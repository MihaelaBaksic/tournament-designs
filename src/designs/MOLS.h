#include "latin_square.h"


#ifndef H_MOLS
#define H_MOLS


namespace design
{
    class PairMOLS
    {

        public:
            PairMOLS(int n);
            std::vector<std::vector<std::vector<int>>>> get_join();

        private:
            std::pair<design::LatinSquare, design::LatinSquare> pair;

            std::vector<std::vector<std::vector<int>>>> combine_latin_squares(design::LatinSquare ls1, design::LatinSquare ls2);

    }
}


#endif H_MOLS