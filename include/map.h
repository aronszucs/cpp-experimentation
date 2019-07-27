#ifndef _MAP_H
#define _MAP_H

#include <iostream>
#include <string>
#include "point.h"

using namespace std;




class Map{
    private:
        int sizeX_;
        int sizeY_;
        short **map_;

    public:
        Map(int, int);
        int getSizeX() {return sizeX_;}
        int getSizeY() {return sizeY_;}
        void setTile(Point, short);
        short getTile(Point);
};
#endif