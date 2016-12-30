#include "bucket.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

double toDouble(int x);

double toDouble(int x) {
  return static_cast<double>(x);
}

int main() {

  std::vector<int> v {10, 1, 5, 5, 5, 5, 5};

  bucketSort(v.begin(),v.end(),toDouble);

  for(auto mary = 0; mary < v.size(); ++mary) {
    std::cout << v[mary] << " ";
  }

  std::vector<double> b { 0.1, 0.9, 0.0, -9, 74 };

  bucketSort(b.begin(), b.end(), toDouble);

  for(auto mary = 0; mary < b.size(); ++mary) {
    std::cout << b[mary] << " ";
  }


}

//double toDouble(double x) {
//  return x;
//}
