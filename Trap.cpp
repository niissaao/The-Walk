#include "Trap.h"

Trap::Trap(int i, int j, Map &world)
{
    world.M[i][j] = -1;
    position.first = i;
    position.second = j;
}

Trap::Trap()
{
    position.first = -1;
    position.second = -1;
}

//capcanele se vor nota cu 4
void Trap::read(ifstream &fin, Map &world)
{
    fin >> position.first;
    fin >> position.second;
    world.M[position.first][position.second] = 4;
}
