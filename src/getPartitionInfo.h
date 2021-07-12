// [[Rcpp::plugins("cpp11")]]
// [[Rcpp::interfaces(r, cpp)]]
#ifndef GET_PARTITION_INFO_H
#define GET_PARTITION_INFO_H

#include <Rcpp.h>
#include <types.h>
#include <vector>

std::vector<std::vector<int>>
getPartitionInfo(const Rcpp::IntegerVector& indices,
                 const std::vector<Interval>& intervals);

// [[Rcpp::export]]
Rcpp::List
getPartitionInfo(Rcpp::IntegerVector indices,
                 Rcpp::NumericVector idxLeft,
                 Rcpp::NumericVector idxRight);

#endif
