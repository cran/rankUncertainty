// [[Rcpp::plugins("cpp11")]]
#ifndef USER_INTERRUPT_CHECKER_H
#define USER_INTERRUPT_CHECKER_H

#include <Rcpp.h>

class UserInterruptChecker
{
public:
    UserInterruptChecker(unsigned int threshold = 1000) :
        m_count(0),
        m_threshold(threshold)
    {
    }

    void check()
    {
        m_count++;
        if (m_threshold == m_count)
        {
            Rcpp::checkUserInterrupt();
            m_count = 0;
        }
    }

private:
    unsigned int m_count;
    const unsigned int m_threshold;
};

#endif
