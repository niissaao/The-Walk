#include <iostream>
#include "TheWalk.h"
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int main()
{
    TheWalk the_walk;
    fin >> the_walk;
    Robot *a;
    a = new Robot();
    the_walk.set_robot(a);
    the_walk.play_game();
    return 0;
}
