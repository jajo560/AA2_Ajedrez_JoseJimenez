#include "piece.h"

Piece::Piece(char symbol, int x, int y) : symbol(symbol), x(x), y(y) {}

char Piece::GetSymbol() {
    return symbol;
}

void Piece::SetPosition(int newX, int newY) {
    x = newX;
    y = newY;
}