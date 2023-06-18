#include <string>
#include <vector>

#ifndef H_LATIN_SQUARE
#define H_LATIN_SQUARE

/*
    A class implementing Latin squares and complete Latin squares
    Three construction algorihtms are available: 
    - basic rotation
    - complete Latin square algorithm
    - k-construction
*/
namespace design{

    class LatinSquare{

        public:

            int n;
            std::vector<std::vector<int>> latin_square;

            // constructs basic Latin square by rotating or a complete Latin square
            LatinSquare(int n, bool complete = false); 

            /* constructs basic Latin square by rotating or a complete Latin square
            with elements from [lower_bound, upper_bound] */
            LatinSquare(int lower_bound, int upper_bound, bool complete); 

            // Reading a Latin square from the file with a given filename
            LatinSquare(int n, std::string filename);

            // Creating a Latin square from a predefined array
            LatinSquare(int n, std::vector<std::vector<int>> ls);

            /* Creates a Latin square by the k-construction algorithm */
            LatinSquare(int n, int k); 
            LatinSquare(); // use to construct pairs

            /* Performs validation of the design according to the definition 
            If complete is true, it validates the object as a complete Latin square*/
            bool validate_latin_square(bool complete = false);

            std::string to_string(std::string delimiter = ";");


            /* Asserts if the construct is defined for the given parameter */
            static void assert_parameter(int n, bool complete = false);
            static void assert_parameter(int n, int k);

            /* Calculates the memory consumption of a single object*/
            int get_memory_size();

        private:

            std::vector<std::vector<int>> read_latin_square(int n, std::string filename);

    };

}



#endif