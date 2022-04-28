#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> COL;
typedef vector<COL> MAT;

int totalSol = 0;

void initialInfo(){
    cout<<"\nWrite the sudoku board\n";
    cout<<"Enter first the rows and cols and then all the board numbers (spaces with '-')\n\n";
}

int getSize(){
    int x;
    cin >> x;
    return x;
}

void readBoard(MAT& board){
    char c;
    for (int i = 0; i < board.size(); ++i){
        for (int j = 0; j < board[0].size(); ++j){
            cin >> c;
            if (c > 48 and c <= 57) board[i][j] = c-48;
            else board[i][j] = 0;
        }
    }
}

void printBoard(const MAT& board){
    int x = board.size();
    for (int i = 0; i <= x; ++i){
        if (i%3 == 0){
            cout << " +";
            for (int m = 0; m < x/3; ++m) cout <<"-------+";
            cout << endl;
        }
        for (int j = 0; j <= x && i != x; ++j){
            if (j == 0 or j%3 == 0 and j != 1) cout << " |";
            if (j != x){ 
                cout << ' ';
                if (board[i][j] > 0) cout << board[i][j];
                else cout << ' ';
            }
        }
        cout << endl;
    }
}

bool valid(int f, int c, int num, const MAT& board){
    int s = board.size();
    for (int j = 0; j < s; ++j){
        if (j != c and board[f][j] == num) return false;
    }
    for (int i = 0; i < s; ++i){
        if (i != f and board[i][c] == num) return false;
    }
    int f0 = (f/3) * 3;
    int c0 = (c/3) * 3;
    for (int m = 0; m < 3; ++m){
        for (int n = 0; n < 3; ++n){
            int ff = f0+m;
            int cc = c0+n;
            if ((ff != f and cc != c) and board[ff][cc] == num) return false;
        }
    }
    return true;
}

void solveBoard(MAT& board){
    int s = board.size();
    for (int i = 0; i < s; ++i){
        for (int j = 0; j < s; ++j){
            if (board[i][j] < 1){
                for (int k = 1; k <= 9; ++k){
                    if (valid(i,j,k,board)) {
                        board[i][j] = k;
                        solveBoard(board);
                        board[i][j] = 0;
                    }
                }
                return;
            }
        }
    }
    ++totalSol;
    printBoard(board);
}

bool validSudoku(const MAT& board){
    int s = board.size();
    for (int i = 0; i < s; ++i){
        for (int j = 0; j < s; ++j){
            if (board[i][j] > 0 and not valid(i,j,board[i][j],board)) return false;
        }
    }
    return true;
}

void analize(int totalSol){
    if (totalSol == 0) cout << "This SUDOKU has NO solution\n";
    else cout << "This SUDOKU has " << totalSol << " solution/s\n";
}

int main(){
    initialInfo();
    int x = getSize();
    MAT board(x, COL(x));
    readBoard(board);
    printBoard(board);
    if (validSudoku(board)) solveBoard(board);
    analize(totalSol);
}
