#pragma once

#include <memory>
#include <vector>

namespace UniquePtrFunctions
{

	// Move the unique_ptr at the specified index out of the vector
	// The caller gains ownership of the pointer
	// return the pointer
	template <class T> std::unique_ptr<T> moveOutOfVector(std::vector<std::unique_ptr<T>> &vec, int index) {
		const auto it = vec.begin() + index;
		std::unique_ptr<T> item = std::move(*it);
		vec.erase(it);
		return item;
	}

	// Move the unique_ptr out of the vector
	// The caller gains ownership of the pointer
	// return the pointer
	template <class T> std::unique_ptr<T> moveOutOfVector(std::vector<std::unique_ptr<T>> &vec, std::unique_ptr<T> &ptr) {
		const auto it = std::find(vec.begin(), vec.end(), ptr);
		if (it != vec.end()) {
			std::unique_ptr<T> item = std::move(*it);
			vec.erase(it);
			return item;
		}
		return NULL;
	}

}
