#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

using namespace std;

template <typename T>
void printElement(T t);

template<typename T>
void printElements(vector<T> elements);

bool is_number(const string &s);

#endif
