#include <string>

#ifndef H_INPUT_OUTPUT_MANIP
#define H_INPUT_OUTPUT_MANIP 

namespace io_manip
{

int assert_input_parameters(int argc, char** argv);
std::string format_output();

void visualise(std::string file_name);

}

#endif //!H_INPUT_OUTPUT_MANIP