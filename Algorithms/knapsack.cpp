#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <utility>

using namespace std;

pair<double,vector<int>> knapsack(int weightLimit, const vector<int> &weights, const vector<double> &values);

pair<double,vector<int>> knapsack(int weightLimit, const vector<int> &weights, const vector<double> &values) {

  vector<vector<double>> table(weights.size() + 1,vector<double>(weightLimit + 1));
  
  for(auto i = 0; i <= weights.size(); ++i) {
    for(auto v = 0; v <= weightLimit; ++v) {
      if(i == 0) {
        table[i][v] = 0;
      } else if(weights[i-1] <= v) {
        table[i][v] = std::max(values[i-1] + table[i-1][v-weights[i-1]], table[i-1][v]);
      } else {
        table[i][v] = table[i-1][v];
      }
    }
  }

  vector<int> indexList;

  int counter = weights.size();
  int W = weightLimit;

  while(counter != 0) {
    auto compItems = table[counter][W] - table[counter - 1][W];
    if(compItems == 0) {
      --counter;
    } else {
      indexList.push_back(counter - 1);
      W -= weights[counter-1];
      --counter;
    }
  }
  
  return make_pair(table[weights.size()][weightLimit],indexList);
}
/*
int main() {
  vector<int> correct = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  vector<double> solution = {60, 100, 120, 140, 160, 180, 190, 200, 210};

  cout << knapsack(50, correct, solution).first << " ";

  auto temp = knapsack(50, correct, solution).second;

  for(auto i = 0; i < temp.size(); ++i) {
    cout << temp[i] << " ";
  }

  return 0;
} */


