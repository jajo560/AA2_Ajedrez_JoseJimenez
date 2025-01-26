#pragma once

#include <vector>

class Piece {
private:
    char symbol;

public:
    int x, y;

    Piece(char symbol = '*', int x = 0, int y = 0);
    char GetSymbol();
    void SetPosition(int newX, int newY);
    bool IsValidMove(int toX, int toY, std::vector<std::vector<Piece>>& board, bool isWhiteTurn);

};