//
// Created by L00716137 on 11/23/2026.
//

#include "libtcod.hpp"
#include "Actor.hpp"
#include "Map.hpp"
#include "Engine.hpp"

// Constructor
Engine::Engine() {
    // Makes the Console and dynamically allocates the actors
    // so far one for the player and one for future use such as an npc
    TCODConsole::initRoot(80,50,"Text-Based Crawler", false);
    player = new Actor(40,25,'@', TCODColor::white);
    actors.push(player);
    actors.push(new Actor(60,13,'@',TCODColor::yellow));
    map = new Map(80,45);
}

// destructor
Engine::~Engine() {
    // delete all the objs same as the map
    actors.clearAndDelete();
    delete map;
}

// World Update stuff
void Engine::update() {
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
    switch (key.vk) {
        case TCODK_UP:
            if ( ! map->is_wall(player->x,player->y-1)) {
                player->y--; // go up
            }
        break;
        case TCODK_DOWN:
            if ( ! map->is_wall(player->x,player->y+1)) {
                player->y++; // go down
            }
        break;
        case TCODK_LEFT:
            if ( ! map->is_wall(player->x-1,player->y)) {
                player->x--; // go left
            }
        break;
        case TCODK_RIGHT:
            if ( ! map->is_wall(player->x+1,player->y)) {
                player->x++; // go right
            }
        break;
        default:break;
    }
}

// finally render all the crap above
void Engine::render() {
    TCODConsole::root->clear();
    // draw the map
    map->render();
    // draw the things on the map
    for (Actor **iterator=actors.begin();
        iterator != actors.end(); iterator++) {
        (*iterator)->render();
    }
    // much more shaky on this last part but i believe
    // its iterating through all the actors and drawing them
    // there seems to be an easier way of doing this but i understand that even less so...
}
