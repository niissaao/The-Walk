#ifndef TRAP_H
#define TRAP_H

#include "Map.h"
using namespace std;
class Trap
{
    pair < int, int > position;
public:
    Trap(int i, int j, Map &world);
    Trap();
    void read(ifstream &fin, Map &world);
};
#endif // TRAP_H
