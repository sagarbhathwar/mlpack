/**
* @file affinity_propagation.hpp
* @author Sagar B Hathwar (sagarbhathwar@gmail.com)
*
* Implementation of Affinity Propagation clustering algorithm.
*
* mlpack is free software; you may redistribute it and/or modify it under the
* terms of the 3-clause BSD license.  You should have received a copy of the
* 3-clause BSD license along with mlpack.  If not, see
* http://www.opensource.org/licenses/BSD-3-Clause for more information.
*/
#include <numeric>
#include "affinity_propagation.hpp"

namespace mlpack {
namespace affinity {

template<typename MatType,  typename MetricType>
AffinityPropagation<MatType, MetricType>::AffinityPropagation(
  size_t dampingFactor,
  size_t maxIterations,
  size_t convergenceIterations) :
  dampingFactor(damping Factor),
  maxIterations(maxIterations),
  convergenceIterations(convergenceIterations)
{
  // Nothing to do
}

template<typename MatType, typename MetricType>
AffinityPropagation<MatType, MetricType>::AffinityPropagation(
    const MatType& dataset,
    arma::Row<size_t>& labels,
    const arma::Row<size_t>& preferences,
    size_t dampingFactor,
    size_t maxIterations,
    size_t convergenceIterations) :
    dampingFactor(damping Factor),
    maxIterations(maxIterations),
    convergenceIterations(convergenceIterations)
{
  Cluster(dataset, labels, preferences);
}

template<typename MatType, typename MetricType>
void AffinityPropagation<MatType, MetricType>::
Cluster(const MatType& dataset,
        arma::Row<size_t>& labels,
        const arma::Row<size_t>& preferences)
{
  size_t numInputs = dataset.n_cols;
  arma::mat affinityMatrix(numInputs, numInputs);
  PairwiseDistance(dataset, affinityMatrix);
  if (preferences.n_elem == 0)
  {
    affinityMatrix.diag = arma::median(dataset);
  }
  else
  {
    affinityMatrix.diag = preferences;
  }

  arma::mat A(numInputs, numInputs);

  arma::mat B(numInputs, numInputs);

  arma::mat tmp(numInputs, numInputs);

  arma::mat e(convergenceIterations, numInputs);

  std::vector<int> range(numInputs);
  std::iota(range.begin(), range.end(), 0);
  arma::Row<size_t> e(range);

  for (size_t iter = 0; iter < maxIterations; ++i)
  {
    tmp = A + affinityMatrix;

  }
}

template<typename MatType, typename MetricType>
void AffinityPropagation<MatType, MetricType>::PairwiseDistance(
    const MatType& dataset, 
    MatType& affinityMatrix)
{
  MetricType metric;
  size_t numInputs = dataset.n_cols;
  for (size_t i = 0; i < numInputs; ++i)
    for (size_t j = 0; j < numInputs; ++j)
      affinityMatrix(i, j) = i == j ? 0 : metric.Evaluate(dataset.col(i), dataset.col(j));
}


}
}