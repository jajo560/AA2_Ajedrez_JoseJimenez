#pragma once

class Piece {
private:
    char symbol;

public:
    int x, y;

    Piece(char symbol = '*', int x = 0, int y = 0);
    char GetSymbol();

};