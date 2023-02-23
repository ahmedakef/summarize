#include <set>
#include <vector>
#include "summarizer.hpp"
#include "../utils/utils.hpp"

using namespace std;

Summarizer::Summarizer()
{
    sum = 0;
    numbers = set<double>();
}

void Summarizer::add_number(double number)
{
    sum += number;
    numbers.insert(number);
}

void Summarizer::print_summery(int precision)
{
    double count = numbers.size();
    double average = sum / count;

    set<double>::iterator it = numbers.begin();
    // minimum is the first item in the set
    double min = *it;
    // median exist at the center of the set: 0+50 = 50;
    std::advance(it, 0.50 * count);
    double median = *it;
    // p95 exists after 45% of the center: 0+50+45 = 95
    std::advance(it, 0.45 * count);
    double p95 = *it;
    // p99 exists after 4% of the p95: 0+50+45+4 = 99
    std::advance(it, 0.04 * count);
    double p99 = *it;
    // maximum exists at the end of the set: 0+50+45+4+1 = 100
    std::advance(it, 0.01 * count);
    double maximum = *it;
    printElements(vector<double>{average, min, median, p95, p99, maximum}, precision);
}
