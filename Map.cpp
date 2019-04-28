#include "Map.h"
#include <iostream>
using namespace std;
Map::Map(int n, int m)
{
    height = n;
    width = m;
    M.resize(n);
    for (int i = 0; i < n; i++)
        M[i].resize(m);
    M[0][0] = 1;
}

Map::~Map()
{
    M.erase(M.begin(), M.end());
}

Map::Map(Map &obj)
{
    height = obj.height;
    width = obj.width;
    M.resize(height);
    for (int i = 0; i < height; i++)
        M[i].resize(width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            M[i][j] = obj.M[i][j];
}

bool Map::is_trap(pair < int, int > p) const
{
    if (M[p.first][p.second] == -1)
    {
        return true;
    }
    return false;
}

Map &Map::operator=(const Map &A)
{
    if (this != &A)
    {
        height = A.height;
        width = A.width;
        treasure_position.first = A.treasure_position.first;
        treasure_position.second = A.treasure_position.second;
        M.resize(height);
        for (int i = 0; i < height; i++)
            M[i].resize(width);
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                M[i][j] = A.M[i][j];
    }
    return *this;
}

void operator << (int x, Map & world)
{
    int i, j;
    for (i = 0; i < world.height; i++)
        cout << "__";
    cout << "\n";
    for (i = 0; i < world.height; i++)
    {
        for (j = 0; j < world.width; j++)
        {
            if(j == 0)
                cout << "| ";
            if(world.M[i][j] == 0)
                cout << "_ ";
            else
                cout << world.M[i][j] << " ";
            if(j == world.width - 1)
                cout << "|";
        }
        cout << "\n";
    }
    for (i = 0; i < world.height; i++)
        cout << "__";
    cout << "\n";
}
