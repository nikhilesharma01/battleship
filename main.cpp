#include <iostream>
#include <vector>
#include <string>
#include "battleship.hpp"
#include "board.hpp"
#include "player.hpp"

using namespace std;

int main() {
    int numRows, numCols;
    string box;
    bool result1, result2;
    Player player1, player2;

    cout << "Enter the board dimensions: " << endl;
    cin >> numRows >> numCols;

    cout << "Initializing player1's board: " << endl;
    player1.initializeBoard(numRows, numCols);

    cout << "Initializing player1's ships: " << endl;
    player1.initializeShips(1);

    cout << "Initializing player2's board: " << endl;
    player2.initializeBoard(numRows, numCols);

    cout << "Initializing player2's ships: " << endl;
    player2.initializeShips(2);

    result1 = true;
    result2 = true;

    while( player1.isPlayerDone() == false && player2.isPlayerDone() == false) {
        /* Player1's turn */
        while (result1 == true) {
            if (player1.getNumHits() < player1.getNumBoxes()) {
                cout << "Player1: Choose the opponent's box to hit: " << endl;
                cin >> box;
                cout << "Player 1 chooses to hit: " << box << endl;

                result1 = player1.isBoxHit(&player2, box);

                if (result1 == true)
                    cout << "Result: HIT!" << endl;
                else
                    cout << "Result: MISS!" << endl;
            }
            else
                break;
        }

        if (player1.isPlayerDone() == true)
            break;

        /* Player2's turn */
        while (result2 == true) {
            if (player2.getNumHits() < player2.getNumBoxes()) {
                cout << "Player 2: Choose the opponent's box to hit: " << endl;
                cin >> box;
                cout << "Player 2 chooses to hit: " << box << endl;

                result2 = player2.isBoxHit(&player1, box);

                if (result2 == true)
                    cout << "Result: HIT!" << endl;
                else
                    cout << "Result: MISS!" << endl;
            }
            else
                break;
        }

        if (player2.isPlayerDone() == true)
            break;
    }

    if (player1.isPlayerDone() == true && player2.isPlayerDone() == false)
        cout << "Player 1 wins!" << endl;

    if (player1.isPlayerDone() == false && player2.isPlayerDone() == true)
        cout << "Player 2 wins!" << endl;

    return 0;
}
