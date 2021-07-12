// [[Rcpp::plugins("cpp11")]]
// [[Rcpp::interfaces(r, cpp)]]
#ifndef COUNT_PRINCIPAL_DOWN_SETS_H
#define COUNT_PRINCIPAL_DOWN_SETS_H

#include <Rcpp.h>
#include <types.h>
#include <vector>

Rcpp::IntegerVector
countPrincipalDownSets(const std::vector<Endpoint>& endpoints);

// [[Rcpp::export]]
Rcpp::IntegerVector
countPrincipalDownSets(Rcpp::NumericVector left,
                       Rcpp::NumericVector right);

#endif
