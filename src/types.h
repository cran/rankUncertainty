// [[Rcpp::plugins("cpp11")]]
#ifndef TYPES_H
#define TYPES_H

#include <ostream>
#include <Rcpp.h>
#include <string>
#include <vector>

struct Endpoint
{
public:
    int    index;
    bool   left;
    double value;

    std::string
    toString() const;
    
    static std::vector<Endpoint>
    makeEndpoints(const Rcpp::NumericVector& left,
                  const Rcpp::NumericVector& right);
                  
    static Endpoint
    negate(const Endpoint& in);
};

bool
operator<(const Endpoint& left,
          const Endpoint& right);

std::ostream&
operator<<(std::ostream& os,
           const Endpoint& e);

struct Interval
{
public:
    int    index;
    double left;
    double right;
    
    std::string
    toString() const;
    
    static std::vector<Interval>
    makeIntervals(const Rcpp::IntegerVector& indices,
                  const Rcpp::NumericVector& left,
                  const Rcpp::NumericVector& right,
                  bool sorted = true);
};

bool
operator<(const Interval& left,
          const Interval& right);

std::ostream&
operator<<(std::ostream& os,
           const Interval& i);

#endif
