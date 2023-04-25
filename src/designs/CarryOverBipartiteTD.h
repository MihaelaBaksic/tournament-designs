#include "BipartiteTD.h"
#include "TD.h"

#ifndef H_CO_BIPARTITE_TOURNAMENT_DESIGN
#define H_CO_BIPARTITE_TOURNAMENT_DESIGN

namespace design
{
    class COBipartiteTournamentDesign : public BipartiteTournamentDesign
    {
        public:
            COBipartiteTournamentDesign(int n);
            COBipartiteTournamentDesign(int n, std::string filename);

            virtual bool validate_design();

        private:

            virtual std::vector<std::vector<std::vector<int>>> construct_design(int n);
            std::vector<std::vector<int>> construct_latin_square(int n);

            
    };
}


#endif // !H_CO_BIPARTITE_TOURNAMENT_DESIGN