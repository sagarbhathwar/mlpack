/**
* @file kmeans.hpp
* @author Sagar B Hathwar (sagarbhathwar@gmail.com)
*
* Implementation of Affinity Propagation algorithm.
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
  /* Implementation of AP
  */
template<typename MatType = arma::mat,
         typename MeticType = metric::Eucledian>
class AffinityPropagation
{
  public:
    /*
    * One of the constructors
    */
    AffinityPropagation(int dampingFactor = 0.5,
      int maxIterations = 200,
      bool copy = true);
};
} // namespace affinity
} // namespace mlpack
