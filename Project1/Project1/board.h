#pragma once

#include <vector>
#include "piece.h"

class Board {
private:
    std::vector<std::vector<Piece>> board;

public:
    Board();
    void Initialize();
    void PrintBoard();

};