#include <vector>
#include <array>
#include <boost/array.hpp>
#include "summarizer.hpp"
#include "../utils/utils.hpp"


using namespace boost::accumulators;
static constexpr std::array<double, 2> probs{0.95, 0.99};

Summarizer::Summarizer() : acc(tag::extended_p_square::probabilities = probs) {}

void Summarizer::add_number(double number)
{
    acc(number);
}

void Summarizer::print_summary(int precision)
{
    double count_v = count(acc);
    if (count_v == 0.0){
        print_elements(std::vector<double>{0, 0, 0, 0, 0, 0}, precision);
        return;
    }
    double mean_v = mean(acc);
    double min_v = (min)(acc);
    double max_v = (max)(acc);
    double p95_v = extended_p_square(acc)[0];
    double p99_v = extended_p_square(acc)[1];

    print_elements(std::vector<double>{count_v, mean_v, min_v, max_v, p95_v, p99_v}, precision);
}
