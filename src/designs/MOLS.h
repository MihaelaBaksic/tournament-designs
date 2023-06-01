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
            PairMOLS(int range_1_lower, int range_1_upper, int range_2_lower, int range_2_upper);
            PairMOLS(int n, design::LatinSquare* ls1, design::LatinSquare* ls2);
            ~PairMOLS();
            
            std::vector<std::vector<std::vector<int>>> get_join();

            std::string to_string(std::string delimiter = ";");

            std::string join_to_string(std::string delimiter_pairs = ";", std::string delimiter_elements = " ");

            int get_max_element_value();

            bool validate_mols();
            bool has_equal_values();

            static std::vector<std::vector<int>> kronecker_product(design::LatinSquare &A, design::LatinSquare &B);


        private:
            LatinSquare* ls1;
            LatinSquare* ls2;
            std::vector<std::vector<std::vector<int>>> join;

            int max_element_value;

            std::vector<std::vector<std::vector<int>>> create_join();

    };
}




#endif 