/*
 * Battleship Game:
 *      Base class of a battleship.
 *      Each battleship has a size and a vector of
 *      locations.
 */

#ifndef _BATTLESHIP_HPP_
#define _BATTLESHIP_HPP_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Battleship{
private:
    int m_size;
    int m_orientation;
    vector<string> m_ship;

public:
    /* Constructors and destructors */
    Battleship();
    Battleship(int size, int orientation);
    ~Battleship();

    /* Setter and Getter functions */
    int getSize();
    void setSize(int size);
    vector<string> getShip();
    void addLocation(string loc);
    void printShip();
};

#endif
