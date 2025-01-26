#include "board.h"
#include <iostream>


using namespace std;

Board::Board() {
    board.resize(8, vector<Piece>(8));
}

void Board::Initialize() {
    string startMap[] = {
        "thbqkbht",
        "pppppppp",
        "********",
        "********",
        "********",
        "********",
        "PPPPPPPP",
        "THBQKBHT"
    };

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = Piece(startMap[i][j], i, j);
        }
    }
}

void Board::PrintBoard() {
    cout << "  a b c d e f g h" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j].GetSymbol() << " ";
        }
        cout << 8 - i << endl;
    }
    cout << "  a b c d e f g h" << endl;
}