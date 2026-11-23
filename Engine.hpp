/*
 *Created by L00716137 on 11/18/2026.
 */


#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <libtcod/list.hpp>

class Actor;
class Map;

class Engine {
public:
    TCODList<Actor *> actors;
    Actor *player;
    Map *map;

    Engine();
    ~Engine();
    void update();
    void render();
};

extern Engine engine;

#endif //ENGINE_HPP
