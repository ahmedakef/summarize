#include <iostream>
#include <vector>
#include <iomanip>
#include "utils.hpp"

using namespace std;

template <typename T>
void print_element(T &t, int precision)
{
    cout << left << setw(10) << fixed << setprecision(precision) << t;
}

template <typename T>
void print_elements(const vector<T> &elements, int precision)
{
    for (auto &element : elements)
    {
        print_element(element, precision);
    }
}
template void print_elements(const vector<double> &elements, int precision);
template void print_elements(const vector<string> &elements, int precision);

tuple<double, bool> is_number(const string &s)
{
    char *end;
    double r = strtod(s.c_str(), &end);
    return {r, *end == 0};
}
