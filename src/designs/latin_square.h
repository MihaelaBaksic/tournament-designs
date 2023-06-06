#include <string>
#include <vector>

#ifndef H_LATIN_SQUARE
#define H_LATIN_SQUARE

namespace design{

    class LatinSquare{

        public:

            LatinSquare(int n, bool complete = false); // constructs basic Latin square via shifting
            LatinSquare(int lower_bound, int upper_bound, bool complete);
            LatinSquare(int n, std::string filename);
            LatinSquare(int n, std::vector<std::vector<int>> ls);
            LatinSquare(int n, int k); // used only if n is a prime power
            LatinSquare(); // use to construct pairs

            int n;

            bool validate_latin_square(bool complete = false);
            std::string to_string(std::string delimiter = ";");

            std::vector<std::vector<int>> latin_square;

            int get_memory_size();

        private:

            std::vector<std::vector<int>> read_latin_square(int n, std::string filename);

    };

}



#endif