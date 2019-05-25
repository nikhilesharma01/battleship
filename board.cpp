#include <iostream>
#include <vector>
#include <string>
#include "board.hpp"

using namespace std;

Board::Board() {

}

Board::Board(int rows, int cols) : m_numRows(rows), m_numCols(cols) {

}

Board::~Board() {

}

void Board::setRows(int rows) {
    m_numRows = rows;
}

void Board::setCols(int cols) {
    m_numCols = cols;
}

int Board::getRows() {
    return m_numRows;
}

int Board::getCols() {
    return m_numCols;
}
