#include "latin_square.h"
#include <vector>
#include <tuple>
#include <utility>
#include <memory>
#include "../utils/utils.h"

#ifndef H_MOLS
#define H_MOLS


namespace design
{
    class PairMOLS
    {

        public:
            PairMOLS(int n);
            
            std::vector<std::vector<std::vector<int>>> get_join();

            std::string to_string();

        private:
            LatinSquare* ls1;
            LatinSquare* ls2;
            std::vector<std::vector<std::vector<int>>> join;

            std::vector<std::vector<std::vector<int>>> create_join();
            std::vector<std::vector<int>> product(design::LatinSquare &A, design::LatinSquare &B);

    };
}




#endif 