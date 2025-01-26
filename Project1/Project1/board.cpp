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

bool Board::MovePiece(std::string from, std::string to, bool isWhiteTurn) {
    int fromX = 8 - (from[1] - '0');
    int fromY = from[0] - 'a';
    int toX = 8 - (to[1] - '0');
    int toY = to[0] - 'a';

    if (fromX < 0 || fromX >= 8 || fromY < 0 || fromY >= 8 ||
        toX < 0 || toX >= 8 || toY < 0 || toY >= 8) {
        return false;
    }

    Piece& piece = board[fromX][fromY];
    if (!piece.IsValidMove(toX, toY, board, isWhiteTurn)) {
        return false;
    }

    piece.x = toX;
    piece.y = toY;

    board[toX][toY] = piece;
    board[fromX][fromY] = Piece('*', fromX, fromY);

    return true;
}

bool Board::IsCheckmate(bool isWhiteTurn) {
    char king = isWhiteTurn ? 'k' : 'K';
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].GetSymbol() == king) {
                return false;
            }
        }
    }
    return true;
}
