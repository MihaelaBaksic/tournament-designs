#include <assert.h>
#include <string>
#include <set>
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
#include "latin_square.h"
#include "../utils/utils.h"

design::LatinSquare::LatinSquare() {}

design::LatinSquare::LatinSquare(int n, bool complete)
{
    assert(n > 1);
    this->n = n;

    this->latin_square = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));

    if(!complete)
    {
        for(int row=0; row < n; row++)
            for(int column = 0; column < n; column++)
                this->latin_square[row][column] = (row + column) % n;
    }
    else
    {
        int m = n/2;

        int i=0;
        int j=0;
        int upper = n;
        int lower = 2;

        latin_square[i][j] = 1;

        for(int cnt=1; cnt<n; cnt++)
        {
            this->latin_square[i][cnt] = (cnt%2 == 1 ? lower : upper) % n;
            this->latin_square[cnt][j] = (cnt%2 == 1 ? lower : upper) % n;
            lower += cnt % 2 == 1 ? 1 : 0;
            upper -= cnt % 2 == 1 ? 0 : 1;
        }
        
        for(i=1; i<n; i++)
            for(j=1; j<n; j++)
                this->latin_square[i][j] = ( this->latin_square[i][0] + this->latin_square[0][j] - 1 + n ) % n;

    }

}

design::LatinSquare::LatinSquare(int lower_bound, int upper_bound, bool complete) :
    design::LatinSquare::LatinSquare(upper_bound-lower_bound, complete) 
{
    for(int i=0; i < this->n; i++)
        for(int j=0; j< this->n; j++)
            this->latin_square[i][j] += lower_bound;
}


design::LatinSquare::LatinSquare(int n, std::vector<std::vector<int>> ls)
{
    assert(n > 1);
    this->n = n;
    this->latin_square = ls;
}

design::LatinSquare::LatinSquare(int n, std::string filename)
{
    assert(n >= 1);
    this->n = n;
    this->latin_square = this->read_latin_square(n, filename);
}


std::string design::LatinSquare::to_string(std::string delimiter){

    std::vector<std::string> rows;

    for(auto row: this->latin_square)
    {
        std::vector<std::string> string_element;
        std::transform( row.begin(), row.end(), std::back_inserter(string_element), [](int i)
        {
             return std::to_string(i);
        });

        rows.push_back(boost::algorithm::join(string_element, delimiter));
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



bool design::LatinSquare::validate_latin_square(bool complete)
{

    for(int i=0; i<this->n; i++)
    {
        // every element must be contained in the row once
        std::set<int> row = std::set<int>(this->latin_square[i].begin(), this->latin_square[i].end());
        if(row.size() != this->n)
            return false;

        if(*row.begin() != 0)
            return false;

        if(*row.rbegin() != this->n - 1)
            return false;

        std::set<int> column = std::set<int>();
        for(int j=0; j<this->n; j++)
            column.insert(this->latin_square[j][i]);

        if(column.size() != this->n)
            return false;

        if(*column.begin() != 0)
            return false;

        if(*column.rbegin() != this->n - 1)
            return false; 
    }
    
    if(complete) // additional checks for completeness of latin squares
    {
        std::vector<std::vector<bool>> check = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));

        for(int i=0; i< this->n; i++)
        {
            for(int j=0; j < this->n-1; j++)
            {
                
                if(check[this->latin_square[i][j]][this->latin_square[i][j+1]])
                    return false;

                check[this->latin_square[i][j]][this->latin_square[i][j+1]] = true;
            }
        }
    }

    return true;
}


design::LatinSquare::LatinSquare(int n, int k)
{
    assert( k >= 1 && k<= n - 1);
    this->n = n;
    std::vector<int> gf = std::vector<int>(n, 0);
    this->latin_square = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));

    for(int i=0; i< n-1; i++)
        gf[i] = i+1;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            this->latin_square[i][j] = (gf[i]*gf[k-1] + gf[j]) % n;
    

}