#include "FileFunctions.h"

#include <fstream>
namespace FileFunctions
{

	void writeVectorToFile(std::string fname, std::vector<std::string> &lines, bool append) {

		std::ofstream of;

		if (append)
			of.open(fname, std::ofstream::app);
		else
			of.open(fname);

		if (!of.is_open()) {
			throw std::exception("File could not be opened");
		}
		else {
			for (std::string &s : lines) {
				of << s << std::endl << std::endl;
			}
			of.close();
		}
	}

}