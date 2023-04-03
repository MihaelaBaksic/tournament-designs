#include <iostream>
#include <string>
#include "io/io.h"

using namespace std;


int main(int argc, char** argv)
{
    int n = io_manip::assert_input_parameters(argc, argv);
     
    cout << "Hello, this is TD(" << n << ")" << endl;

}