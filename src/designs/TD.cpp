#include <assert.h>
#include <vector>

#include "TD.h"

using namespace std;

design::TournamentDesign::TournamentDesign(int n)
{
    this->n = n;
    this->n_teams = 2*n;
    this->n_courts = n;
    this->n_rounds = 2*n - 1;
    
}


std::string design::TournamentDesign::to_string()
{   
    std::string s = "";

    for(int row = 0; row < this->n_rounds; row++)
    {
        
        for(int col = 0; col < this->n_courts; col++)
        {
            std::string tmp = std::to_string(this->design[row][col]);
            tmp.resize(2);
            s += tmp;
        }
        s += "\n";
    }
    return s;

}
