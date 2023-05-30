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
    /* cout << "parameter,construction_time,validation_time,total_time" << endl;
    
    for(int i=2351; i<=3877; i+=2)
    {
        auto start_design = chrono::high_resolution_clock::now();

        std::unique_ptr<design::TournamentDesign> d = std::unique_ptr<design::TournamentDesign>(new design::BalancedTournamentDesign(i));

        auto end_design = chrono::high_resolution_clock::now();



        auto start_validation = chrono::high_resolution_clock::now();

        d->validate_design();
        
        auto end_validation = chrono::high_resolution_clock::now();

        cout << i << "," <<  chrono::duration_cast<chrono::microseconds>(end_design - start_design).count() / 1000000. 
                    << "," << chrono::duration_cast<chrono::microseconds>(end_validation - start_validation).count() / 1000000.
                    << ',' << chrono::duration_cast<chrono::microseconds>(end_validation - start_design).count() / 1000000. << endl;
    
    }

    
    int n = 6; //io_manip::assert_input_parameters(argc, argv);

    std::unique_ptr<design::TournamentDesign> d = std::unique_ptr<design::TournamentDesign>(new design::COBipartiteTournamentDesign(n));

    std::cout << d->validate_design() << std::endl;

    cout << d->to_string() << endl;
    */
    /*

    cout << "Parameter " << n << endl;
    cout << "Construction time: " << chrono::duration_cast<chrono::microseconds>(end_design - start_design).count() / 1000000. << endl;
    cout << "Validation time: " << chrono::duration_cast<chrono::microseconds>(end_validation - start_validation).count() / 1000000.<< endl;
    cout << "Total time: " <<  chrono::duration_cast<chrono::microseconds>(end_validation - start_design).count() / 1000000. << endl;

    */

   int n = 8 ; //io_manip::assert_input_parameters(argc, argv);
   /*std::unique_ptr<design::LatinSquare> ls = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, 1));
   std::cout << ls->to_string() << std::endl;
   std::cout << ls->validate_latin_square() << std::endl;
   
    
    std::unique_ptr<design::COBipartiteTournamentDesign> d = std::unique_ptr<design::COBipartiteTournamentDesign>(new design::COBipartiteTournamentDesign(n));

    std::cout << d->to_string() << std::endl;
    */

    std::unique_ptr<design::PairMOLS> mols = std::unique_ptr<design::PairMOLS>(new design::PairMOLS(n));

    int i=0;
    for(i=0; i<10; i++)
    {
        i++;
    }
    std::cout << i << std::endl;
    std::cout << mols->to_string() << std::endl;

    std::cout << mols->validate_mols() << std::endl;

    
}