#include "CarryOverBipartiteTD.h"
#include "TD.h"
#include "latin_square.h"
#include<iostream>
#include<memory>

design::COBipartiteTournamentDesign::COBipartiteTournamentDesign(int n):BipartiteTournamentDesign(n, true)
{
    this->latin_square = std::unique_ptr<LatinSquare>(new LatinSquare(n, true));
    this->design = this->construct_design(n);

}


design::COBipartiteTournamentDesign::COBipartiteTournamentDesign(int n, std::string filename): BipartiteTournamentDesign(n, filename)
{
    this->latin_square = std::unique_ptr<LatinSquare>(new LatinSquare(n, filename));
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
            int first = this->latin_square->latin_square[i][j];
            int second = this->latin_square->latin_square[i][j+1];

            if(pairs[first][second] == 1)
                return false;

            pairs[first][second] = 1;
        }
    }

    return true;
}


std::unique_ptr<design::LatinSquare> design::COBipartiteTournamentDesign::design_to_latin_square()
{
    std::vector<std::vector<int>> latin_square = std::vector<std::vector<int>>(this->n, std::vector<int>(this->n, -1));

    for(int i=0; i<this->n; i++)
        for(int j=0; j<this->n; j++)
        {
            int x = this->design[i][j][0];
            int y = this->design[i][j][1];
            latin_square[x][y] = i;
            latin_square[y][x] = i;
        }

    return std::unique_ptr<LatinSquare>(new LatinSquare(n, latin_square));
}


std::vector<std::vector<std::vector<int>>> design::COBipartiteTournamentDesign::latin_square_to_design()
{
    std::vector<std::vector<std::vector<int>>> design = std::vector<std::vector<std::vector<int>>>(n, std::vector<std::vector<int>>(n, std::vector<int>(2, -1)));

    std::vector<int> round_match_count(n, 0);

    for(int i=0; i<this->n; i++)
    {
        for(int j=0; j<this->n; j++)
        {
            int round = this->latin_square->latin_square[i][j];
            design[round][round_match_count[round]][0] = i;
            design[round][round_match_count[round]][1] = j;
            round_match_count[round]++;
        }
    }
    
    return design;
}


std::string design::COBipartiteTournamentDesign::to_string(std::string delimiter_pairs, std::string delimiter_elements)
{
    std::string str = "";
    
    str += this->latin_square->to_string(delimiter_elements);
    str += "\n";
    str += BipartiteTournamentDesign::to_string(delimiter_pairs, delimiter_elements);
    return str;
}


int design::COBipartiteTournamentDesign::get_memory_size()
{
    int size = sizeof(*this);

    size += this->latin_square->get_memory_size();

    size += sizeof(this->design) + this->design.size() * ( sizeof(this->design[0]) + this->design[0].size() * (sizeof(this->design[0][0]) + this->design[0][0].size() * sizeof(int)) );  

    return size;
}

void design::COBipartiteTournamentDesign::assert_parameter(int n)
{
    if(! (n > 0))
        throw std::invalid_argument("n > 0 must hold");
}