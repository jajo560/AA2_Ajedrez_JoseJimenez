#pragma once

#include <vector>


class Board {
private:
    std::vector<std::vector<Piece>> board;

public:
    Board();
    void Initialize();
    void PrintBoard();

};