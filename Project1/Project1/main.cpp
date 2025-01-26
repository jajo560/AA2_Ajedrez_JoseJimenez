#include <iostream>
#include "board.h"
#include "piece.h"

using namespace std;

int main() {
    Board chessBoard;
    chessBoard.Initialize();

    bool isWhiteTurn = true;
    string from, to;

    while (true) {
        chessBoard.PrintBoard();

        if (chessBoard.IsCheckmate(isWhiteTurn)) {
            cout << (isWhiteTurn ? "Negras" : "Blancas") << " ganan por jaque mate." << endl;
            break;
        }

        cout << (isWhiteTurn ? "Blancas" : "Negras") << " mueven. Ingresa movimiento (e.g., e2 e4): ";
        cin >> from >> to;

        if (!chessBoard.MovePiece(from, to, isWhiteTurn)) {
            cout << "Movimiento invalido." << endl;
            continue;
        }

        isWhiteTurn = !isWhiteTurn;
    }

    return 0;
}
