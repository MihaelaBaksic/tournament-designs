#include <string>
#include <vector>

#ifndef H_LATIN_SQUARE
#define H_LATIN_SQUARE

namespace design{

    class LatinSquare{

        public:

            LatinSquare(int n); // constructs basic Latin square via shifting
            LatinSquare(int n, std::string filename);
            LatinSquare(int n, int k); // used only if n is a prime power
            LatinSquare(LatinSquare& ls_1, LatinSquare& ls_2); // use to construct MOLS

            int n;

            bool validate_latin_square();
            std::string to_string();

        private:
            std::vector<std::vector<int>> latin_square;

            std::vector<std::vector<int>> read_latin_square(int n, std::string filename);

    };

}



#endif