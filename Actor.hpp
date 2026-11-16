/*
 * Created by Bruen Smith on 11/16/2026.
 * I am using an int to store the ascii code
 * of the character representing the Actor
 * instead of a char or unsigned char because
 * it makes it possible to use more
 * than 256 different characters.
 */
#ifndef ACTOR_HPP
#define Actor_HPP

#include "libtcod.hpp"

class Actor {
public:
    int x,y; // position on map
    int ch; // ascii code
    TCODColor col; // color

    Actor(int x, int y, int ch, const TCODColor &col);
    void render() const;
};

#endif