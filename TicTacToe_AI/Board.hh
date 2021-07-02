#ifndef BORAD_HH
#define BOARD_HH

#include <iostream>
#include <vector>
using namespace std;


class Board {

private:
  //typedef vector<char> mat;
  short val = 3;
  vector<vector<char>> board;//(3, vector<char>(3));
  //static char board[val][val]; //board
  const char cp1 = 'X'; //character player 1
  const char cp2 = 'O'; // character player 2

public:
  
  //Builder
  Board()
    /*Pre: true*/
    /*Post: creates an empty board of 3 by 3*/
  {
    board.resize(val, vector<char>(val, ' '));
  }
  
  Board(const vector<vector<char>>& b)
    /*Pre: b is a reglated board*/
    /*Post: the i.p. is a copy of b*/
  {
    board = b;
  }
  
  //Getters
  bool fear_move(string place) 
    /*Pre: true*/
    /*Post: returns true if the place is alowed, false otherwise.*/
  {
    if (place.size() != 2) return false;
    short j = place[1] - 48;
    short i = place[0] - 48;
    if (i >= 0 and i <= 2 and j >= 0 and j <= 2) {
      if (board[i][j] == ' ') return true;
      else return false;
    }
    else return false;
  }
  
  bool end_game() 
    /*Pre: true*/
    /*Post: returns true if someone won and turns
    player1 to true if p1 is who won and flase otherwise*/
  {
    for (int k = 0; k < 3; ++k) {
      if (board[k][0] == board[k][1] and board[k][1] == board[k][2]) {
        if (board[k][0] != ' ') return true;
      }
    }
    for (int k = 0; k < 3; ++k) {
      if (board[0][k] == board[1][k] and board[1][k] == board[2][k]) {
        if (board[0][k] != ' ') return true;
      }
    }
    if (board[0][0] == board[1][1] and board[1][1] == board[2][2]) {
      if (board[1][1] != ' ') return true;
    }
    if (board[2][0] == board[1][1] and board[1][1] == board[0][2]) {
      if (board[1][1] != ' ') return true;
    }
    return false;
  }
  
  bool if_full()
    /*Pre: true*/
    /*Post: return true if the board is full, false otherwise*/
  {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j  < 3; ++j) {
        if (board[i][j] == ' ') return false;
      }
    }
    return true;
  }
  
  //Setters
  void add_play(string place, bool player1)
    /*Pre: true*/
    /*Post: adds and 'X' on place if player1 = true
    or an 'O' if player1 = false*/
  {
    short j = place[1] - 48; //addr
    short i = place[0] - 48;
    if (player1) board[i][j] = cp1;
    else board[i][j] = cp2;
  }
  
  pair<int,int> random_play() 
    /*Pre: the board is not full*/
    /*Post: adds an 'O' to a random place on the board and returns a pair of int on witch position did it place it*/
  {
      bool cond = true;
      pair<int, int> coord;
      for (int i = 0; i < 3 and cond; ++i) {
          for (int j = 0; j < 3 and cond; ++j) {
              if (board[i][j] == ' ') {
                  board[i][j] = 'O';
                  cond = false;
                  coord.first = i;
                  coord.second = j;
              }
        }
    }
    return coord;
  }
  
  //InputOutput
  
  void print() 
    /*Pre: true*/
    /*Post: the board is visualized on the output standard channel*/
  {
    for (int i = 0; i < 3; ++i) {
        cout << " --- --- ---" << endl;
      for (int j = 0; j  < 3; ++j) {
        cout << "| ";
        cout << board[i][j] << ' ';
      }
      cout << "| ";
      cout << endl;
    }
    cout << " --- --- ---" << endl;
  }
  
  
};


#endif
