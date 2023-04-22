#include <functional>
#include <vector>


#ifndef H_UTILS
#define H_UTILS

int modulo_period(int m, int left, int right);

int modulo_solver(int m, int function_value, std::function<int(int)> func);

std::vector<std::vector<int>> get_coset(std::vector<std::vector<int>> &pairs, int n, int t);

int modulo_period_gcd(int m, int i);


#endif // !H_UTILS