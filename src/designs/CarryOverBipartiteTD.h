#include "BipartiteTD.h"
#include "TD.h"
#include <memory>
#include "latin_square.h"


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

            int get_memory_size();

        private:

            std::unique_ptr<LatinSquare> latin_square;

            virtual std::vector<std::vector<std::vector<int>>> construct_design(int n);

            std::unique_ptr<LatinSquare> design_to_latin_square();
            std::vector<std::vector<std::vector<int>>> latin_square_to_design();

    };
}


#endif // !H_CO_BIPARTITE_TOURNAMENT_DESIGN