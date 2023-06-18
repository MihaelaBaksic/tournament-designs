#include "BipartiteTD.h"
#include "TD.h"
#include <memory>
#include "latin_square.h"


#ifndef H_CO_BIPARTITE_TOURNAMENT_DESIGN
#define H_CO_BIPARTITE_TOURNAMENT_DESIGN

/*
    Class implementing Bipartite tournament designs with balanced 
    carry-over effects.
    The design is stored in a Latin square format and the design format.
    The tournament is constructed as a symmetric complete Latin square.
*/
namespace design
{
    class COBipartiteTournamentDesign : public BipartiteTournamentDesign
    {
        public:
            COBipartiteTournamentDesign(int n);
            COBipartiteTournamentDesign(int n, std::string filename);

            /* Performs validation of the design according to the definition */
            virtual bool validate_design();
            virtual std::string to_string(std::string delimiter_pairs = ";", std::string delimiter_elements = " ");
            
            /* Calculates the memory consumption of a single object*/
            int get_memory_size();

            /* Asserts if the construct is defined for the given parameter */
            static void assert_parameter(int n);

        private:

            std::unique_ptr<LatinSquare> latin_square;

            /* Construction method */
            virtual std::vector<std::vector<std::vector<int>>> construct_design(int n);

            /* Transforms the design into a Latin square*/
            std::unique_ptr<LatinSquare> design_to_latin_square();

            /*Transforms a Latin square into a design*/
            std::vector<std::vector<std::vector<int>>> latin_square_to_design();

    };
}


#endif // !H_CO_BIPARTITE_TOURNAMENT_DESIGN