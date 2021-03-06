% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/generateIntervals.R
\name{generateIntervals}
\alias{generateIntervals}
\title{Generate random intervals}
\usage{
generateIntervals(n, sort = FALSE, f = NULL)
}
\arguments{
\item{n}{number of intervals to generate}

\item{sort}{if TRUE, sort the output intervals by their left endpoints}

\item{f}{transformation to apply to each endpoint}
}
\value{
Data frame with columns 'left' and 'right'.  It is guaranteed that
every value in 'left' is no greater than the corresponding value in 'right'.
}
\description{
Generate a set of intervals with endpoints uniformly distributed between 0
and 1.
}
\examples{
generateIntervals(10)
generateIntervals(20, f = qnorm)
generateIntervals(5, TRUE, f = function(x) { x + 1 })

}
