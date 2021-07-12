#' Compute a canonical representation of an interval order
#'
#' This functions generates a set of intervals with distinct endpoints such that
#' running any of the functions in this package on the return value gives the
#' same answer as running those functions on the input.
#'
#' See section 3.1 of Rising (2021).
#'
#' @param intervals data frame (see [rankUncertainty::generateIntervals] for
#' the required format)
#'
#' @return a data frame in the same format as the input
#' @export
#'
#' @references
#' Rising, Justin (2021).  _Uncertainty in Ranking_.  arXiv:2107.03459.
#'
#' @examples
#' left <- c(0, 0, 0, 1, 2)
#' right <- c(0, 1, 2, 2, 2)
#' intervals <- data.frame(left = left, right = right)
#' toMatrix(intervals)
#' toMatrix(canonicalize(intervals))
canonicalize <- function(intervals)
{
  errorCheck(intervals, FALSE)

  makeCanonicalRep(1:nrow(intervals), intervals[, 'left'], intervals[, 'right'])
}
