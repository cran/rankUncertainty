// [[Rcpp::plugins("cpp11")]]
#include <countPrincipalDownSets.h>

#include <Rcpp.h>
#include <types.h>
#include <userInterruptChecker.h>
#include <vector>

Rcpp::IntegerVector
countPrincipalDownSets(const std::vector<Endpoint>& endpoints)
{
    UserInterruptChecker checker;

    const unsigned int n = endpoints.size() / 2;
    Rcpp::IntegerVector c(n);

    int r = 1;
    for (const Endpoint& q : endpoints)
    {
        checker.check();

        if (q.left)
        {
            c[q.index] = r;
        }
        else
        {
            r = r + 1;
        }
    }

    return c;
}

Rcpp::IntegerVector
countPrincipalDownSets(Rcpp::NumericVector left,
                       Rcpp::NumericVector right)
{
    auto endpoints = Endpoint::makeEndpoints(left, right);
    return countPrincipalDownSets(endpoints);
}
