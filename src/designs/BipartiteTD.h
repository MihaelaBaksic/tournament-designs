#include "TD.h"

#ifndef H_BIPARTITE_TOURNAMENT_DESIGN
#define H_BIPARTITE_TOURNAMENT_DESIGN

namespace design
{
    class BipartiteTournamentDesign : public TournamentDesign
    {
        public:

            BipartiteTournamentDesign(int n);
            BipartiteTournamentDesign(int n, std::string filename);

            virtual bool validate_design();

        protected:

            virtual std::vector<std::vector<std::vector<int>>> construct_design(int n);
            
            std::vector<std::vector<int>> latin_square;

    };
}




#endif // !H_BIPARTITE_TOURNAMENT_DESIGN