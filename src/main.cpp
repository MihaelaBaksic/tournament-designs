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


bool validate_mols(design::LatinSquare &ls1, design::LatinSquare & ls2) 
{

    if(ls1.n != ls2.n)
        return false;

    int n = ls1.n;

    std::vector<std::vector<bool>> check = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));

    for(int i= 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(check[ls1.latin_square[i][j]][ls2.latin_square[i][j]])
            {
                std::cout << "error in row " << i << " column " << j << std::endl;
                return false;
            }

            check[ls1.latin_square[i][j]][ls2.latin_square[i][j]] = true;
        }
    }
    return true;
}


int main(int argc, char** argv)
{
    /*
     cout << "parameter,construction_time,validation_time,total_time" << endl;
    
    for(int i=5; i<=20; i+=2)
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
    */

    /*
    
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

   //int n = 3*5; //io_manip::assert_input_parameters(argc, argv);
   /*std::unique_ptr<design::LatinSquare> ls = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, 1));
   std::cout << ls->to_string() << std::endl;
   std::cout << ls->validate_latin_square() << std::endl;
   
    
    std::unique_ptr<design::COBipartiteTournamentDesign> d = std::unique_ptr<design::COBipartiteTournamentDesign>(new design::COBipartiteTournamentDesign(n));

    std::cout << d->to_string() << std::endl;
    */

    /*    
    std::unique_ptr<design::PairMOLS> mols = std::unique_ptr<design::PairMOLS>(new design::PairMOLS(n));

    std::cout << mols->to_string() << std::endl;

    std::cout << mols->validate_mols() << std::endl;

    std::cout << mols->has_equal_values() << std::endl;

    */
    
    /*int n1=4;
    int n2=5;
    int n3=17;
    
    design::LatinSquare ls1(n1, 1);
    design::LatinSquare ls2(n1, 2);
    std::cout << ls1.to_string() << std::endl << std::endl;
    std::cout << ls2.to_string() << std::endl << std::endl;

    std::cout << "Orthogonal? " << validate_mols(ls1, ls2) << std::endl;

    design::LatinSquare ls11(n2, 1);
    design::LatinSquare ls22(n2, 2);
    std::cout << ls11.to_string() << std::endl << std::endl;
    std::cout << ls22.to_string() << std::endl << std::endl;

    std::cout << "Orthogonal? " << validate_mols(ls11, ls22) << std::endl;

    design::LatinSquare ls111(n3, 1);
    design::LatinSquare ls222(n3, 2);
    std::cout << ls111.to_string() << std::endl << std::endl;
    std::cout << ls222.to_string() << std::endl << std::endl;

    std::cout << "Orthogonal? " << validate_mols(ls111, ls222) << std::endl;
    
    
    design::LatinSquare product_1(n1*n2, design::PairMOLS::product(ls11, ls1));
    design::LatinSquare product_2(n1*n2, design::PairMOLS::product(ls22, ls2));

    std::cout << product_1.to_string() << std::endl << std::endl;
    std::cout << product_2.to_string() << std::endl << std::endl;
    std::cout << "Orthogonal? " << validate_mols(product_1, product_2) << std::endl;


    design::LatinSquare product_11(n1*n2*n3, design::PairMOLS::product(ls111, product_1));
    design::LatinSquare product_22(n1*n2*n3, design::PairMOLS::product(ls222, product_2));

    std::cout << product_11.to_string() << std::endl << std::endl;
    std::cout << product_22.to_string() << std::endl << std::endl;
    std::cout << "Orthogonal? " << validate_mols(product_11, product_22) << std::endl;

    
    */
    
    //cout << "algorithm, parameter,optimization,construction_time" << endl;
    
    /*
    for(int i=4921 ;i<=4921 ; i+=100)
    {
        double sum = 0.;

        int n_runs = 10;

        for(int j=0; j<n_runs; j++)
        {
            auto start_design = chrono::high_resolution_clock::now();

            std::unique_ptr<design::BalancedTournamentDesign> d = std::unique_ptr<design::BalancedTournamentDesign>(new design::BalancedTournamentDesign(i));

            auto end_design = chrono::high_resolution_clock::now();

            sum += chrono::duration_cast<chrono::microseconds>(end_design - start_design).count() / 1000000. ;
        }




        cout << "FBTD" << ","
                    << i << "," << "O3" 
                    << "," <<  sum / n_runs
                    << endl ;
   
        
    }
    */
    
    
    design::BalancedTournamentDesign pm(101);
    cout << pm.get_memory_size() << endl;
    
    
    
}