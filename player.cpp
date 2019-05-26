#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "board.hpp"
#include "player.hpp"
#include "battleship.hpp"

using namespace std;

int Player::m_playerID{0};

Player::Player() {
    m_playerID++;
    m_hits = 0;
}

Player::~Player() {

}

void Player::initializeBoard(int rows, int cols) {
    this->m_board = Board(rows, cols);
}

void Player::initializeShips(int playerID) {
    /* Random seed for each initialization */
    srand(playerID);

    int count = 0;
    this->m_numShipBoxes = 0;

    while (count < 5) {

        bool placed = false;
        int ship_size = 5 - count;
        this->m_numShipBoxes += ship_size;

        /* Choose random orientation: Horizontal = 0, Vertical = 1*/
        int orientation = rand() % 2;
        Battleship* ship = new Battleship(ship_size, orientation);

        while (placed == false) {

            /* Get starting location for the ship */
            int row = rand() % m_board.getRows();
            int col = rand() % m_board.getCols();

            string location = to_string(row) + to_string(col);

            if (orientation == 0) {
                if (col + ship_size - 1 < m_board.getCols()) {
                    for (int j = 0; j < ship_size; j++) {
                        string new_box = to_string(row) + to_string(col + j);
                        ship->addLocation(new_box);
                    }
                    placed = true;
                }
            }

            else if (orientation == 1) {
                if (row + ship_size - 1 <= m_board.getRows()) {
                    for (int j = 0; j < ship_size; j++) {
                        string new_box = to_string(row + j) + to_string(col);
                        ship->addLocation(new_box);
                    }
                    placed = true;
                }
            }

        }
        count++;
        this->m_ships.push_back(ship);
    }
    this->printShips();
}

int Player::getNumBoxes() {
    return this->m_numShipBoxes;
}

void Player::printShips() {
    for (int i = 0; i < m_ships.size(); i++) {
        Battleship* ship = m_ships[i];

        ship->printShip();
        cout << endl;
    }
}

vector<Battleship*> Player::getShipLocations() {
    return this->m_ships;
}

int Player::getNumHits() {
    return this->m_hits;
}

bool Player::isBoxHit(Player* player, string box) {
    /* Opponent's battleships */
    vector<Battleship*> oppShips = player->getShipLocations();

    /* Search for the selected box in the opponent's ships */
    for (int i = 0; i < oppShips.size(); i++) {
        Battleship* ship = oppShips[i];
        vector<string> strShip = ship->getShip();

        vector<string>::iterator it = find(strShip.begin(), strShip.end(), box);

        if (it != strShip.end()){
            this->m_hits++;
            return true;
        }
    }

    return false;
}

bool Player::isPlayerDone() {
    if (m_hits == m_numShipBoxes)
        return true;

    return false;
}
