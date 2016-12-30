#ifndef PMERGESORT
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
/*
template<typename T>
std::vector<T> merge(std::vector<T> &left, std::vector<T> &right) {
	std::vector<T> result;
	auto left_it = 0;
	auto right_it = 0;

	while((left_it < left.size()) && (right_it < right.size())) {
		if(left[left_it] < right[right_it]) {
			result.push_back(left[left_it]);
			left_it++;
		} else {
			result.push_back(right[right_it]);
			right_it++;
		}
	}

	while(left_it < left.size()) {
		result.push_back(left[left_it]);
		left_it++;
	}

	while(right_it < right.size()) {
		result.push_back(right[right_it]);
		right_it++;
	}

	return result;
}

template<typename T>
std::vector<T> mergesort(std::vector<T> &v) {
	if(v.size() == 1) {
		return v;
	}

	auto middle = v.begin();

	middle += v.size()/2;

	std::vector<T> left(v.begin(), middle);
	std::vector<T> right(middle, v.end());

	left = mergesort(left);
	right = mergesort(right);

	return merge(left, right);
} */

template<typename T>
void merge(std::vector<T> &v, int l, int m, int r) {
	int k;
	int n1 = m - l + 1;
	int n2 = r - m;

	std::vector<T> left;
	std::vector<T> right;

	for(auto i = 0; i < n1; i++) {
		left[i] = v[i + 1];
	}
	for(auto j = 0; j < n2; j++) {
		right[j] = v[m + j + 1];
	}

	
}

template<typename T>
void pmergesort(std::vector<T> &v) {
	mergesort(v);
    //std::sort(v.begin(),v.end());

}

#endif