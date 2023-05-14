#include "latin_square.h"
#include <assert.h>
#include <string>
#include <iostream>
#include <fstream>

#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/range/adaptor/transformed.hpp>



design::LatinSquare::LatinSquare(int n)
{
    assert(n >= 1);
    this->n = n;
    this->latin_square = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));

    for(int row=0; row < n; row++)
        for(int column = 0; column < n; column++)
            this->latin_square[row][column] = (row + column) % n;

}

design::LatinSquare::LatinSquare(int n, std::string filename)
{
    assert(n >= 1);
    this->n = n;
    this->latin_square = this->read_latin_square(n, filename);
}


std::string design::LatinSquare::to_string(){

    std::vector<std::string> rows;

    for(auto row: this->latin_square)
    {
        std::vector<std::string> string_element;
        std::transform( row.begin(), row.end(), std::back_inserter(string_element), [](int i)
        {
             return std::to_string(i);
        });

        rows.push_back(boost::algorithm::join(string_element, ";"));
    }

    return boost::algorithm::join(rows, "\n");
    
}


std::vector<std::vector<int>> design::LatinSquare::read_latin_square(int n, std::string filename){

    std::vector<std::vector<int>> latin_square;

    std::ifstream input_file(filename);
    if(input_file.is_open())
    {
        std::string line;


        while(getline(input_file, line))
        {
            boost::trim(line);

            std::vector<int> row;
            std::vector<std::string> line_split;

            boost::split(line_split, line, boost::is_any_of(";"), boost::token_compress_on);

            std::transform( line_split.begin(), line_split.end(), std::inserter(row, row.begin()), &boost::lexical_cast<int,std::string>);

            latin_square.push_back(row);
        }
    }

    return latin_square;
}
