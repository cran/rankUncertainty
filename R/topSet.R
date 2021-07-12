#' Compute the k-top set for a set of intervals
#'
#' Suppose that we select one point from each of a set of n intervals and rank
#' them.  The k-top set is the set of intervals whose points can have a rank of
#' k or lower.
#'
#' See section 4.2 of Rising (2021).
#'
#' @param intervals data frame (see [rankUncertainty::generateIntervals] for
#' the required format)
#' @param k cutoff for inclusion
#'
#' @return Indices of intervals in the k-top set.
#' @export
#'
#' @references
#' Rising, Justin (2021).  _Uncertainty in Ranking_.  arXiv:2107.03459.
#'
#' @examples
#' intervals <- data.frame(left = 1:4, right = 1:4 + 0.5)
#' topSet(intervals, 2)
topSet <- function(intervals, k)
{
  errorCheck(intervals)
  if (!checkNumericClass(k))
  {
    stop('k must be numeric')
  }

  counts <- countPrincipalDownSets(intervals[, 'left'], intervals[, 'right'])
  which(counts <= k)
}
