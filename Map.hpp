//
// Created by Bruen Smith on 11/16/2026.
//
// a lot of defining ideas
//

#ifndef MAP_HPP
#define MAP_HPP

struct Tile {
    bool can_walk; // tell us if we can walk through tiles
    Tile() : can_walk(true) {}
};

class Map {
public:
    int width,height;

    Map(int width, int height);
    ~Map();
    bool is_wall(int x, int y) const;
    void render() const;
protected:
    Tile *tiles;

    void set_wall(int x, int y);
};

#endif //MAP_HPP
