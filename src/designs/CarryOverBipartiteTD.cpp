#include "CarryOverBipartiteTD.h"
#include "TD.h"
#include<iostream>

design::COBipartiteTournamentDesign::COBipartiteTournamentDesign(int n): BipartiteTournamentDesign(n)
{
    this->n_rounds = n; // Bipartite tournaments have n rounds

    this->latin_square = this->construct_latin_square(n);

}


design::COBipartiteTournamentDesign::COBipartiteTournamentDesign(int n, std::string filename): BipartiteTournamentDesign(n, filename)
{
    this->n_rounds = n; // Bipartite tournaments have n rounds

    this->latin_square = this->construct_latin_square(n);

}



std::vector<std::vector<int>> design::COBipartiteTournamentDesign::construct_latin_square(int n)
{

    std::vector<std::vector<int>> design_LS = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));

    int m = n/2;

    int i=0;
    int j=0;
    int upper = n;
    int lower = 2;

    design_LS[i][j] = 1;

    for(int cnt=1; cnt<n; cnt++)
    {
        if(cnt % 2 == 1)
        {
            design_LS[i][cnt] = lower;
            design_LS[cnt][j] = lower;
            lower++;
        }
        else
        {
            design_LS[i][cnt] = upper;
            design_LS[cnt][j] = upper;
            upper--;
        }
    }
    

    for(i=1; i<n; i++)
    {
        for(j=1; j<n; j++)
        {
            design_LS[i][j] = ( design_LS[i][0] + design_LS[0][j] - 1 + n ) % n;
        }
    }

    return design_LS;
}


std::vector<std::vector<std::vector<int>>> design::COBipartiteTournamentDesign::construct_design(int n)
{
    return std::vector<std::vector<std::vector<int>>>(); 
}


bool design::COBipartiteTournamentDesign::validate_design()
{
    return false;
}