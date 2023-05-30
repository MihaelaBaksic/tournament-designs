#include "MOLS.h"
#include <list>
#include <assert.h>
#include <iostream>

design::PairMOLS::PairMOLS(int n)
{
    //assert(n > 2 && n != 6);

    // deconstruct n to prime powers (this is an ordered list)
    std::vector<int> prime_powers = get_prime_powers(n);

    std::vector<design::LatinSquare> latin_squares;
    for(int pp : prime_powers)
    {
        LatinSquare ls(pp, 1);
        latin_squares.push_back(ls);
    }

    design::LatinSquare last_ls(prime_powers[prime_powers.size()-1], 2);

    this->ls1 = new LatinSquare(prime_powers[0], latin_squares[0].latin_square);
    this->ls2 = new LatinSquare(last_ls.n, last_ls.latin_square);

    this->join = create_join();

}

design::PairMOLS::~PairMOLS()
{
    free(this->ls1);
    free(this->ls2);
}


std::vector<std::vector<int>> product(design::LatinSquare &A, design::LatinSquare &B)
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

std::string design::PairMOLS::to_string()
{
    std::string ls1 = this->ls1->to_string();
    std::string ls2 = this->ls2->to_string();

    return ls1 + "\n\n" + ls2; 

}



bool design::PairMOLS::validate_mols()
{

    if(this->ls1->n != this->ls2->n)
        return false;

    int n = this->ls1->n;

    std::vector<std::vector<bool>> check = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));

    std::cout << "SIZE : " << sizeof(check) << std::endl;

    for(auto row : join)
    {
        for(auto pair : row)
        {
            if(check[pair[0]][pair[1]])
                return false;

            check[pair[0]][pair[1]] = true;
        }
    }
    return true;
}