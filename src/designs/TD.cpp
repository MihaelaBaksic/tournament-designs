#include <assert.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <set>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split
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
            auto cell_it = this->design[row][col].begin();
            std::string tmp = std::to_string(*cell_it);
            tmp += " ";
            tmp += std::to_string(*(++cell_it));
            s += ";";
            s += tmp;
            
        }
        s += "\n";
    }
    return s;

}


vector<vector<set<int>>> design::TournamentDesign::read_design(int n, string filename)
{   
    vector<vector<set<int>>> design;
    ifstream input_file(filename);
    if(input_file.is_open())
    {
        string line;
        while (getline(input_file, line)) 
        {
            vector<set<int>> row;
            vector<string> pairs;
            string s;
            boost::split(pairs, s, boost::is_any_of(";"), boost::token_compress_on);

            for(auto pair : pairs)
            {
                std::set<int> pair_set;
                boost::tokenizer<> tok(pair);
                std::transform( tok.begin(), tok.end(), std::back_inserter(pair), &boost::lexical_cast<int,std::string> );
                row.push_back(pair_set);
            }

            design.push_back(row);
        }
        input_file.close();
    }
    else
        throw std::invalid_argument("Unable to open specified design file");


    return design;

}
