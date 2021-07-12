#' Plot intervals
#'
#' Generates a plot of a set of intervals.  This is intended for simple
#' visualizations and does not offer any degree of customization.
#'
#' @param intervals data frame (see [rankUncertainty::generateIntervals] for
#' the required format)
#'
#' @return ggplot object
#' @export
#'
#' @examples
#' intervals <- generateIntervals(10)
#' p <- plotIntervals(intervals)
#' p
plotIntervals <- function(intervals)
{
  errorCheck(intervals, FALSE)

  intervals[, 'idx'] <- 1:nrow(intervals)
  idx <- intervals[, 'idx']
  left <- intervals[, 'left']
  right <- intervals[, 'right']

  p <- ggplot2::ggplot()
  p <- p + ggplot2::theme(panel.border = ggplot2::element_blank())
  p <- p + ggplot2::theme(panel.grid.major = ggplot2::element_blank(),
                          panel.grid.minor = ggplot2::element_blank())
  p <- p + ggplot2::geom_segment(data = intervals, ggplot2::aes(x = left,
                                 y = idx, xend = right, yend = idx))
  p <- p + ggplot2::theme(axis.text.x = ggplot2::element_blank(),
                          axis.ticks.x = ggplot2::element_blank())
  p <- p + ggplot2::theme(axis.text.y = ggplot2::element_blank(),
                          axis.ticks.y = ggplot2::element_blank())
  p <- p + ggplot2::theme(axis.title.x = ggplot2::element_blank(),
                          axis.title.y = ggplot2::element_blank())
  p
}
