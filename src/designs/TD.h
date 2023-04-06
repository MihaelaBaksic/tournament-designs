#include <vector>
#include <set>
#include <string>

#ifndef H_TOURNAMENT_DESIGN
#define H_TOURNAMENT_DESIGN

namespace design {

    class TournamentDesign
    {

        public:
            TournamentDesign(int n);
            //~TournamentDesign();

            virtual bool validate_design() = 0;

            virtual std::string to_string();
            
        protected:
            int n;
            int n_courts;
            int n_rounds;
            int n_teams;

            std::vector<std::vector<std::set<int>>> design;

            virtual std::vector<std::vector<std::set<int>>> construct_design(int n) = 0;
            std::vector<std::vector<std::set<int>>> read_design(int n, std::string filename);
    };

}


#endif // !H_TOURNAMENT_DESIGN