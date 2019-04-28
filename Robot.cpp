#include "Robot.h"
#include "Trap.h"
#include <cstdlib>
Robot::Robot()
{
    position.first = 0;
    position.second = 0;
}

//pozitia robotului se va nota cu 1
void Robot::set_map_position(pair < int, int > p, Map &world)
{
    world.M[p.first][p.second] = 1;
}

Robot::~Robot() {}

bool Robot::round(Map &world)
{
    int i = get_position().first;
    int j = get_position().second;
    int xF = world.treasure_position.first;
    int yF = world.treasure_position.second;
    if (world.get_treasure_position() == make_pair(j, i))
    {
        return true;
    }
    else
    {
        if (abs(xF - i) <= 4 && abs(yF - j) <= 4)
        {
            if (xF < i)
                set_position(i - 1, j);
            else if (xF > i)
                set_position(i + 1, j);
            if (yF < j)
                set_position(i, j - 1);
            else if (yF > j)
                set_position(i, j + 1);
            set_map_position(get_position(), world);
            if (world.is_trap(get_position()))
            {
                set_position(i - 1, j - 1); //muta robotul cu un pas mai in spate
            }
        }
        else
        {
            //robotul se controleaza cu tastele s, d, e, c)
            char x;
            cout << "Urmatoarea miscare a robotului: ";
            cin >> x;
            if(x == 's')
                set_position(i + 1, j);
            if(x == 'd')
                set_position(i, j + 1);
            if(x == 'e')
                set_position(i - 1, j + 1);
            if(x == 'c')
                set_position(i + 1, j + 1);
            return 0;
        }
    }
    return false;
}
