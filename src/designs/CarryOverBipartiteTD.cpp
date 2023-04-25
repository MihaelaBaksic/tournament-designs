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

    this->design = this->construct_design(n);

}



std::vector<std::vector<int>> design::COBipartiteTournamentDesign::construct_latin_square(int n)
{

    std::vector<std::vector<int>> latin_square = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));

    int m = n/2;

    int i=0;
    int j=0;
    int upper = n;
    int lower = 2;

    latin_square[i][j] = 1;

    for(int cnt=1; cnt<n; cnt++)
    {
        if(cnt % 2 == 1)
        {
            latin_square[i][cnt] = lower % n;
            latin_square[cnt][j] = lower % n;
            lower++;
        }
        else
        {
            latin_square[i][cnt] = upper % n;
            latin_square[cnt][j] = upper % n;
            upper--;
        }
    }
    

    for(i=1; i<n; i++)
    {
        for(j=1; j<n; j++)
        {
            latin_square[i][j] = ( latin_square[i][0] + latin_square[0][j] - 1 + n ) % n;
        }
    }


    return latin_square;
}


std::vector<std::vector<std::vector<int>>> design::COBipartiteTournamentDesign::construct_design(int n)
{
    return this->latin_square_to_design(); 
}


bool design::COBipartiteTournamentDesign::validate_design()
{
    //validate latin square to be complete

    std::vector<std::vector<int>> pairs(n, std::vector<int>(n, 0));

    for(int i=0; i<this->n; i++)
    {
        for(int j=0; j< this->n -1; j++)
        {
            int first = this->latin_square[i][j];
            int second = this->latin_square[i][j+1];

            if(pairs[first][second] == 1)
                return false;

            pairs[first][second] = 1;
        }
    }

    return true;
}