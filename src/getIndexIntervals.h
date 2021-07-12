// [[Rcpp::plugins("cpp11")]]
// [[Rcpp::interfaces(r, cpp)]]
#ifndef GET_INDEX_INTERVALS_H
#define GET_INDEX_INTERVALS_H

#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::DataFrame
getIndexIntervals(Rcpp::NumericVector left,
                  Rcpp::NumericVector right);

#endif
