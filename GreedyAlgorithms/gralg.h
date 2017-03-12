#ifndef GRALG_H
#define GRALG_H

#include <vector>
#include <array>
#include <cstdlib>

void first_case(std::vector<std::array<int, 2>> &v_pair, std::vector<int> &v_out);

double second_case(int W, std::vector<std::array<double, 2>> &v_pair);

void third_case(int n, std::vector<int> &v_out);

size_t numb_requests(std::vector<std::array<int, 2>> &v_pair);

#endif // GRALG_H
