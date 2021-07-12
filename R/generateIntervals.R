#' Generate random intervals
#'
#' Generate a set of intervals with endpoints uniformly distributed between 0
#' and 1.
#'
#'
#' @param n number of intervals to generate
#' @param sort if TRUE, sort the output intervals by their left endpoints
#' @param f transformation to apply to each endpoint
#'
#' @return Data frame with columns 'left' and 'right'.  It is guaranteed that
#' every value in 'left' is no greater than the corresponding value in 'right'.
#' @export
#'
#' @examples
#' generateIntervals(10)
#' generateIntervals(20, f = qnorm)
#' generateIntervals(5, TRUE, f = function(x) { x + 1 })
#'
#' @importFrom magrittr %>%
#' @importFrom stats runif
generateIntervals <- function(n, sort = FALSE, f = NULL)
{
  if (!checkNumericClass(n))
  {
    stop('n must be numeric')
  }

  if (is.null(f))
  {
    f <- function(x) { x }
  }

  x <- runif(n) %>% sapply(f)
  y <- runif(n) %>% sapply(f)
  intervals <- data.frame(left = pmin(x, y), right = pmax(x, y))
  if (sort)
  {
    idx <- with(intervals, order(left))
    intervals <- intervals[idx, ]
    row.names(intervals) <- 1:n
  }
  intervals
}
