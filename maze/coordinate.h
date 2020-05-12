#ifndef COORDINATE_H
#define COORDINATE_H


class coordinate
{
    int x, y;
public:
    coordinate(int GetX, int y);
    ~coordinate();
    int GetX() const;
    int GetY() const;
    coordinate GoNorth();
    coordinate GoEast();
    coordinate GoSouth();
    coordinate GoWest();
};

#endif // COORDINATE_H
