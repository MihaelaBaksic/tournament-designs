#include "TD.h"

#ifndef H_BIPARTITE_TOURNAMENT_DESIGN
#define H_BIPARTITE_TOURNAMENT_DESIGN

/*
    Class implementing Bipartite tournament designs
    based on construction of a pair of MOLS
*/
namespace design
{
    class BipartiteTournamentDesign : public TournamentDesign
    {
        public:

            /* Constructs a Bipartite tournament design
               If base is true, only parameters are set, 
               the design is not constructed. */
            BipartiteTournamentDesign(int n, bool base = false);
            BipartiteTournamentDesign(int n, std::string filename);

            /* Performs validation of the design according to the definition */
            virtual bool validate_design();

            /* Calculates the memory consumption of a single object*/
            int get_memory_size();

            /* Asserts if the construct is defined for the given parameter */
            static void assert_parameter(int n);

        protected:
            
            /* Construction method */
            virtual std::vector<std::vector<std::vector<int>>> construct_design(int n);


    };
}


#endif // !H_BIPARTITE_TOURNAMENT_DESIGN