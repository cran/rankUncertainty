// [[Rcpp::plugins("cpp11")]]
#include <getPartitionInfo.h>

#include <limits>
#include <Rcpp.h>
#include <types.h>
#include <userInterruptChecker.h>
#include <utilityFunctions.h>
#include <vector>

std::vector<std::vector<int>>
getPartitionInfo(const Rcpp::IntegerVector& indices,
                 const std::vector<Interval>& intervals)
{
    UserInterruptChecker checker;

    const unsigned int n = intervals.size();
    std::vector<int> internalIndices(n);
    for (unsigned int i = 0;
         i < n;
         i++)
    {
        checker.check();

        internalIndices[i] = intervals[i].index;
    }

    std::vector<std::vector<int>> partitions;
    unsigned int start = 0;
    double r = std::numeric_limits<double>::lowest();
    for (unsigned int i = 0;
         i < n;
         i++)
    {
        checker.check();

        if (r < intervals[i].right)
        {
            r = intervals[i].right;
        }
        if (i < n - 1 && r < intervals[i + 1].left)
        {
            partitions.push_back(copyRange(internalIndices, start, i + 1));
            start = i + 1;
        }
    }
    partitions.push_back(copyRange(internalIndices, start, n));

    return partitions;
}

Rcpp::List
getPartitionInfo(Rcpp::IntegerVector indices,
                 Rcpp::NumericVector idxLeft,
                 Rcpp::NumericVector idxRight)
{
    auto intervals = Interval::makeIntervals(indices, idxLeft, idxRight);

    Rcpp::List output;
    output["partitions"] = getPartitionInfo(indices, intervals);
    return output;
}
