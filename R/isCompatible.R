#' Test whether a ranking is compatible with a set of intervals
#'
#' A ranking is compatible with a set of intervals if we can pick a point from
#' each interval such that the ranking of those points is the ranking in
#' question.
#'
#' See section 4.1 of Rising (2021).
#'
#' @param intervals data frame (see [rankUncertainty::generateIntervals] for
#' the required format)
#' @param ranking permutation of `1:nrow(intervals)`
#'
#' @return TRUE if the ranking is compatible and FALSE otherwise
#' @export
#'
#' @references
#' Rising, Justin (2021).  _Uncertainty in Ranking_.  arXiv:2107.03459.
#'
#' @examples
#' left <- 0:2 * 0.5 + 1
#' right <- left + 0.75
#' intervals <- data.frame(left = left, right = right)
#' isCompatible(intervals, 1:3)
#' isCompatible(intervals, c(3, 2, 1))
isCompatible <- function(intervals, ranking)
{
  errorCheck(intervals)
  checkNumericClass(ranking)
  if (length(ranking) != nrow(intervals))
  {
    stop('ranking is not of correct length')
  }
  if (any(sort(ranking) != 1:nrow(intervals)))
  {
    stop('ranking must be a valid ranking')
  }

  getCompatibility(ranking, intervals[, 'left'], intervals[, 'right'])
}
