//
// Created by Bruen Smith on 11/16/2026.
//

#include "libtcod.hpp"
#include "Actor.hpp" // uses libtcod so must come after

Actor::Actor(int x, int y, int ch, const TCODColor &col) :
    x(x),y(y),ch(ch),col(col) {
}
// set the details of the character immedietly at creation
// initialyzing the list skips extra steps and is typically better

void Actor::render() const {
    TCODConsole::root->setChar(x,y,ch);
    TCODConsole::root->setCharForeground(x,y,col);
}