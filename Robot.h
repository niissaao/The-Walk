#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <vector>
#include <iostream>
#include "Map.h"

using namespace std;
class Robot
{
    pair < int, int > position;
public:
    friend class TheWalk;
    Robot();
    void set_map_position(pair < int, int > p, Map &world);
    bool round(Map &world);
    ~Robot();

    pair < int, int > get_position() const
    {
        return position;
    };

    void set_position(int move_row, int move_column)
    {
        position.first = move_row;
        position.second = move_column;
    }
};
#endif //ROBOT_H
