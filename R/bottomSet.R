#' Compute the k-bottom set for a set of intervals
#'
#' Suppose that we select one point from each of a set of n intervals and rank
#' them.  The k-bottom set is the set of intervals whose points can have a rank
#' of n + 1 - k or higher.
#'
#' See section 4.2 of Rising (2021).
#'
#' @param intervals data frame (see [rankUncertainty::generateIntervals] for
#' the required format)
#' @param k cutoff for inclusion
#'
#' @return Indices of intervals in the k-bottom set.
#' @export
#'
#' @references
#' Rising, Justin (2021).  _Uncertainty in Ranking_.  arXiv:2107.03459.
#'
#' @examples
#' intervals <- data.frame(left = 1:4, right = 1:4 + 0.5)
#' bottomSet(intervals, 2)
bottomSet <- function(intervals, k)
{
  errorCheck(intervals)
  if (!checkNumericClass(k))
  {
    stop('k must be numeric')
  }

  counts <- countPrincipalDownSets(-intervals[, 'right'], -intervals[, 'left'])
  which(counts <= k)
}
