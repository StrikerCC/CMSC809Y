#include "coordinate.h"

coordinate::coordinate(int x, int y)
{
    this->x = x;
    this->y = y;
}

coordinate::~coordinate() {
//    delete this;
}

int coordinate::GetX() const {
    return this->x;
}

int coordinate::GetY() const {
    return this->y;
}


coordinate coordinate::GoNorth() {
    return coordinate(this->x, this->y-1);
}

coordinate coordinate::GoEast() {
    return coordinate(this->x+1, this->y);
}

coordinate coordinate::GoSouth() {
    return coordinate(this->x, this->y+1);
}

coordinate coordinate::GoWest() {
    return coordinate(this->x-1, this->y);
}
