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
    Board m_board;
    vector<Battleship*> m_ships;

public:
    Player();
    ~Player();

    void initializeBoard(int rows, int cols);
    void initializeShips(int playerID);
    void printShips();
    vector<Battleship*> getShipLocations();

    bool isBoxHit(Player* player, string box);
    bool isPlayerDone();
};

#endif
