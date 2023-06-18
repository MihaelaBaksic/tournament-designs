#include <vector>
#include <set>
#include <string>


#ifndef H_TOURNAMENT_DESIGN
#define H_TOURNAMENT_DESIGN

/*
    Abstract class implementing a Tournament design
*/
namespace design {

    class TournamentDesign
    {

        public:
            TournamentDesign(int n);

            /* Performs validation of the design according to the definition */
            virtual bool validate_design() = 0;

            virtual std::string to_string(std::string delimiter_pairs = ";", std::string delimiter_elements = " ");
            static std::vector<std::vector<std::vector<int>>> read_design(int n, std::string filename);

            /* Asserts if the construct is defined for the given parameter */
            static void assert_parameter(int n);
            
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