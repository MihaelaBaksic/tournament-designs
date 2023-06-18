#include <iostream>
#include <string>
#include <memory>
#include "io/io.h"
#include "utils/utils.h"
#include "designs/TD.h"
#include "designs/BTD.h"
#include "designs/CarryOverBipartiteTD.h"
#include "designs/latin_square.h"
#include "designs/MOLS.h"
#include <chrono>

using namespace std;


int main(int argc, char** argv)
{
    int n = io_manip::assert_input_parameters(argc, argv);

    std::string input = argv[1];

    if (input == "FBTD") {
        std::unique_ptr<design::BalancedTournamentDesign> td = unique_ptr<design::BalancedTournamentDesign>(new design::BalancedTournamentDesign(n));
        std::cout << td->to_string() << std::endl;
    } else if (input == "BipartiteTD") {
        std::unique_ptr<design::BipartiteTournamentDesign> td = unique_ptr<design::BipartiteTournamentDesign>(new design::BipartiteTournamentDesign(n));
        std::cout << td->to_string() << std::endl;
    } else if (input == "COBipartiteTD") {
        std::unique_ptr<design::COBipartiteTournamentDesign> td = unique_ptr<design::COBipartiteTournamentDesign>(new design::COBipartiteTournamentDesign(n));
        std::cout << td->to_string() << std::endl;
    } else if (input == "LS") {
        std::unique_ptr<design::LatinSquare> td = unique_ptr<design::LatinSquare>(new design::LatinSquare(n));
        std::cout << td->to_string() << std::endl;
    } else if (input == "MOLS") {
        std::unique_ptr<design::PairMOLS> td = unique_ptr<design::PairMOLS>(new design::PairMOLS(n));
        std::cout << td->to_string() << std::endl;
    } else {
        std::cout << "Invalid design name input." << std::endl;
    }
}