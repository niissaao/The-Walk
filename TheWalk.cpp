#include "TheWalk.h"
#include <cstdlib>
TheWalk::TheWalk() : world(1, 1)
{
    nr_rounds = 0;
    count_traps = 0;
}

void TheWalk::set_robot(Robot *a)
{
    robo = a;
}

void TheWalk::set_robot_position(int x, int y)
{
    robo -> set_position(x, y);
}

ifstream &operator>>(ifstream &fin, TheWalk &game)
{
    int x, y;
    fin >> game.nr_rounds;
    fin >> x >> y;
    Map A(x, y);
    fin >> x >> y;
    A.set_treasure_position(make_pair(x, y));
    fin >> game.count_traps;
    for (int i = 0; i < game.count_traps; i++)
    {
        Trap *current_trap = new Trap();
        (*current_trap).read(fin, A);
        game.traps.push_back(current_trap);
    }
    game.world = A;
    return fin;
}

TheWalk::~TheWalk()
{
    traps.clear();
}

void TheWalk::play_game()
{
    int it = 0;
    cout << world;
    //joaca pana gaseste comoara
    while(robo->round(world)==0)
    {
        cout << "Round:" << it << endl;
        cout << world;
        it++;
        if(it == nr_rounds)
            exit(0);
    }
}
