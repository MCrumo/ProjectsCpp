#ifndef BORAD_HH
#define BOARD_HH

class Board {

private:
  const int val = 3: 
  char board[val][val];

public:
  
  //Builder
  Board()
    /*Pre: true*/
    /*Post: creates an empty board of 3 by 3*/
  {
    board = {
     { ' ', ' ', ' ' },
     { ' ', ' ', ' ' },
     { ' ', ' ', ' ' }
    };
    char cp1 = 'X'; //character player 1
    char cp2 = 'O'; // character player 2
  }
  
  Board(const Board& b)
    /*Pre: b is a reglated board*/
    /*Post: the i.p. is a copy of b*/
  {
    board = b;
  }
  
  //Getters
  bool fear_move(string place) 
    /*Pre: true*/
    /*Post: returns ture if the place is alowed, false otherwise.*/
  {
    short i = place[1] - 48;
    short j = place[0] - 48;
    if (i >= 0 and i <= 2 and j >= 0 and j <= 2) {
      if (board[i][j] == ' ') return ture;
      else return false;
    }
    else return false;
  }
  
  bool end_game(bool& player1) 
    /*Pre: true*/
    /*Post: returns ture if someone won and turns
    player1 to true if p1 is who won and flase otherwise*/
  {
    player1 = false;
    for (int k = 0; k < 3; ++k) {
      if (board[k][0] == board[k][1] and board[k][1] == board[k][2]) {
        if (board[k][0] == cp1) player1 = true;
        return true;
      }
    }
    for (int k = 0; k < 3; ++k) {
      if (board[0][k] == board[1][k] and board[1][k] == board[2][k]) {
        if (board[0][k] == cp1) player1 = true;
        return true;
      }
    }
    if (board[0][0] == board[1][1] and board[1][1] == board[2][2]) {
      if (board[0][k] == cp1) player1 = true;
      return true;
    }
    if (board[2][0] == board[1][1] and board[1][1] == board[0][2]) {
      if (board[0][k] == cp1) player1 = true;
      return true;
    }
    return false;
  }
  
  bool full_board()
    /*Pre: true*/
    /*Post: return true if the board is full, false otherwise*/
  {
    for (int i = 0
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
  }
  
  //Setters
  bool add_play(string place, bool player1)
    /*Pre: true*/
    /*Post: adds and 'X' on place if player1 = true
    or an 'O' if player1 = false*/
  {
    short i = place[1] - 48;
    short j = place[0] - 48;
    if (player1) board[i][j] = cp1;
    else board[i][j] = cp2;
  }
  
  
}


#endif
