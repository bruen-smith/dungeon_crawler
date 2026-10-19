/* Project Name: Generic Dungeon Crawler
 * Programmer Name: Bruen Smith
 * Date: 10/19/2026 MM/DD/YYYY
 * Version: 1.1.0
 * IDE: CLion 2024.1.4
 * Description: An in console dungeon crawler!
 */

#include <iostream>
#include <iomanip>

char maze[8][8] = {
    {'#','P','#','#','#','#','#','#'},
    {'#','.','#','.','.','.','.','#'},
    {'#','.','#','.','#','#','.','#'},
    {'#','.','.','.','#','.','.','#'},
    {'#','#','#','.','#','.','.','#'},
    {'#','.','.','.','#','#','.','#'},
    {'#','.','#','.','.','#','.','X'},
    {'#','#','#','#','#','#','#','#'}
};

void ProcessInput() {
    // stuff will go here eventually lol
}

void render() {
    std::system("cls");
    for (auto & row : maze) {
        for (char column : row) {
            std::cout << column;
        }
        std::cout << '\n';
    }
}

int main() {
    bool running = true;
    while(running) {
        ProcessInput();
        running = false;
    }

    return 0;
}
