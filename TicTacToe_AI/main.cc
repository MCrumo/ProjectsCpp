#include "Board.hh"


int main() {
    bool playagain = true;
    while (playagain) {
        bool ia = false;
        bool cond = true;
        string p1, p2, r1;
        string q1 = "Will Player2 be an A.I. ?";
        string q2 = "y/n ";
        
        cout << endl << q1 << endl << q2;
        while (cond and cin >> r1) {
            if (r1 == "y") {
                ia = true;
                cond = false;
            }
            else if (r1 == "n") cond = false;
            else cout << endl << q2;
        }
        
        Board board;
        int cont = 0;
        if (ia) cont = cont * 2; //useless
        bool endgame = false;
        board.print();
        while (not board.if_full() and not endgame) {
            string place = "44";
            if (cont%2 == 0) { //player1
                while(not board.fear_move(place)) {
                    cout << endl << "P1: ";
                    cin >> place;
                }
                board.add_play(place, true);
                board.print();
                if (board.end_game()) {
                    endgame = true;
                    cout << "Player 1 has won!" << endl;
                }
            }
            else if (not ia){ //player2
                while(not board.fear_move(place)) {
                    cout << endl << "P2: ";
                    cin >> place;
                }
                board.add_play(place, false);
                board.print();
                if (board.end_game()) {
                    endgame = true;
                    cout << "Player 2 has won!" << endl;
                }
            }
            else { //I.A. tourn
                pair <int, int> coord = board.random_play();
                cout << endl << "P2: " << coord.first << coord.second << endl;
                board.print();
                if (board.end_game()) {
                    endgame = true;
                    cout << "Player 2, aka the I.A. has won!" << endl;
                }
            }
            ++cont;
        }
        string ans = "answ";
        cout << "Play again?" << endl << q2;
        while (ans != "n" and ans != "y") {
            cin >> ans;
            cout << " ";
        }
        if (ans == "n") playagain = false;
        
    } 
}
