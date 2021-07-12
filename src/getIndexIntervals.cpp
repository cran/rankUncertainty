// [[Rcpp::plugins("cpp11")]]
#include <algorithm>
#include <countPrincipalDownSets.h>
#include <Rcpp.h>
#include <types.h>

Rcpp::DataFrame
getIndexIntervals(Rcpp::NumericVector left,
                  Rcpp::NumericVector right)
{
    auto endpoints = Endpoint::makeEndpoints(left, right);

    auto bottom = countPrincipalDownSets(endpoints);
    std::reverse(endpoints.begin(), endpoints.end());
    std::transform(endpoints.begin(), endpoints.end(), endpoints.begin(),
                   Endpoint::negate);
    auto top = countPrincipalDownSets(endpoints);

    const unsigned int n = left.size();
    return Rcpp::DataFrame::create(Rcpp::Named("left")  = bottom,
                                   Rcpp::Named("right") = n + 1 - top);
}
