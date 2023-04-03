#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>
#include "io.h"


using namespace std;


int io_manip::assert_input_parameters(int argc, char** argv)
{

    regex pat("[0-9]+");
    assert (argc==2 && regex_match(argv[1], pat) && "Program requires one argument of type int");
    int n = atoi(argv[1]);
    cout << n << endl;
    assert (n > 2 && "Side parameter must be bigger than 2!");
    return n; 
}


string io_manip::format_output()
{
    return "";
}

void io_manip::visualise(string file_name = "")
{

    return;
}