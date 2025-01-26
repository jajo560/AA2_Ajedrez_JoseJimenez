#include "piece.h"

Piece::Piece(char symbol, int x, int y) : symbol(symbol), x(x), y(y) {}

char Piece::GetSymbol() {
    return symbol;
}