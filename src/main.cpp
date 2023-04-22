#include <iostream>
#include <string>
#include <memory>
#include "io/io.h"
#include "utils/utils.h"
#include "designs/TD.h"
#include "designs/BTD.h"
#include <chrono>

using namespace std;


int main(int argc, char** argv)
{
    int n = io_manip::assert_input_parameters(argc, argv);
    //int n = 3;

    auto start_design = chrono::high_resolution_clock::now();

    std::unique_ptr<design::TournamentDesign> d = std::unique_ptr<design::TournamentDesign>(new design::BalancedTournamentDesign(n));

    auto end_design = chrono::high_resolution_clock::now();


    auto start_validation = chrono::high_resolution_clock::now();
    //cout << d->to_string() << endl;

    d->validate_design();
    
    auto end_validation = chrono::high_resolution_clock::now();


    cout << "Parameter " << n << endl;
    cout << "Construction time: " << chrono::duration_cast<chrono::microseconds>(end_design - start_design).count() / 1000000. << endl;
    cout << "Validation time: " << chrono::duration_cast<chrono::microseconds>(end_validation - start_validation).count() / 1000000.<< endl;
    cout << "Total time: " <<  chrono::duration_cast<chrono::microseconds>(end_validation - start_design).count() / 1000000. << endl;
    


}