#include <iostream>

#include "BipartiteTD.h"
#include "MOLS.h"

design::BipartiteTournamentDesign::BipartiteTournamentDesign(int n, bool base): TournamentDesign(n)
{
    this->n_rounds = n; // Bipartite tournaments have n rounds
    if(! base)
        this->design = this->construct_design(n);
}

design::BipartiteTournamentDesign::BipartiteTournamentDesign(int n, std::string filename): TournamentDesign(n)
{
    this->n_rounds = n; // Bipartite tournaments have n rounds
    this->design = this->read_design(n, filename);
}


std::vector<std::vector<std::vector<int>>> design::BipartiteTournamentDesign::construct_design(int n)
{
    design::PairMOLS p = design::PairMOLS(n, false);
    return p.get_join();
}


bool design::BipartiteTournamentDesign::validate_design()
{
    int n = this->n;

    std::vector<std::vector<bool>> check = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));

    for(int i= 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            auto pair = this->design[i][j];
            if(check[pair[0]][pair[1]])
            {
                std::cout << "error in row " << i << " column " << j << std::endl;
                return false;
            }

            check[pair[0]][pair[1]] = true;
        }
    }
    return true;
}



int design::BipartiteTournamentDesign::get_memory_size()
{
    int size = sizeof(*this);

    size += sizeof(this->design) + this->design.size() * ( sizeof(this->design[0]) + this->design[0].size() * (sizeof(this->design[0][0]) + this->design[0][0].size() * sizeof(int)) );  

    return size;
}

void design::BipartiteTournamentDesign::assert_parameter(int n)
{
    if(! (n > 2))
        throw std::invalid_argument("n > 2 must hold");

    design::PairMOLS::assert_parameter(n);
}
