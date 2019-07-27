#include <iostream>
#include <string>
#include "map.h"

using namespace std;


Map::Map(int sizeX, int sizeY) : sizeX_(sizeX), sizeY_(sizeY) {
    map_ = new short*[sizeX];
    for (int y = 0; y < sizeY; y++) {
        map_[y] = new short[sizeY_];
    }
}

short Map::getTile(Point p) {
    return map_[p.x][p.y];
}

void Map::setTile(Point p, short tileId) {
    map_[p.x][p.y] = tileId;
}