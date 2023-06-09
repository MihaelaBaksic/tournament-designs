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

            virtual bool validate_design() = 0;

            virtual std::string to_string(std::string delimiter_pairs = ";", std::string delimiter_elements = " ");
            static std::vector<std::vector<std::vector<int>>> read_design(int n, std::string filename);
            
        protected:
            int n;
            int n_courts;
            int n_rounds;
            int n_teams;

            std::vector<std::vector<std::vector<int>>> design;

            virtual std::vector<std::vector<std::vector<int>>> construct_design(int n) = 0;
            
    };

}


#endif // !H_TOURNAMENT_DESIGN