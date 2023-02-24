#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

using namespace std;

template <typename T>
void print_element(T& t, int precision);

template<typename T>
void print_elements(const vector<T>& elements, int precision);

bool is_number(const string &s);

#endif
