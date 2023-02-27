#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

template <typename T>
void print_element(T &t, int precision);

template <typename T>
void print_elements(const std::vector<T> &elements, int precision);

bool is_number(const std::string &s);

#endif
