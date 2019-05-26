#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include <vector>
#include "board.hpp"
#include "battleship.hpp"

using namespace std;

class Player {
private:
    static int m_playerID;
    int m_hits;
    int m_numShipBoxes;
    Board m_board;
    vector<Battleship*> m_ships;

public:
    Player();
    ~Player();

    void initializeBoard(int rows, int cols);
    void initializeShips(int playerID);
    int getNumBoxes();
    void printShips();
    vector<Battleship*> getShipLocations();

    int getNumHits();
    bool isBoxHit(Player* player, string box);
    bool isPlayerDone();
};

#endif
