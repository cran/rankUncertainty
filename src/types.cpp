// [[Rcpp::plugins("cpp11")]]
#include <types.h>

#include <limits>
#include <Rcpp.h>
#include <ostream>
#include <sstream>

std::string
Endpoint::toString() const
{
    std::stringstream ss;
    ss << "("  << index << ", " << left
       << ", " << value << ")";
    return ss.str();
}

std::vector<Endpoint>
Endpoint::makeEndpoints(const Rcpp::NumericVector& left,
                        const Rcpp::NumericVector& right)
{
    const unsigned int n = left.size();

    std::vector<Endpoint> endpoints(2 * n);
    for (unsigned int i = 0;
         i < n;
         i++)
    {
        endpoints[i].index = i;
        endpoints[i].left  = true;
        endpoints[i].value = left[i];

        int j              = i + n;
        endpoints[j].index = i;
        endpoints[j].left  = false;
        endpoints[j].value = right[i];
    }

    const double epsilon = std::numeric_limits<double>::epsilon();
    std::sort(endpoints.begin(), endpoints.end());
    for (unsigned int i = 0;
         i < 2 * n - 1;
         i++)
    {
        const double e1 = endpoints[i].value;
        const double e2 = endpoints[i + 1].value;
        const double delta = e2 - e1;
        if (delta < epsilon)
        {
            std::stringstream ss;
            ss << "Successive endpoints differ by less than machine epsilon";
            Rcpp::stop(ss.str());
        }
    }

    return endpoints;
}

Endpoint
Endpoint::negate(const Endpoint& in)
{
    Endpoint out;
    out.index = in.index;
    out.left  = !in.left;
    out.value = -in.value;
    return out;
}

bool
operator<(const Endpoint& left,
          const Endpoint& right)
{
    return left.value < right.value;
}

std::ostream&
operator<<(std::ostream& os,
           const Endpoint& e)
{
    os << e.toString();
    return os;
}

std::string
Interval::toString() const
{
    std::stringstream ss;
    ss << "("  << index << ", " << left
       << ", " << right << ")";
    return ss.str();
}

std::vector<Interval>
Interval::makeIntervals(const Rcpp::IntegerVector& indices,
                        const Rcpp::NumericVector& left,
                        const Rcpp::NumericVector& right,
                        bool sorted)
{
    const unsigned int n = indices.size();
    std::vector<Interval> intervals(n);
    for (unsigned int i = 0;
         i < n;
         i++)
    {
        intervals[i].index = indices[i];
        intervals[i].left  = left[i];
        intervals[i].right = right[i];
    }
    if (sorted)
    {
        std::sort(intervals.begin(), intervals.end());
    }
    return intervals;
}

bool
operator<(const Interval& left,
          const Interval& right)
{
    return left.left < right.left;
}

std::ostream&
operator<<(std::ostream& os,
           const Interval& i)
{
    os << i.toString();
    return os;
}
