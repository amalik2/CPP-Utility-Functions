#pragma once

#include <string>
#include <vector>

namespace DirectoryLoad {
	// Get the names of all files (or folders) in the specified directory (and subdirectories)
	// if extension does not start with ".", then only folders will be returned. If extension starts with ".", all files returned must have the extension (ex: ".txt")
	// if nameOnly is set to true, only the names of matching files are returned (no directory and extension)
	std::vector<std::string> getDirectoryContents(std::string dir, std::string extension, bool nameOnly);
}
