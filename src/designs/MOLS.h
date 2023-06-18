#include "latin_square.h"
#include <vector>
#include <tuple>
#include <utility>
#include <memory>
#include "../utils/utils.h"

#ifndef H_MOLS
#define H_MOLS

/*
    Class implementing a pair of Mutually orthogonal Latin squares
    Contains two Latin squares.
    The join is constructed optionally.
*/
namespace design
{
    class PairMOLS
    {
        public:
            PairMOLS(int n, bool with_join = false);
            PairMOLS(int range_1_lower, int range_1_upper, int range_2_lower, int range_2_upper, bool with_join = false);
            PairMOLS(int n, design::LatinSquare* ls1, design::LatinSquare* ls2, bool with_join = false);
            
            /*If join of Latin squares member variable is constructed, the method returns it
            Otherwise, the method constructs the join and returns it*/
            std::vector<std::vector<std::vector<int>>> get_join();

            std::string to_string(std::string delimiter = ";");

            std::string join_to_string(std::string delimiter_pairs = ";", std::string delimiter_elements = " ");

            /* Returns value of the biggest element in the*/
            int get_max_element_value();

            /* Performs validation of the MOLS according to the definition */
            bool validate_mols();

            static std::vector<std::vector<int>> kronecker_product(std::unique_ptr<design::LatinSquare> & A, std::unique_ptr<design::LatinSquare> & B);

            /* Calculates the memory consumption of a single object*/
            int get_memory_size();

            /* Asserts if the construct is defined for the given parameter */
            static void assert_parameter(int n);


        private:
            std::unique_ptr<LatinSquare> ls1;
            std::unique_ptr<LatinSquare> ls2;
            std::vector<std::vector<std::vector<int>>> join;
            int max_element_value;

            std::vector<std::vector<std::vector<int>>> create_join();

    };
}




#endif 