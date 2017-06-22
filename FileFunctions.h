#pragma once

#include <string>
#include <vector>
namespace FileFunctions
{

	// Write all lines in the given vector to the output file
	void writeVectorToFile(std::string fname, std::vector<std::string> &lines, bool append = false);

}