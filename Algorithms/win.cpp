#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <utility>
#include <map>

using namespace std;

bool jumpDown(pair<int,int> cords, vector<vector<bool>> &board, map<string,bool> &memories);
bool jumpUp(pair<int,int> cords, vector<vector<bool>> &board, map<string,bool> &memories);
bool jumpLeft(pair<int,int> cords, vector<vector<bool>> &board, map<string,bool> &memories);
bool jumpRight(pair<int,int> cords, vector<vector<bool>> &board, map<string,bool> &memories);
bool canWin(const vector<vector<bool>> &board);
bool Winning(const vector<vector<bool>> &board, map<string,bool> &memories);


bool jumpDown(pair<int,int> cords, vector<vector<bool>> &board, map<string,bool> &memories) {
  //cout << "Jumped Down!\n";
  int a = cords.first;
  int b = cords.second;
  int size = board[0].size();
  if((b < (size - 2)) && board[a][b+1] && board[a][b+2]) {
    //cout << "Jumped Down!\n";
    board[a][b+1] = false;
    board[a][b+2] = false;
    board[a][b] = true;
    bool solved = Winning(board, memories);
    board[a][b+1] = true;
    board[a][b+2] = true;
    board[a][b] = false;
    return solved;
  }
  return false;
}

bool jumpUp(pair<int,int> cords, vector<vector<bool>> &board, map<string,bool> &memories) {
  //cout << "Jumped Up!\n";
  int a = cords.first;
  int b = cords.second;
  int size = board[0].size();
  //cout << "b: " << cords.second << "\n";
  //cout << "Size of board: " << board[0].size() << "\n";
  if((b > 1) && board[a][b-1] && board[a][b-2]) {
    //cout << "Jumped Up!\n";
    board[a][b-1] = false;
    board[a][b-2] = false;
    board[a][b] = true;
    bool solved = Winning(board, memories);
    board[a][b-1] = true;
    board[a][b-2] = true;
    board[a][b] = false;
    return solved;
  }
  return false;
}

bool jumpLeft(pair<int,int> cords, vector<vector<bool>> &board, map<string,bool> &memories) {
  //cout << "Jumped Left!\n";
  int a = cords.first;
  int b = cords.second;
  int size = board.size();
  if((a > 1) && board[a-1][b] && board[a-2][b]) {
    //cout << "Jumped Left!\n";
    board[a-1][b] = false;
    board[a-2][b] = false;
    board[a][b] = true;
    bool solved = Winning(board, memories);
    board[a-1][b] = true;
    board[a-2][b] = true;
    board[a][b] = false;
    return solved;
  }
  return false;
}

bool jumpRight(pair<int,int> cords, vector<vector<bool>> &board, map<string,bool> &memories) {
  //cout << "Jumped Right!\n";
  int a = cords.first;
  int b = cords.second;
  int size = board.size();
  if((a < (size -2)) && board[a+1][b] && board[a+2][b]) {
    //cout << "Jumped Right!\n";
    board[a+1][b] = false;
    board[a+2][b] = false;
    board[a][b] = true;
    bool solved = Winning(board, memories);
    board[a+1][b] = true;
    board[a+2][b] = true;
    board[a][b] = false;
    return solved;
  }
  return false;
}

bool Winning(const vector<vector<bool>> &board, map<string,bool> &memories) {

  bool won = false;

  auto c = board.size();

  auto r = board[0].size();

  vector<vector<bool>> temp(c, vector<bool>(r, false));

  for(auto a = 0; a < c; ++a) {
    for(auto b = 0; b < r; ++b) {
      temp[a][b] = board[a][b];
    }
  }

  vector<pair<int,int>> emptySlots;

  for(auto a = 0; a < c; ++a) {
    for(auto b = 0; b < r; ++b) {
      if(board[a][b] == false) {
        emptySlots.push_back(std::make_pair(a,b));
        //cout << "Empty at: (" << a << ", " << b << ")\n";
      } //else {
        //cout << "Filled at: (" << a << ", " << b << ")\n";
      //}
    }
  }

  if(((r*c) - emptySlots.size()) == 1) {
    //cout << "WINNNING";
    //return true;
    won = true;
  }

  string bin = "";

  for(auto a = 0; a < c; ++a) {
    for(auto b = 0; b < r; ++b) {
      bin += board[a][b];
    }
  }

  //cout << bin << "\n";

  auto it = memories.find(bin);
  if(it != memories.end()) {
    for(auto a = memories.begin(); a !=  memories.end(); ++a) {
      if(a -> second == true) {
        won = true; //return true;
      //} //else {
       // return false;
      }
    }
  }

  for(auto a = 0; a < emptySlots.size(); ++a) {
    bool up = jumpUp(emptySlots[a], temp, memories);
    bool down = jumpDown(emptySlots[a], temp, memories);
    bool left = jumpLeft(emptySlots[a], temp, memories);
    bool right = jumpRight(emptySlots[a], temp, memories);

    won = up || down || left || right;
  }

  //return won;
  
  memories.insert(make_pair(bin, won));

  cout << "This case was: " << won << "\n";

  return won;

  //cout << memories.size();

  //cout << "Winning status: " << won;

  /*for(auto a = memories.begin(); a !=  memories.end(); ++a) {
      //cout << "Looking through memories\n";
      if(a -> second == true) {
        cout << (a -> second);
        return true; //true
      }
  }*/
  //cout << "its false";
  //return false;
}

bool canWin(const vector<vector<bool>> &board) {
  map<string,bool> memories;
  auto ans = Winning(board,memories);
  cout << "Result: " << ans << "\n";
  return ans;
}
/*
int main() {
  
  vector<vector<bool>> mary;
  for(int i = 0; i < 3; ++i) {
    vector<bool> temp;
    mary.push_back(temp);
  }
  mary[0].push_back(false);
  mary[0].push_back(false);
  mary[0].push_back(false);
  mary[1].push_back(true);
  mary[1].push_back(true);
  mary[1].push_back(false);
  mary[2].push_back(false);
  mary[2].push_back(false);
  mary[2].push_back(false);

  cout << "Mary is: " << mary[0].size() << "\n";
  cout << "Found: " << canWin(mary);
  return 0;
}*/
