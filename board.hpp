/*
 *  Board file:
 *      Initializes the playing board.
 *
 */

#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Board {
private:
    int m_numRows;
    int m_numCols;

public:
    Board();
    Board(int rows, int cols);
    ~Board();

    void setRows(int rows);
    void setCols(int cols);
    int getRows();
    int getCols();
    void initializeShips();
};

#endif
