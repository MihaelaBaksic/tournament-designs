#include "BipartiteTD.h"

design::BipartiteTournamentDesign::BipartiteTournamentDesign(int n): TournamentDesign(n)
{
    this->n_rounds = n; // Bipartite tournaments have n rounds

}

design::BipartiteTournamentDesign::BipartiteTournamentDesign(int n, std::string filename): TournamentDesign(n)
{
    this->n_rounds = n; // Bipartite tournaments have n rounds
    this->design = this->read_design(n, filename);
    this->latin_square = this->design_to_latin_square();

}


std::vector<std::vector<std::vector<int>>> design::BipartiteTournamentDesign::construct_design(int n)
{

    return std::vector<std::vector<std::vector<int>>>();
    
}


bool design::BipartiteTournamentDesign::validate_design()
{
    return false;
}



std::vector<std::vector<int>> design::BipartiteTournamentDesign::design_to_latin_square()
{
    return std::vector<std::vector<int>>();
}


std::vector<std::vector<std::vector<int>>> design::BipartiteTournamentDesign::latin_square_to_design()
{
    return std::vector<std::vector<std::vector<int>>>();
}

