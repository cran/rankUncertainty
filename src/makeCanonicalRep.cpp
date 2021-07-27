// [[Rcpp::plugins("cpp11")]]
#include <makeCanonicalRep.h>

#include <Rcpp.h>
#include <map>
#include <set>
#include <types.h>
#include <userInterruptChecker.h>
#include <vector>

void
distinguish(Rcpp::NumericVector& left,
            Rcpp::NumericVector& right)
{
    UserInterruptChecker checker;

    const unsigned int n = left.size();
    std::set<int> vals;
    for (unsigned int i = 0;
         i < n;
         i++)
    {
        checker.check();

        vals.insert(left[i]);
        vals.insert(right[i]);
    }

    for (const auto v : vals)
    {
        unsigned int b = 0;
        unsigned int l = 0;
        unsigned int r = 0;

        for (unsigned int i = 0;
             i < n;
             i++)
        {
            checker.check();

            const bool fl = (left[i] == v);
            const bool fr = (right[i] == v);

            b += (fl && fr);
            l += fl;
            r += fr;
        }

        const unsigned int m = l + r - b;

        std::vector<double> epsilon(m);
        for (unsigned int i = 0;
             i < m;
             i++)
        {
            epsilon[i] = 0.5 * (i + 1)/(m + 1);
        }

        unsigned int j = 0;
        for (unsigned int i = 0;
             i < n && j < m;
             i++)
        {
            checker.check();

            const bool fl = (left[i] == v);
            const bool fr = (right[i] == v);

            left[i]  -= fl * epsilon[j];
            right[i] += fr * epsilon[j];
            j        += (fl || fr);
        }
    }
}

Rcpp::DataFrame
makeCanonicalRep(const std::vector<Interval>& intervals)
{
    const unsigned int n = intervals.size();
    Rcpp::NumericVector left(n, 0);
    Rcpp::NumericVector right(n, 0);

    std::map<int, int> preds;
    std::map<int, int> succs;

    for (const auto& ival : intervals)
    {
        preds[ival.index] = 0;
        succs[ival.index] = 0;
        for (const auto& jval : intervals)
        {
            if (jval.right < ival.left)
            {
                preds[ival.index] += 1;
            }
            else if (ival.right < jval.left)
            {
                succs[ival.index] += 1;
            }
        }
    }

    std::set<int> predVals;
    for (const auto& kv : preds)
    {
        predVals.insert(kv.second);
    }

    std::set<int> succVals;
    for (const auto& kv : succs)
    {
        succVals.insert(kv.second);
    }

    std::map<int, int> newLefts;
    std::map<int, int> newRights;
    for (const auto& ival : intervals)
    {
        const auto idx = ival.index;
        newLefts[idx]  = 0;
        newRights[idx] = 0;

        for (const auto p : predVals)
        {
            if (p < preds[idx])
            {
                newLefts[idx] += 1;
            }
        }

        for (const auto s : succVals)
        {
            if (succs[idx] < s)
            {
                newRights[idx] += 1;
            }
        }
    }

    for (unsigned int i = 0;
         i < n;
         i++)
    {
        left[i]  = newLefts[intervals[i].index];
        right[i] = newRights[intervals[i].index];
    }

    distinguish(left, right);
    return Rcpp::DataFrame::create(Rcpp::Named("left")  = left,
                                   Rcpp::Named("right") = right);

}

Rcpp::DataFrame
makeCanonicalRep(Rcpp::IntegerVector indices,
                 Rcpp::NumericVector left,
                 Rcpp::NumericVector right)
{
    auto intervals = Interval::makeIntervals(indices, left, right, false);
    return makeCanonicalRep(intervals);
}
