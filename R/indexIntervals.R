#' Generate index intervals for a set of intervals
#'
#' If we pick one point from each of a set of intervals, the index intervals
#' describe the possible ranks of points in each interval.  If this function is
#' given simultaneous 100(1 - alpha)% confidence intervals for a distinct set
#' of parameters, the index intervals are simultaneous 100(1 - alpha)%
#' confidence intervals for the true ranks.
#'
#' See section 5.2 of Rising (2021).
#'
#' @param intervals data frame (see [rankUncertainty::generateIntervals] for
#' the required format)
#'
#' @return data frame (see [rankUncertainty::generateIntervals] for
#' the format)
#' @export
#'
#' @references
#' Rising, Justin (2021).  _Uncertainty in Ranking_.  arXiv:2107.03459.
#'
#' @examples
#' left <- 0:2 * 0.5 + 1
#' right <- left + 0.75
#' intervals <- data.frame(left = left, right = right)
#' indexIntervals(intervals)
indexIntervals <- function(intervals)
{
  errorCheck(intervals)

  getIndexIntervals(intervals[, 'left'], intervals[, 'right'])
}
