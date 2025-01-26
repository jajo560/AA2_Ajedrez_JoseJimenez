#pragma once

#include <string>
#include <vector>
#include "piece.h"

class Board {
private:
    std::vector<std::vector<Piece>> board;

public:
    Board();
    void Initialize();
    void PrintBoard();
    bool MovePiece(std::string from, std::string to, bool isWhiteTurn);

};