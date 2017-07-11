#pragma once

#include <algorithm>

#include "RandomFunctions.h"

namespace VectorFunctions {

	// Get whether the vector contains the specified element
	template<class T>
	bool contains(std::vector<T> &vec, const T& value)
	{
		return std::find(vec.begin(), vec.end(), value) != vec.end();
	}

	// Return a random element in the vector
	// Do not use if the vector has no elements inside
	template<class T> T& randomElement(std::vector<T> &vec)
	{
		/*if (vec.size() == 0) {
		return NULL;
		}*/
		return vec.at(RandomFunctions::randint(0, (int)(vec.size()) - 1));
	}

	// Find the index of the specified element
	// Return the index if found, or -1 if not found
	template <class T> int findIndexUnsorted(std::vector<T> &vec, const T& value) {
		auto it = std::find(vec.begin(), vec.end(), value);
		return (it == vec.end()) ? -1 : (it - vec.begin());
	}

	// Preserve sorted order
	template<class T>
	void removeAtIndexSorted(std::vector<T> &vec, size_t index) {
		vec.erase(vec.begin() + index);
	}

	// Remove the specified element from the vector, if it exists
	// Does not preserve sorted order
	template<class T>
	void removeFromUnsorted(std::vector<T> &vec, T &element) {
		auto it = std::find(vec.begin(), vec.end(), element);

		if (it != vec.end()) {
			std::swap(*it, vec.back());
			vec.pop_back();
		}
	}

	// Does not preserve sorted order
	template<class T>
	void removeAtIndexUnsorted(std::vector<T> &vec, int index) {
		vec[i] = std::move(vec.back());
		vec.pop_back();
	}

	// Preserves sorted order
	template<class T>
	void removeFromSorted(std::vector<T> &vec, T &element) {
		auto it = std::find(vec.begin(), vec.end(), element);
		if (it != vec.end()) {
			vec.erase(it);
		}
	}

}
