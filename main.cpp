/* Project Name: Generic Dungeon Crawler
* Programmer Name: Bruen Smith
 * Date: 10/26/2026 MM/DD/YYYY
 * Version: 1.2.1
 * IDE: CLion 2024.1.4
 * Description: An in console dungeon crawler!
 */

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <chrono>

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

bool process_input() {
    // handle user inout
    int input = _getch();
    switch (input) {
        case 'W':
        case 'w':
            // go up
            std::cout << "W was pressed \n\n";
            break;

        case 'A':
        case 'a':
            // go left
            std::cout << "A was pressed \n\n";
            break;

        case 'S':
        case 's':
            // go down
            std::cout << "S was pressed \n\n";
            break;

        case 'D':
        case 'd':
            // go right
            std::cout << "D was pressed \n\n";
            break;

        case 'Q':
        case 'q':
            // quits loop for testing
            return false;

        default:
            break; //ignore random stuff
    }

    return true;
}

void update() {
    // advance the game one step
}

void render() {
    // draw the game
    std::system("cls");
    for (auto & row : maze) {
        for (char column : row) {
            std::cout << column;
        }
        std::cout << '\n';
    }
}

int main() {
    using Clock = std::chrono::steady_clock;
    using Duration = std::chrono::duration<double>;

    // 60 updates per second
    constexpr Duration updateInterval{1.0 / 6.0};

    bool running = true;
    auto previous = Clock::now();
    Duration lag{0.0};

    while(running) {
        auto current = Clock::now();
        Duration elapsed = current - previous;
        previous = current;
        lag += elapsed;

        running = process_input();

        while (lag >= updateInterval) {
            update();
            lag -= updateInterval;
        }

        render();
    }

    return 0;
}
