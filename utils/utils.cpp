#include <iostream>
#include <vector>
#include <iomanip>
#include "utils.hpp"


using namespace std;

template <typename T>
void printElement(T t)
{
    cout << left << setw(10) << fixed << setprecision(2) << t;
}


template<typename T> 
void printElements(vector<T> elements)
{
    for( auto element : elements )
    {
        printElement(element);
    }
}
template void printElements(vector<double> elements);
template void printElements(vector<string> elements);



bool is_number(const string &s)
{
    char *end;
    strtod(s.c_str(), &end);
    return *end == 0;
}

