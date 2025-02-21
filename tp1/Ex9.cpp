#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int bfs(const std::vector<std::vector<int>>& maze, int startX, int startY) {
    std::queue<std::pair<int, int>> q;
    q.push({startX, startY});
    std::vector<std::vector<int>> dist(maze.size(), std::vector<int>(maze[0].size(), -1));
    dist[startX][startY] = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        if (maze[current.first][current.second] == 2) {
            return dist[current.first][current.second];
        }
        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < maze.size() && ny < maze[0].size() && maze[nx][ny] != 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[current.first][current.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    std::vector<std::vector<int>> maze = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 2}
    };
    int steps = bfs(maze, 0, 0);
    if (steps != -1) {
        std::cout << "Le chemin le plus court a une longueur de " << steps << std::endl;
    } else {
        std::cout << "Pas de solution." << std::endl;
    }
    return 0;
}