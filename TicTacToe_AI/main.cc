#include "board.hh"


int main() {
    bool ia = false;
    bool cond = true;
    string p1, p2, r1;
    string q1 = "Will Player2 be an A.I. ?";
    string q2 = "y/n";
    
    cout << q1 << endl << q2 << endl;
    while (cond and cin >> r1) {
        if (r1 == "y") {
            ia = true;
            cond = false;
        }
        else if (r1 == "n") cond = false;
        else cout << q2 << endl;
    }
    
    Board board;
    int cont = 0;
    if (ia) cont = cont * 2; //useless
    bool endgame = false;
    while (not board.if_full() and not endgame) {
        if (true /* not ia */) {
            string place = "44";
            bool p1win;
            if (cont%2 == 0) { //player1
                while(not board.fear_move(place)) {
                    cout << endl << "P1: ";
                    cin >> place;
                }
                board.add_play(place, true);
                board.print();
                if (board.end_game(p1win)) {
                    endgame = true;
                    cout << "Player 1 has won!" << endl;
                }
            }
            else { //player2
                while(not board.fear_move(place)) {
                    cout << endl << "P2: ";
                    cin >> place;
                }
                board.add_play(place, false);
                board.print();
                if (board.end_game(p1win)) {
                    endgame = true;
                    cout << "Player 2 has won!" << endl;
                }
            }
        }
        ++cont;
    }
}
