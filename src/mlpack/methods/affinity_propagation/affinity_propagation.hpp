/**
* @file affinity_propagation.hpp
* @author Sagar B Hathwar (sagarbhathwar@gmail.com)
*
* Interface of Affinity Propagation clustering algorithm.
*
* mlpack is free software; you may redistribute it and/or modify it under the
* terms of the 3-clause BSD license.  You should have received a copy of the
* 3-clause BSD license along with mlpack.  If not, see
* http://www.opensource.org/licenses/BSD-3-Clause for more information.
*/

#include <mlpack/prereqs.hpp>
#include <mlpack/core/metrics/lmetric.hpp>

namespace mlpack{
namespace affinity{
template<typename MatType = arma::mat,
         typename MetricType = metric::Eucledian>
class AffinityPropagation
/* Affinity Propagation clustering algorithm */
{
 public:
  /*
  * Calling Cluster after this is prudent.
  * @param dampingFactor Damping Factor for the algorithm between 0.5 and 1.
  * @param maxIterations Maximum number of iterations.
  * @param convergenceIterations Numbers of iterations with no change after which.
            the algorithm is said to have converged.
  */
  AffinityPropagation(size_t dampingFactor = 0.5,
    size_t maxIterations = 200,
    size_t convergenceIterations = 10);

  /*
  * Does the clustering just by this call
  * @param dataset Input to be clustered.
  * @param labels Labels of each input.
  * @param preferences Preference of each input vector
           Input with higher preference are more likely to be chosen as
           exemplars. Note that this vector will also influence the number
           of clusters produced by the algorithm
  * @param dampingFactor Damping Factor for the algorithm between 0.5 and 1.
  * @param maxIterations Maximum number of iterations.
  * @param convergenceIterations Numbers of iterations with no change after which
            the algorithm is said to have converged.
  */
  AffinityPropagation(const MatType& dataset,
    arma::Row<size_t>& labels,
    const arma::Row<size_t>& preferences = arma::Row<size_t>(),
    size_t dampingFactor = 0.5,
    size_t maxIterations = 200,
    size_t convergenceIterations = 10);

  /*
  * @param dataset Input to be clustered.
  * @param labels Labels of each input.
  * @param preferences Preference of each input vector
           Input with higher preference are more likely to be chosen as
           exemplars. Note that this vector will also influence the number
           of clusters produced by the algorithm
  */
  void Cluster(const MatType& dataset, 
               arma::Row<size_t>& labels,
               const arma::Row<size_t>& preferences = arma::Row<size_t>());

  //!
  const size_t DampingFactor() const { return dampingFactor; }
  //!
  size_t& DampingFactor() { return dampingFactor; }

  //!
  const size_t MaxIterations() const { return maxIterations; }
  //!
  size_t& MaxIterations() { return maxIterations; }

  //!
  const size_t ConvergenceIterations() const { return convergenceIterations; }
  //!
  size_t& ConvergenceIterations() { return convergenceIterations; }

  //! Serialize the AffinityPropagation object.
  template<typename Archive>
  void Serialize(Archive& ar, const unsigned int version)
  {
    using mlpack::data::CreateNVP;

    ar& CreateNVP(dampingFactor, "dampingFactor");
    ar& CreateNVP(maxIterations, "maxIterations");
    ar& CreateNVP(convergenceIterations, "convergenceIterations");
  }

 private:

  size_t dampingFactor;

  size_t maxIterations;

  size_t convergenceIterations;

  void PairwiseDistance(const MatType& dataset, MatType& affinityMatrix);
};

} // namespace affinity
} // namespace mlpack
