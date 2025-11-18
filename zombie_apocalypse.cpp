#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;
char map[HEIGHT][WIDTH];

// Player position
int playerX = 0;
int playerY = 0;

void generateMap() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = '.';
        }
    }
    map[0][0] = 'P'; // Player start
    map[HEIGHT - 1][WIDTH - 1] = 'E'; // Exit
}

void printMap() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void movePlayer(char move) {
    // Remove player from current position
    map[playerX][playerY] = '.';

    // Update position based on input
    if (move == 'W' || move == 'w') playerX = max(0, playerX - 1);
    if (move == 'S' || move == 's') playerX = min(HEIGHT - 1, playerX + 1);
    if (move == 'A' || move == 'a') playerY = max(0, playerY - 1);
    if (move == 'D' || move == 'd') playerY = min(WIDTH - 1, playerY + 1);

    // Place player in new position
    map[playerX][playerY] = 'P';
}

int main() {
    srand(time(0));
    generateMap();

    while (true) {
        printMap();
        cout << "Use W/A/S/D to move. Reach E to escape!" << endl;

        // Check win condition
        if (playerX == HEIGHT - 1 && playerY == WIDTH - 1) {
            cout << "You reached the exit. Game Over!" << endl;
            break;
        }

        char move;
        cin >> move;
        movePlayer(move);

        system("clear"); // For Linux/Mac to clear screen; use "cls" on Windows
    }

    return 0;
}
