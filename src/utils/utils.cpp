
#include "utils.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstring>
#include<bits/stdc++.h>


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

int modulo_period_gcd(int m, int i){
    return m / std::__gcd(m, i);
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



std::vector<std::vector<int>> get_coset(std::vector<std::vector<int>> &pairs, int n, int t) 
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
                if(pairs[i][0] == find_elem)
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
    
    return cosets;
}


int int_pow(int x, unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;
  
  int tmp = int_pow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}


 
std::vector<int> get_prime_powers(int q)
{
    int s[q+1];
    std::vector<bool> prime(q+1, false);

    std::vector<int> prime_powers;

    for (int i=2; i<=q; i+=2)
        s[i] = 2;
 
    for (int i=3; i<=q; i+=2)
    {
        if (prime[i] == false)
        {
            s[i] = i;
 
            for (int j=i; j*i<=q; j+=2)
            {
                if (prime[i*j] == false)
                {
                    prime[i*j] = true;

                    s[i*j] = i;
                }
            }
        }
    }
  
    int curr = s[q];
    int cnt = 1; 
 
    while (q > 1)
    {
        q /= s[q];
 
        if (curr == s[q])
        {
            cnt++;
            continue;
        }
 
        prime_powers.push_back(int_pow(curr, cnt));
 
        curr = s[q];
        cnt = 1;
    }

    return prime_powers;
}