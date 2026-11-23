/* Project Name: Generic Dungeon Crawler
 * Programmer Name: Bruen Smith
 * Date: 11/23/2026 MM/DD/YYYY
 * Version: 1.3.2
 * IDE: CLion 2024.1.4
 * Description: A text based dungeon crawler.
 */

#include "libtcod.hpp"
#include "Actor.hpp"
#include "Map.hpp"
#include "Engine.hpp"

Engine engine;

int main() {
    while ( !TCODConsole::isWindowClosed() ) {
        engine.update();
        engine.render();
        TCODConsole::flush();
    }
    return 0;
}