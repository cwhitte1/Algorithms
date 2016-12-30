#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <regex>
#include <iterator>
#include <sstream>

using namespace std;

vector<string> splitMaster(const string &s, char f, vector<string> &elems) {
  stringstream ss(s);
  string temp;

  while(getline(ss, temp, f)) {
    elems.push_back(temp);
  }
  
  return elems;
}

tuple<vector<int>,vector<int>> chemBalance(const string &equ) {

  auto pos = equ.find('=');
  auto left = equ.substr(0, pos);
  auto right = equ.substr((pos + 1), equ.size() - 1);

  vector<string> chemicals;
  string segment;

  splitMaster(left, '+', chemicals);
  auto numLeft = chemicals.size();
  splitMaster(right, '+', chemicals);

  for(a : chemicals) {
  cout << "Chemical Found: " << a << "\n";
  }

  vector<vector<int>> matrix;
  vector<string> elements;

  for(auto a = 0; a < numLeft; a++) {
    for(auto b = 0; b < chemicals[a].length(); b++) {
      if(isdigit(chemicals[a][b+1]) &&
       find(elements.begin(), elements.end(),chemicals[a][b])==elements.end()) {
        string target = "";
        target += chemicals[a][b];
        elements.push_back(target);
      } else if(islower(chemicals[a][b+1])) {
          string target = "";
          target += chemicals[a].substr(b,b+2);
          if(find(elements.begin(), elements.end(),target)==elements.end()) {
          elements.push_back(target);
        }
      }
    }
  }

  /*
  for(auto a = 0; a < numLeft; a++) {
    for(auto b = 0; b < chemicals[a].length(); b++) {
      if(isdigit(chemicals[a][b + 1]) && 
       find(elements.begin(), elements.end(),chemicals[a][b])==elements.end()) {
        cout << "Element being worked on: " << chemicals[a][b] << "\n";
        elements.push_back(chemicals[a][b]);
        auto temp = chemicals[a][b];
        vector<int> line;
        line.push_back(chemicals[a][b+1]);
        for(auto c = 0; c < chemicals; c++) {
          if(chemicals
          
        }
      }
    }
  } */

  vector<int> empty;
  return make_tuple(empty,empty);
}

int main() {
  auto chem = "CiO4+O2=H2O+CO2";
  chemBalance(chem);
  return 0;
} 
