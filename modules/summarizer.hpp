#ifndef Summarizer_H
#define Summarizer_H

#include <set>

class Summarizer
{
  double sum;
  std::set<double> numbers;

public:
  Summarizer();
  void add_number(double number);
  void print_summery(int precision);
};

#endif