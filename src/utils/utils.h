#include <functional>
#include <vector>


#ifndef H_UTILS
#define H_UTILS

int modulo_period(int m, int left, int right);

int modulo_solver(int m, int function_value, std::function<int(int)> func);

std::vector<int> get_coset(std::vector<std::vector<int>> &pairs, int start_index);


#endif // !H_UTILS