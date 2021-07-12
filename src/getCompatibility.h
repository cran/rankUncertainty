// [[Rcpp::plugins("cpp11")]]
// [[Rcpp::interfaces(r, cpp)]]
#ifndef GET_COMPATIBILITY_H
#define GET_COMPATIBILITY_H

#include <Rcpp.h>
#include <types.h>
#include <vector>

bool
getCompatibility(const Rcpp::IntegerVector& ranking,
                 const std::vector<Endpoint>& endpoints);

// [[Rcpp::export]]
bool
getCompatibility(Rcpp::IntegerVector ranking,
                 Rcpp::NumericVector left,
                 Rcpp::NumericVector right);

#endif
