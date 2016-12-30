#include "floydwarshall.cpp"
#include <vector>
#include <tuple>
#include <iostream>
#include <utility>

using namespace std;

int main() {

  // create testing vector(s)

  cout << "\n";

  vector<vector<int>> tester { { 1, 369, 1000000001},
                               { 9, 1, 789 },
                               { 1, 2, 88 }};
  
  // manually change values for testing

  // print vector(s)
  
  for(int i = 0; i < 3; i++) {
    for(int b = 0; b < 3; b++) {
      cout << tester[i][b] << " ";
    }
    cout << "\n";
  }

  cout << "\n";

  // call crossCountryChallenge for testing
  
  tuple<vector<vector<int>>, vector<vector<int>>> tested; 

  tested = crossCountryChallenge(tester);

  // print tester results

  vector<vector<int>> shortestPaths;
  shortestPaths = get<0>(tested); // extract shortest paths

  auto h = shortestPaths.size();

  for(int a = 0; a < h; a++) {
    for(int b = 0; b < shortestPaths[a].size(); b++) {
      cout << shortestPaths[a][b] << " ";
    }
    cout << "\n";
  }

  cout << "\n";

  vector<vector<int>> routes;
  routes = get<1>(tested); // extract routes

  auto g = routes.size();

  for(int a = 0; a < g; a++) {
    for(int b = 0; b < routes[a].size(); b++) {
      cout << routes[a][b] << " ";
    }
    cout << "\n";
  }

  cout << "\n";

  return 0;
}
