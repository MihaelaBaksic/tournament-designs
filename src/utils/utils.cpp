
#include "utils.h"
#include <iostream>


int modulo_period(int m, std::function<int(int)> func) // maybe can be implemented differently
{
    int i=1;
    int last_elem = ((func(0) % m) + m ) % m;
    while ( (func(i) % m + m ) % m != last_elem)
        i += 1;

    return i;  
}

int modulo_solver(int m, int function_value, std::function<int(int)> func)
{
    int period = modulo_period(m, func);
    int function_value_mod = (function_value % m + m) % m;
    for(int i=0; i < period; i++)
    {
        int function_result_mod = (func(i) % m + m ) % m;
        if( function_value_mod == function_result_mod)
            return i;
    }

    return -1; // no solution
}



std::vector<int> get_coset(std::vector<std::vector<int>> &pairs, int start_index) // try better than O(n^2)
{
    std::vector<int> coset_indices{start_index};
    int first_elem = pairs[start_index][0];
    int find_elem = pairs[start_index][1];
    while(find_elem != first_elem){
        // find find_elem among first members of pairs, add index in coset_indices
        for(int i=0; i<pairs.size(); i++)
        {
            if(pairs[i][0] == find_elem)
            {
                coset_indices.push_back(i);
                find_elem = pairs[i][1];
                break;
            }
        }
    }
    /* std::cout << "AAAA" << std::endl;
    for(auto idx: coset_indices)
    {
        std::cout << pairs[idx][0] << " " << pairs[idx][1] << ";";
    }
    std::cout << std::endl; */
    
    return coset_indices;
}