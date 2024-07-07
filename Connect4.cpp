#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

class Grid {
private:
    int rows, cols;
    vector<vector<char>> grid;

public:
    Grid() : rows(7), cols(6), grid(rows, vector<char>(cols, '.')) {}

    bool isValidPosition(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    int maxDistance(char c, int x, int y, int dirX, int dirY) {
        if (!isValidPosition(x, y) || grid[x][y] != c) {
            return 0;
        }
        return 1 + maxDistance(c, x + dirX, y + dirY, dirX, dirY);
    }

    bool didPlayerWin(char playerChar) {
        int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == playerChar) {
                    for (auto& dir : directions) {
                        if (maxDistance(playerChar, i, j, dir[0], dir[1]) >= 4) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    vector<int> getAvailableColumns() {
        vector<int> availColumns;
        for (int j = 0; j < cols; ++j) {
            if (grid[0][j] == '.') {
                availColumns.push_back(j);
            }
        }
        return availColumns;
    }

    void printGrid() {
        cout << endl;
        for (const auto& row : grid) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    bool playTurn(char playerChar, int column) {
        for (int i = rows - 1; i >= 0; --i) {
            if (grid[i][column] == '.') {
                grid[i][column] = playerChar;
                return true;
            }
        }
        return false;
    }
};

int generateRandomIndex(int n, mt19937& gen) {
    uniform_int_distribution<> dis(0, n - 1);
    return dis(gen);
}

int main() {
    Grid game;
    game.printGrid();

    mt19937 gen(random_device{}());
    bool isXTurn = false;

    while (true) {
        vector<int> availableCols = game.getAvailableColumns();
        if (availableCols.empty()) {
            cout << "GAME END\n";
            break;
        }

        int randomColumn = generateRandomIndex(availableCols.size(), gen);
        char currentChar = isXTurn ? 'X' : 'O';

        if (game.playTurn(currentChar, availableCols[randomColumn])) {
            game.printGrid();

            if (game.didPlayerWin(currentChar)) {
                cout << endl << "PLAYER WON " << currentChar << endl;
                break;
            }

            isXTurn = !isXTurn;
        }

        this_thread::sleep_for(chrono::milliseconds(50));
    }

    return 0;
}
