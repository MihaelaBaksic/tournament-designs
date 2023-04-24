#include "CarryOverBipartiteTD.h"
#include "TD.h"

design::COBipartiteTournamentDesign::COBipartiteTournamentDesign(int n): BipartiteTournamentDesign(n)
{
    this->n_rounds = n; // Bipartite tournaments have n rounds

}


std::vector<std::vector<std::vector<int>>> design::COBipartiteTournamentDesign::construct_design(int n)
{

    return std::vector<std::vector<std::vector<int>>>();
    
}


bool design::COBipartiteTournamentDesign::validate_design()
{
    return false;
}