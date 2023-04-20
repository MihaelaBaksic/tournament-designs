#include <iostream>
#include <string>
#include <memory>
#include "io/io.h"
#include "utils/utils.h"
#include "designs/TD.h"
#include "designs/BTD.h"

using namespace std;


int main(int argc, char** argv)
{
    int n = io_manip::assert_input_parameters(argc, argv);

    std::unique_ptr<design::TournamentDesign> d = std::unique_ptr<design::TournamentDesign>(new design::BalancedTournamentDesign(n));

    cout << d->to_string() << endl;

    d->validate_design();

    

    
}