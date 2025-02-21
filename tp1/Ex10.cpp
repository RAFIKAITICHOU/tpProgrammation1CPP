#include <iostream>
#include <vector>
#include <random>
#include <utility>

std::vector<std::vector<int>> generateMaze(int n) {
    std::vector<std::vector<int>> maze(n, std::vector<int>(n, 0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, n - 1);
    maze[0][0] = 1;
    std::vector<std::pair<int, int>> walls;
    if (1 < n) walls.push_back({0, 1});
    if (1 < n) walls.push_back({1, 0});
    while (!walls.empty()) {
        int idx = dis(gen) % walls.size();
        auto wall = walls[idx];
        walls.erase(walls.begin() + idx);
        int x = wall.first;
        int y = wall.second;
        if (maze[x][y] == 0) {
            maze[x][y] = 1;
            if (x > 0 && maze[x - 1][y] == 0) walls.push_back({x - 1, y});
            if (x < n - 1 && maze[x + 1][y] == 0) walls.push_back({x + 1, y});
            if (y > 0 && maze[x][y - 1] == 0) walls.push_back({x, y - 1});
            if (y < n - 1 && maze[x][y + 1] == 0) walls.push_back({x, y + 1});
        }
    }
    return maze;
}

int main() {
    int n = 5;
    std::vector<std::vector<int>> maze = generateMaze(n);
    for (const auto& row : maze) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}