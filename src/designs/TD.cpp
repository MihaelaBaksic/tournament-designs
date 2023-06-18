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
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include "TD.h"
#include "../utils/utils.h"

using namespace std;

design::TournamentDesign::TournamentDesign(int n)
{
    this->n = n;
    this->n_teams = 2*n;
    this->n_courts = n;
    this->n_rounds = 2*n - 1;
    
}


std::string design::TournamentDesign::to_string(std::string delimiter_pairs, std::string delimiter_elements)
{   

    vector<string> rows;

    for(auto row : this->design)
    {
        vector<string> pair_string;

        std::transform( row.begin(), row.end(), std::back_inserter(pair_string), 
                            [delimiter_elements](std::vector<int> pair) { 
                                return boost::algorithm::join( pair | boost::adaptors::transformed( static_cast<std::string(*)(int)>(std::to_string) ), delimiter_elements ); 
                            } );

        rows.push_back(boost::algorithm::join(pair_string, delimiter_pairs));
    }
    return boost::algorithm::join(rows, "\n");
}


vector<vector<vector<int>>> design::TournamentDesign::read_design(int n, string filename)
{   
    vector<vector<vector<int>>> design;
    ifstream input_file(filename);
    if(input_file.is_open())
    {
        
        string line;
        while (getline(input_file, line)) 
        {   
            boost::trim(line);

            //cout << line << endl;

            vector<vector<int>> row;
            vector<string> pairs;
            boost::split(pairs, line, boost::is_any_of(";"), boost::token_compress_on);


            for(auto pair : pairs)
            {
                std::vector<int> pair_set;
                boost::tokenizer<> tok(pair);
                std::transform( tok.begin(), tok.end(), std::inserter(pair_set, pair_set.begin()), &boost::lexical_cast<int,std::string>);

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


void design::TournamentDesign::assert_parameter(int n)
{
    if(! (n > 2))
        throw std::invalid_argument("n > 2 must hold");
}