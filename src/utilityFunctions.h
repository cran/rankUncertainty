// [[Rcpp::plugins("cpp11")]]
#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <vector>

namespace
{

template <typename T>
std::vector<int>
copyRange(const std::vector<T>& in,
          unsigned int start,
          unsigned int end)
{
    std::vector<T> out;
    for (unsigned int k = start;
         k < end;
         k++)
    {
        out.push_back(in[k]);
    }
    return out;
}

}

#endif
