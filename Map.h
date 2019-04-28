#ifndef MAP_H
#define MAP_H

#include <utility>
#include <vector>
#include <fstream>
using namespace std;
//saves the map details
class Map
{
    int width;
    int height;
    pair < int, int > treasure_position;
    vector < vector < int > > M;
    friend class Robot;
    friend class Trap;
    friend class TheWalk;
public:
    Map(int n, int m);
    Map(Map &M);
    ~Map();
    bool is_trap(pair < int, int > p) const; //verifica daca pe pozitia curenta e o capcana
    Map &operator= (const Map &A);
    friend void operator<< (int x, Map &world);

    Map() : width(1), height(1)
    {
        M.resize(1);
        M[1].resize(1);
    };

    int get_height() const
    {
        return height;
    }

    int get_width() const
    {
        return width;
    }

    pair < int, int > get_treasure_position()
    {
        return treasure_position;
    };

    void set_treasure_position(pair < int, int > p)
    {
        treasure_position.first = p.first;
        treasure_position.second = p.second;
        M[p.first][p.second] = 8; //destinatia se va nota cu 8
    }
};

#endif // MAP_H
