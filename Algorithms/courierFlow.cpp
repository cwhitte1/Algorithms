#include<cstdio>
#include<queue>
#include<string>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>

#define MAXCITIES 1001
#define INT_MAX 2147483646
#define SOURCE -1

using namespace std;

//int caps[MAXCITIES][MAXCITIES];
//int passed[MAXCITIES][MAXCITIES];
//vector<int> graph[MAXCITIES];
//int parents[MAXCITIES];
//int current[MAXCITIES];

tuple<int,vector<int>> breadthFirstSearch(int source, int sink, vector<vector<int>> &capacities, vector<vector<int>> &flows, vector<int> &current) { //, vector<vector<int>> graph) {

  queue<int> q;
  vector<int> parent(capacities[0].size(), -1);
  
  //q.push(source);

  parent[source] = -2;

  /*for(a : parent) {
    cout << a;
  }*/

  current[source] = INT_MAX;

  q.push(source);

  while(!q.empty()) {
    //cout << "while\n";
    int currentCity = q.front();
    q.pop();
    for(int i = 0; i < capacities[currentCity].size(); i++) { //to fix < graph
      //cout << "hello\n";
      if((capacities[currentCity][i] - flows[currentCity][i]) > 0 && (parent[i] == -1)){
        //cout << "hello again\n";
        parent[i] = currentCity;
        current[i] = min(current[currentCity], capacities[currentCity][i] - flows[currentCity][i]);
        if(i != sink) {
          //cout << "i : " << i << " sink: " << sink << "\n";
          //cout<< "Current[i] : " << current[i] << "\n";
          q.push(i);
        } else {
          return make_tuple(current[sink], parent);
        }
      }
    }
  }
  return make_tuple(0, parent);
}






  //int to = capacities[currentCity][i];
      /*if(parent[to] == -1) {
        if(capacities[currentCity][to] != 0) {
          parent[to] = currentCity;
          current[to] = min(current[currentCity], capacities[currentCity][to] - pred[currentCity][to]);
          if(to == sink) {
            return current[sink];
          }
          q.push(to);
       }
      }
    }
  }
  return 0;
}*/

tuple<int,vector<vector<int>>> edmondsKarp(int source, int sink, vector<vector<int>> &capacities, vector<vector<int>> &flows, vector<int> &current) {

  int maxFlow = 0;
  
  while(true) {
    auto capT = breadthFirstSearch(source, sink, capacities, flows, current);
    int capacityFound = get<0>(capT);
    auto parentVec = get<1>(capT);
    if(capacityFound == 0) {
      //cout << "flow found to be 0, broke out of while loop\n";
      break;
    }

    //cout << "flow was not 0\n";

    maxFlow += capacityFound;
    auto v = sink;

    while(v != source) {
      auto u = parentVec[v];
      flows[u][v] = flows[u][v] + capacityFound; //[previousCity][currentCity] += flow;
      flows[v][u] = flows[v][u] - capacityFound; //passed[currentCity][previousCity] -= flow;

      v = u;
    }
  }

  return make_tuple(maxFlow, flows);
}


vector<tuple<int,int,int>> courierLoads(const vector<int> &orders, const vector<tuple<int,int,int>> &capacities) {

  auto orderSize = orders.size() + 1;
  auto capSize = capacities.size();

  vector<vector<int>> graph(orderSize, vector<int>(orderSize)); // capacities
  vector<vector<int>> flows(orderSize, vector<int>(orderSize)); // flows set to 0
  vector<int> current(orderSize);
  //vector<int> pred(capSize);
  //vector<vector<int>> pred(capSize, vector<int>(capSize));
  //build graph of capacities
  for(int a = 0; a < capSize; a++) {
    auto t = capacities[a];
    //cout << get<0>(t) << " ";
    //cout << get<1>(t) << " ";
    //cout << get<2>(t) << "\n";
    graph[get<0>(t)][get<1>(t)] = get<2>(t); 
  }

  //initialize all flows to 0
  for(int a = 0; a < orderSize; a++) {
    for(int b = 0; b < orderSize; b++) {
      flows[a][b] = 0;
    }
  }

  for(int a = 0; a < orders.size(); a++) {
    graph[a][orderSize - 1] = orders[a];
  }
  
  //print out graph for testing
  /* 
  for(int a = 0; a < capSize; a++) {
    //cout << "starting b" << "\n";
    for(int b = 0; b < capSize; b++) {
      //cout << "in loop\n";
      cout << graph[a][b] << " ";
      //cout << "leaving loop\n";
    }
    cout << "\n";
  } */

  //cout << "processing\n\n";

  auto found = edmondsKarp(0,orders.size(), graph, flows, current);

  auto maxFlowFound = get<0>(found);
  auto flowsFound = get<1>(found);

  int orderSum = 0;
  for(int a = 0; a < orders.size(); a++) {
    orderSum += orders[a];
  }

  //cout << "Order sum: " << orderSum << "\n";

  vector<tuple<int,int,int>> returnStuff;

  //cout << "Max flow found: " << maxFlowFound << "\n";

  if(maxFlowFound != orderSum) {
    return returnStuff;
  } else {
   for(int a = 0; a < capacities.size(); a++) {
    auto temp = capacities[a];
    auto start = get<0>(temp);
    //cout << start << " ";
    auto end = get<1>(temp);
    //cout << end << " ";
    auto package = make_tuple(start,end,flowsFound[start][end]);
    //cout << flowsFound[start][end] << "\n";
    returnStuff.push_back(package);
    }
  }
  return returnStuff;    
}
/*
int main () {
  //manually change the numbers
  vector<int> orders = {0,1,2,3};
  vector<tuple<int,int,int>> cities = {
    make_tuple(0,0,0),make_tuple(0,2,3),
    make_tuple(1,2,8),make_tuple(2,3,4)
  };
  vector<tuple<int,int,int>> found = courierLoads(orders,cities);

  //for(int a = 0; a < found.size(); a++) {
  //  auto f = found[a];
    //cout << "hey";
    //cout << get<0>(f) << " ";
    //cout << get<1>(f) << " ";
    //cout << get<2>(f) << "\n";
  //}
  //similar to lewis test
  sort(found.begin(),found.end(),
    [] (const tuple<int,int,int> &t1,const tuple<int,int,int> &t2)
    { return get<0>(t1) < get<0>(t2) || (get<0>(t1)==get<0>(t2) && get<1>(t1) < get<1>(t2)); });
  vector<tuple<int,int,int>> a1 = {
    make_tuple(0,1,3),make_tuple(0,2,3),make_tuple(1,2,2),make_tuple(2,3,3)
  };
  if(found==a1) {
    cout << "Failed" << endl;
  return -1;
  }
  cout << "work bitch";
  return 0;
}*/
