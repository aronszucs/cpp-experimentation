#ifndef _POINT_H
#define _POINT_H

#include <iostream>
#include <string>


struct Point {
    int x;
    int y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};
#endif