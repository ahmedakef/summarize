#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

using namespace std;

template <typename T>
void printElement(T t, int precision);

template<typename T>
void printElements(vector<T> elements, int precision);

bool is_number(const string &s);

#endif
