#include "BipartiteTD.h"

design::BipartiteTournamentDesign::BipartiteTournamentDesign(int n): TournamentDesign(n)
{
    this->n_rounds = n; // Bipartite tournaments have n rounds

}

design::BipartiteTournamentDesign::BipartiteTournamentDesign(int n, std::string filename): TournamentDesign(n)
{
    this->n_rounds = n; // Bipartite tournaments have n rounds

}


std::vector<std::vector<std::vector<int>>> design::BipartiteTournamentDesign::construct_design(int n)
{

    return std::vector<std::vector<std::vector<int>>>();
    
}


bool design::BipartiteTournamentDesign::validate_design()
{
    return false;
}