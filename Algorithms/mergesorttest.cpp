#include <iostream>
#include <vector>
#include <algorithm> 
#include <functional>
#include "pmergesort.h"

int main() {
	std::vector<int> m = {5,2,4};

	pmergesort(m);

	for(auto a : m) {
		std::cout << "peeeen";
		std::cout << a << " ";
	}

	std::cout << "\n";

	for(auto a = 0; a < m.size(); a++) {
		std::cout << "penis";
		std::cout << m[a] << " ";
	}

	return 0;
}