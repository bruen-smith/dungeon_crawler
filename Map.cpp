/*
 *Created by Bruen Smith on 11/18/2026.
 *
 * Learning some stuff about memory management like constructers
 * and deconstructers for faster programs. also putting my knowlege
 * consts and statics to the test. static should make smth once
 * and call it after and const should tell the program to optimize
 * around that thing not being touched once its been set
 *
 */


#include "libtcod.hpp"
#include "Map.hpp"

Map::Map(int width, int height) : width(width),height(height) {
    tiles = new Tile[width*height];
    set_wall(30,22);
    set_wall(50,22);
}

// delete the stuff we did above this
// aparrently super important dont want mem leaks
// ik its bad with mc so ig it makes sense
Map::~Map() {
    delete [] tiles;
}

// helper functions to call on later
bool Map::is_wall(int x, int y) const {
    return !tiles[x+y*width].can_walk;
}

void Map::set_wall(int x, int y) {
    tiles[x+y*width].can_walk=false;
}

void Map::render() const {
    // define colors
    static const TCODColor dark_wall(0,0,100);
    static const TCODColor dark_ground(50,50,150);

    // scan the map and convert it to a 2d plane and set colors
    // for this we need a nested for loop for the width and height
    // pretty similar to python
    for (int x=0; x < wodth; x++) {
        for (int y=0; y < height; y++) {
            //finally write some shit to the console
            //still dont understand this the best but its how tcod
            // works so ig thats how i got to do it
            TCODConsole::root->setCharBackground(x,y, is_wall(x,y)
                ? dark_wall : dark_ground);
            // used ternary uh idk why tbh but i need the practice
            // ig it is shorter tho
        }
    }
}

