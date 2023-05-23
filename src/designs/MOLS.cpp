#include "MOLS.h"
#include <list>
#include <vector>

design::PairMOLS::PairMOLS(int n)
{
    assert(n > 2 && n != 6)

    // deconstruct n to prime powers (this is an ordered list)
    std::vector<int> prime_powers = get_prime_powers(n);

    std::list<design::LatinSquare> latin_squares;
    for(int pp : prime_powers)
    {
        LatinSquare ls = new LatinSquare(pp, k=1);
        latin_squares.push_back(ls)
    }

    design::LatinSquare last_ls = new LatinSquare(prime_powers[-1], k=2);

    this->pair = std::make_pair<design::LatinSquare, design::LatinSquare>(latin_squares[0], last_ls);

}


std::vector<std::vector<std::vector<int>>>> combine_latin_squares(design::LatinSquare ls1, design::LatinSquare ls2)
{
    // TODO
    return nullptr;
}



std::vector<std::vector<std::vector<int>>>> design::PairMOLS::get_join()
{
    // TODO
    return nullptr;
}