
#include "utils.h"
#include <iostream>
#include <set>


int modulo_period(int m, int left, int right) // maybe can be implemented differently
{
    int cnt = 0;

    while(left != right)
    {
        left = ((left + right) % m + m ) % m;
        cnt++;
    }
    return cnt;
}

int modulo_solver(int m, int function_value, std::function<int(int)> func)
{
    int function_value_mod = (function_value % m + m) % m;
    for(int i=0; i < m; i++)
    {
        int function_result_mod = (func(i) % m + m ) % m;
        if( function_value_mod == function_result_mod)
            return i;
    }

    return -1; // no solution
}



std::vector<std::vector<int>> get_coset(std::vector<std::vector<int>> &pairs, int n, int t) // try better than O(n^2) -- mozda t = modulo / nzd(modulo, i)
{

    int start_index = 0;
    std::set<int> idx_included{0};

    std::vector<std::vector<int>> cosets;

    while(idx_included.size() < n)
    {
        std::vector<int> coset_indices{start_index};
        idx_included.insert(start_index);
        
        int first_elem = pairs[start_index][0];
        int find_elem = pairs[start_index][1];

        while(find_elem != first_elem)
        {
            // find find_elem among first members of pairs, add index in coset_indices
            for(int i=0; i< n; i++)
            {
                if(pairs[i][0] == find_elem) // vidi sta je ovo i sredi
                {
                    coset_indices.push_back(i);
                    idx_included.insert(i);
                    find_elem = pairs[i][1];
                    break;
                }
            }
        }

        cosets.push_back(coset_indices);
        for(int i=0; i<n; i++)
        {
            if(idx_included.find(i) == idx_included.end())
            {
                start_index = i;
                break;
            }
        }
    }
    
    /* 
    for( auto c: cosets)
    {
        for(auto idx: c)
        {
            std::cout << pairs[idx][0] << " " << pairs[idx][1] << ";";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl << std::endl;
    */
    
    return cosets;
}