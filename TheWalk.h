#ifndef THEWALK_H
#define THEWALK_H
#include "Map.h"
#include "Robot.h"
#include "Trap.h"
#include <fstream>
using namespace std;
class TheWalk
{
    int nr_rounds;
    vector < Trap* > traps;
    int count_traps;
    Robot *robo;
    Map world;
public:
    TheWalk();
    ~TheWalk();
    void set_robot(Robot *a);
    friend class Robot;
    friend class Trap;
    friend ifstream &operator>> (ifstream &input, TheWalk &game);
    void set_robot_position(int x, int y);
    void play_game();
};
#endif //THEWALK_H
