#include "DirectoryLoad.h"

#include <filesystem>
#include <sstream>
#include <iostream>

namespace fs = std::experimental::filesystem;
namespace DirectoryLoad
{

	std::vector<std::string> getDirectoryContents(std::string dir, std::string extension, bool nameOnly) {

		std::vector<std::string> list;

		for (auto &file : fs::recursive_directory_iterator(dir)) {

			// Get file name
			std::stringstream ss;
			ss << file;

			// Ignore the base directory
			std::string name = ss.str().substr(dir.size());

			// if adding folders instead of files
			if (extension.size() == 0 || extension.at(0) != '.') {
				if (fs::is_directory(file))
					list.push_back(nameOnly ? name : ss.str());
				continue;
			}

			size_t index = name.rfind(extension);
			if (index == std::string::npos)
				continue;

			// Extension matches, so add the file
			if (name.substr(index) == extension) {
				if (nameOnly)
					list.push_back(name.substr(0, index));	// name without the extension
				else
					list.push_back(ss.str());	// directory + file name + extension
			}

		}

		return list;
	}
}
