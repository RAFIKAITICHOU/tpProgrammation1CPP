#include <iostream>
#include <vector>
#include <utility>

bool dfs(const std::vector<std::vector<int>>& maze, std::vector<std::pair<int, int>>& path, std::vector<std::vector<bool>>& visited, int x, int y) {
    if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size() || maze[x][y] == 0 || visited[x][y]) {
        return false;
    }
    if (maze[x][y] == 2) {
        path.push_back({x, y});
        return true;
    }
    visited[x][y] = true;
    path.push_back({x, y});
    if (dfs(maze, path, visited, x + 1, y) || dfs(maze, path, visited, x - 1, y) || dfs(maze, path, visited, x, y + 1) || dfs(maze, path, visited, x, y - 1)) {
        return true;
    }
    path.pop_back();
    return false;
}

int main() {
    std::vector<std::vector<int>> maze = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 2}
    };
    std::vector<std::pair<int, int>> path;
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
    if (dfs(maze, path, visited, 0, 0)) {
        std::cout << "Chemin trouvé : ";
        for (auto p : path) {
            std::cout << "(" << p.first << "," << p.second << ") ";
        }
    } else {
        std::cout << "Pas de solution.";
    }
    return 0;
}