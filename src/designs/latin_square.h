#include <string>
#include <vector>

#ifndef H_LATIN_SQUARE
#define H_LATIN_SQUARE

namespace design{

    class LatinSquare{

        public:

            LatinSquare(int n, bool complete); // constructs basic Latin square via shifting
            LatinSquare(int n, std::string filename);
            LatinSquare(int n, std::vector<std::vector<int>> ls);
            LatinSquare(int n, int k); // used only if n is a prime power
            LatinSquare(LatinSquare& ls_1, LatinSquare& ls_2); // use to construct MOLS

            int n;

            bool validate_latin_square();
            std::string to_string();

            std::vector<std::vector<int>> latin_square;



        private:

            std::vector<std::vector<int>> read_latin_square(int n, std::string filename);

    };

}



#endif