#include "MOLS.h"
#include <list>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <set>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/range/adaptor/transformed.hpp>


design::PairMOLS::PairMOLS(int n, design::LatinSquare* ls1, design::LatinSquare* ls2)
{
    this->ls1 = ls1;
    this->ls2 = ls2;

    this->join = this->create_join();

    int max_value_1 = *std::max_element(this->ls1->latin_square[0].begin(), this->ls1->latin_square[0].end());
    int max_value_2 = *std::max_element(this->ls2->latin_square[0].begin(), this->ls2->latin_square[0].end());
    this->max_element_value = max_value_1 > max_value_2 ? max_value_1 : max_value_2;
}

design::PairMOLS::PairMOLS(int range_1_lower, int range_1_upper, int range_2_lower, int range_2_upper)
{
    int n1 = range_1_upper - range_1_lower;
    int n2 = range_2_upper - range_2_lower;

    assert(n1 > 0 && n2 > 0 && n1==n2);

    this->ls1 = new LatinSquare(range_1_lower, range_1_upper, false);
    this->ls2 = new LatinSquare(range_2_lower, range_2_upper, false);

    this->join = this->create_join();
    this->max_element_value = range_2_upper > range_1_upper ? range_2_upper : range_1_upper;
}


design::PairMOLS::PairMOLS(int n)
{
    //assert(n > 2 && n != 6);

    // deconstruct n to prime powers (this is an ordered list)
    std::vector<int> prime_powers = get_prime_powers(n);

    design::LatinSquare ls1; 
    design::LatinSquare ls2; 

    if(prime_powers[0] == 2)
    {
        throw std::invalid_argument( "can't deal with prime power 2" );
    }
    else{
        ls1 = LatinSquare(prime_powers[0], 1);
        ls2 = LatinSquare(prime_powers[0], 2);
    }
    
    for(int i=1; i<prime_powers.size(); i++)
    {
        design::LatinSquare ls_other_1(prime_powers[i], 1);
        design::LatinSquare ls_other_2(prime_powers[i], 2);

        auto product_1 = PairMOLS::kronecker_product(ls1, ls_other_1);
        auto product_2 = PairMOLS::kronecker_product(ls2, ls_other_2);

        ls1 = LatinSquare(product_1.size(), product_1);
        ls2 = LatinSquare(product_2.size(), product_2);
    }

    this->ls1 = new LatinSquare(ls1.n, ls1.latin_square);
    this->ls2 = new LatinSquare(ls2.n, ls2.latin_square);
        
    this->join = create_join();
}

design::PairMOLS::~PairMOLS()
{
    free(this->ls1);
    free(this->ls2);
}


std::vector<std::vector<int>> design::PairMOLS::kronecker_product(design::LatinSquare &A, design::LatinSquare &B)
{
    int m = A.n;
    int n = B.n;

    // initialise latin square array with the value n
    std::vector<std::vector<int>> ls = std::vector<std::vector<int>>(m*n, std::vector<int>(n*m, n));
    
    // set a_ij values
    for(int i=0; i<m*n; i++)
    {
        for(int j=0; j<m*n; j++)
        {
            int a_i = i / n;
            int a_j = j / n;

            ls[i][j] *= A.latin_square[a_i][a_j];

            int b_i = i % n;
            int b_j = j % n;

            ls[i][j] += B.latin_square[b_i][b_j];
        }
    }
    
    return ls;
}



std::vector<std::vector<std::vector<int>>> design::PairMOLS::create_join()
{
    int n = this->ls1->n;
    auto join = std::vector<std::vector<std::vector<int>>>(n, std::vector<std::vector<int>>(n, std::vector<int>(2,0)));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            join[i][j][0] = this->ls1->latin_square[i][j];
            join[i][j][1] = this->ls2->latin_square[i][j];
        }
    }

    return join;
}

std::vector<std::vector<std::vector<int>>> design::PairMOLS::get_join()
{
    return this->join;
}

std::string design::PairMOLS::to_string(std::string delimiter)
{
    std::string ls1 = this->ls1->to_string(delimiter);
    std::string ls2 = this->ls2->to_string(delimiter);

    return ls1 + "\n\n" + ls2; 

}



bool design::PairMOLS::validate_mols()
{

    if(this->ls1->n != this->ls2->n)
        return false;

    int n = this->ls1->n;

    // maximum value for check array initialization
    std::vector<std::vector<bool>> check = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));

    for(int i= 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            auto pair = this->join[i][j];
            if(check[pair[0]][pair[1]])
            {
                std::cout << "error in row " << i << " column " << j << std::endl;
                return false;
            }

            check[pair[0]][pair[1]] = true;
        }
    }
    return true;
}

bool design::PairMOLS::has_equal_values()
{
        if(this->ls1->n != this->ls2->n)
        return false;

    int n = this->ls1->n;

    std::vector<std::vector<bool>> check = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));

    for(int i= 0; i<this->ls1->n; i++)
    {
        for(int j=0; j<this->ls1->n; j++)
        {
            auto pair = this->join[i][j];
            if(pair[0] == pair[1])
                return true;
        }
    }
    return false;
}


int design::PairMOLS::get_max_element_value()
{
    return this->max_element_value;
}

std::string design::PairMOLS::join_to_string(std::string delimiter_pairs, std::string delimiter_elements)
{
    std::vector<std::string> rows;

    for(auto row : this->join)
    {
        std::vector<std::string> pair_string;

        std::transform( row.begin(), row.end(), std::back_inserter(pair_string), 
                            [delimiter_elements](std::vector<int> pair) { 
                                return boost::algorithm::join( pair | boost::adaptors::transformed( static_cast<std::string(*)(int)>(std::to_string) ), delimiter_elements ); 
                            } );

        rows.push_back(boost::algorithm::join(pair_string, delimiter_pairs));
    }
    return boost::algorithm::join(rows, "\n");
}
