#include "TD.h"

#ifndef H_BALANCED_TOURNAMENT_DESIGN
#define H_BALANCED_TOURNAMENT_DESIGN


namespace design
{

    class BalancedTournamentDesign : public TournamentDesign
    {
        public:
            BalancedTournamentDesign(int n);
            ~BalancedTournamentDesign();

            virtual bool validate_design();
           
        private:
            virtual std::vector<std::vector<int>> construct_design(int n);
            std::vector<std::vector<int>> construct_even_side(int n);
            std::vector<std::vector<int>> construct_odd_side(int n);
            std::vector<std::vector<int>> construct_manual(int n);            
    };

}


#endif // !H_BALANCED_TOURNAMENT_DESIGN