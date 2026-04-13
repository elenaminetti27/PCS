#pragma once
#include <vector>

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
	if (vec.size() <= 1) {
		return true;
	}
	for (int i=1; i < vec.size(); i++) {
		if (vec[i] < vec[i-1]) {
			return false;
		}
	}
	return true;
}

	
