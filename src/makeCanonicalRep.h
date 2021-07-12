// [[Rcpp::plugins("cpp11")]]
// [[Rcpp::interfaces(r, cpp)]]
#ifndef MAKE_CANONICAL_REP_H
#define MAKE_CANONICAL_REP_H

#include <Rcpp.h>
#include <types.h>
#include <vector>

Rcpp::DataFrame
makeCanonicalRep(const std::vector<Interval>& intervals);

// [[Rcpp::export]]
Rcpp::DataFrame
makeCanonicalRep(Rcpp::IntegerVector indices,
                 Rcpp::NumericVector left,
                 Rcpp::NumericVector right);

#endif
