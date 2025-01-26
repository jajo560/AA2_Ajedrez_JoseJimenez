#include "piece.h"

Piece::Piece(char symbol, int x, int y) : symbol(symbol), x(x), y(y) {}

char Piece::GetSymbol() {
    return symbol;
}

void Piece::SetPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

bool Piece::IsValidMove(int toX, int toY, std::vector<std::vector<Piece>>& board, bool isWhiteTurn) {
    if ((isWhiteTurn && (symbol >= 'a' && symbol <= 'z')) || (!isWhiteTurn && (symbol >= 'A' && symbol <= 'Z'))) {
        return false;
    }

    if ((isWhiteTurn && (board[toX][toY].GetSymbol() >= 'A' && board[toX][toY].GetSymbol() <= 'Z')) ||
        (!isWhiteTurn && (board[toX][toY].GetSymbol() >= 'a' && board[toX][toY].GetSymbol() <= 'z'))) {
        return false;
    }

    int xDiff;
    if (toX > x) {
        xDiff = toX - x;
    }
    else {
        xDiff = x - toX;
    }

    int yDiff;
    if (toY > y) {
        yDiff = toY - y;
    }
    else {
        yDiff = y - toY;
    }

    switch (symbol) {
    case 'P':
        if (xDiff == 1 && yDiff == 0 && board[toX][toY].GetSymbol() == '*') {
            return true;
        }
        if (x == 6 && xDiff == 2 && yDiff == 0 && board[toX][toY].GetSymbol() == '*') {
            return true;
        }
        if (xDiff == 1 && yDiff == 1 && board[toX][toY].GetSymbol() >= 'a' && board[toX][toY].GetSymbol() <= 'z') {
            return true;
        }
        break;

    case 'p':
        if (xDiff == 1 && yDiff == 0 && board[toX][toY].GetSymbol() == '*') {
            return true;
        }
        if (x == 1 && xDiff == 2 && yDiff == 0 && board[toX][toY].GetSymbol() == '*') {
            return true;
        }
        if (xDiff == 1 && yDiff == 1 && board[toX][toY].GetSymbol() >= 'A' && board[toX][toY].GetSymbol() <= 'Z') {
            return true;
        }
        break;

    case 'T':
    case 't':
        if (xDiff == 0 || yDiff == 0) {
            int xDir = (toX > x) ? 1 : (toX < x ? -1 : 0);
            int yDir = (toY > y) ? 1 : (toY < y ? -1 : 0);
            for (int i = 1; i < (xDiff > yDiff ? xDiff : yDiff); ++i) {
                if (board[x + i * xDir][y + i * yDir].GetSymbol() != '*') {
                    return false;
                }
            }
            return true;
        }
        break;

    case 'H':
    case 'h':
        if ((xDiff == 2 && yDiff == 1) || (xDiff == 1 && yDiff == 2)) {
            return true;
        }
        break;

    case 'B':
    case 'b':
        if (xDiff == yDiff) {
            int xDiff = (toX > x) ? 1 : -1;
            int colDir = (toY > y) ? 1 : -1;
            for (int i = 1; i < xDiff; ++i) {
                if (board[x + i * xDiff][y + i * colDir].GetSymbol() != '*') {
                    return false;
                }
            }
            return true;
        }
        break;

    case 'Q':
    case 'q':
        if (xDiff == yDiff || xDiff == 0 || yDiff == 0) {
            int xDir = (xDiff == 0) ? 0 : (toX > x ? 1 : -1);
            int yDir = (yDiff == 0) ? 0 : (toY > y ? 1 : -1);
            for (int i = 1; i < (xDiff > xDiff ? xDiff : xDiff); ++i) {
                if (board[x + i * xDir][y + i * yDir].GetSymbol() != '*') {
                    return false;
                }
            }
            return true;
        }
        break;

    case 'K':
    case 'k':
        if (xDiff <= 1 && yDiff <= 1) {
            return true;
        }
        break;
    }

    return false;
}
