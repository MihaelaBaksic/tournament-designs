#include "TD.h"

#ifndef H_BALANCED_TOURNAMENT_DESIGN
#define H_BALANCED_TOURNAMENT_DESIGN

/*
    A class implementing a Balanced tournament design
    The construction is performed via the Factor balanced tournament design algorihtm
*/
namespace design
{

    class BalancedTournamentDesign : public TournamentDesign
    {
        public:
            BalancedTournamentDesign(int n);
            BalancedTournamentDesign(int n, std::string filename);

            /* Performs validation of the design according to the definition */
            virtual bool validate_design();

            /* Calculates the memory consumption of a single object*/
            int get_memory_size();

            /* Asserts if the construct is defined for the given parameter */
            static void assert_parameter(int n);
           
        private:

            /* Construction method */
            virtual std::vector<std::vector<std::vector<int>>> construct_design(int n);

            /*Constructing FBTD of even side */
            std::vector<std::vector<std::vector<int>>> construct_even_side(int n);

            /*Constructing FBTD of odd side */
            std::vector<std::vector<std::vector<int>>> construct_odd_side(int n);

            /*Constructs FBTD of size 4 or 6 by reading from their respective files */
            std::vector<std::vector<std::vector<int>>> construct_manual(int n); 

    };

}


#endif // !H_BALANCED_TOURNAMENT_DESIGN