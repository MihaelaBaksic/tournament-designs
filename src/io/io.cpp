#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>
#include "io.h"
#include "../designs/BipartiteTD.h"
#include "../designs/BTD.h"
#include "../designs/CarryOverBipartiteTD.h"
#include "../designs/latin_square.h"
#include "../designs/MOLS.h"
#include "../designs/TD.h"


int io_manip::assert_input_parameters(int argc, char** argv)
{

    std::regex pat("[0-9]+");
    assert (argc==3 && regex_match(argv[2], pat) && "Program requires one argument of type string and one argument of type int\n Run: ./executable <design_name> <parameter>");
    int n = atoi(argv[2]);

    std::string input = argv[1];

    if (input == "TD") {
        throw std::invalid_argument("TD cannot be instantiated.");
    } else if (input == "FBTD") {
        design::BalancedTournamentDesign::assert_parameter(n);
    } else if (input == "BipartiteTD") {
        design::BipartiteTournamentDesign::assert_parameter(n);
    } else if (input == "COBipartiteTD") {
        design::COBipartiteTournamentDesign::assert_parameter(n);
    } else if (input == "LS") {
        design::LatinSquare::assert_parameter(n);
    } else if (input == "MOLS") {
        design::PairMOLS::assert_parameter(n);
    } else {
        throw std::invalid_argument("Invalid design name input.");
    }

    return n; 
}


