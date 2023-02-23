#include <iostream>
#include <vector>
#include <iomanip>
#include "utils.hpp"


using namespace std;

template <typename T>
void printElement(T t, int precision)
{
    cout << left << setw(10) << fixed << setprecision(precision) << t;
}


template<typename T> 
void printElements(vector<T> elements, int precision)
{
    for( auto element : elements )
    {
        printElement(element, precision);
    }
}
template void printElements(vector<double> elements, int precision);
template void printElements(vector<string> elements, int precision);



bool is_number(const string &s)
{
    char *end;
    strtod(s.c_str(), &end);
    return *end == 0;
}

