// [[Rcpp::plugins("cpp11")]]
#include <getCompatibility.h>

#include <Rcpp.h>
#include <types.h>
#include <unordered_map>
#include <userInterruptChecker.h>
#include <vector>

bool
getCompatibility(const Rcpp::IntegerVector& ranking,
                 const std::vector<Endpoint>& endpoints)
{
    UserInterruptChecker checker;

    const unsigned int n = ranking.size();
    std::vector<bool> deleted(n, false);

    std::unordered_map<int, int> lefts(n);
    for (unsigned int i = 0;
         i < endpoints.size();
         i++)
    {
        checker.check();

        if (endpoints[i].left)
        {
            lefts[endpoints[i].index] = i;
        }
    }

    unsigned int j = 0;
    for (unsigned int i = 0;
         i < n;
         i++)
    {
        checker.check();

        while (j < endpoints.size() &&
               (endpoints[j].left || deleted[endpoints[j].index]))
        {
            j++;
        }

        if (j == endpoints.size())
        {
            break;
        }

        int r = ranking[i] - 1;
        if (endpoints[j] < endpoints[lefts[r]])
        {
            return false;
        }
        else
        {
            deleted[r] = true;
        }
    }

    return true;
}

bool
getCompatibility(Rcpp::IntegerVector ranking,
                 Rcpp::NumericVector left,
                 Rcpp::NumericVector right)
{
    auto endpoints = Endpoint::makeEndpoints(left, right);
    return getCompatibility(ranking, endpoints);
}
