#include <iostream>
#include <vector>
#include <string>
#include "battleship.hpp"

using namespace std;

Battleship::Battleship() {

}

Battleship::Battleship(int size, int orientation) : m_size(size), m_orientation(orientation) {
    for (int i = 0; i < m_ship.size(); i++)
        m_ship[i] = "";
}

Battleship::~Battleship() {
    std::vector<string> m_ship(m_size, "");
}

int Battleship::getSize() {
    return m_size;
}

void Battleship::setSize(int size) {
    m_size = size;
}

vector<string> Battleship::getShip() {
    return this->m_ship;
}

void Battleship::addLocation(string loc) {
    this->m_ship.push_back(loc);
}

void Battleship::printShip() {
    for (int i = 0; i < m_size; i++) {
        cout << m_ship[i] << " ";
    }
}
