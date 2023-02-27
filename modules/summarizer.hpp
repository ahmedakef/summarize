#ifndef Summarizer_H
#define Summarizer_H
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/count.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/min.hpp>
#include <boost/accumulators/statistics/max.hpp>
#include <boost/accumulators/statistics/extended_p_square.hpp>

using namespace boost::accumulators;

typedef accumulator_set<double, stats<tag::count, tag::mean, tag::min, tag::max, tag::extended_p_square>> accumulator_t;

class Summarizer
{
  accumulator_t acc;

public:
  Summarizer();
  void add_number(double number);
  void print_summary(int precision);
};

#endif