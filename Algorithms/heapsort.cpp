#include "heapsort.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
  std::vector<int> v { 5 , 4 , 9 , 6 , 8 , 99, 1, 2};
  //std::vector<int> copy(v.begin(),v.end());
  //std::cout << copy[1];
  heapsort(v.begin(),v.end());

  for(auto mary = 0; mary < v.size(); ++mary) {
    std::cout << v[mary] << " ";
  }

  std::vector<std::string> love { "sos", "ab", "xxx" };

  heapsort(love.begin(), love.end());

  for(auto mary = 0; mary < love.size(); ++mary) {
    std::cout << love[mary] << " ";
  }

  std::vector<char> gg { 'b' , 'a', 'A', 'f' };
  heapsort(gg.begin(), gg.end());

  for(auto mary = 0; mary < gg.size(); ++mary) {
    std::cout << gg[mary] << " ";
  }
  return 0;
}
