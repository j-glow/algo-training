#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#include "judge.h"

class Shops : public iShops {
    std::vector<std::vector<bool>> visited;
    std::vector<std::pair<int, int>> house;
    std::queue<std::pair<int, int>> queue;

   public:
    int getDistance(char data[256][256]) {
        int max = -1;
        house = std::vector<std::pair<int, int>>();

        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                if (data[i][j] == 'M') house.push_back(std::pair<int, int>(i, j));
            }
        }

        for (auto i : house) {
            queue = std::queue<std::pair<int, int>>();
            visited = std::vector<std::vector<bool>>(256, std::vector<bool>(256, false));

            auto distance = bfs(i, data);
            if (distance == -1) return -1;

            if (distance > max) max = distance;
        }

        return max;
    }

    int bfs(std::pair<int, int> coord, char data[256][256]) {
        int distance = 0;
        queue.push(coord);
        int result = 0;

        while (!queue.empty()) {
            distance += 1;
            result = solve_queue(data);
        }

        if (result == 1)
            return distance - 1;
        else
            return -1;
    }
    int solve_queue(char data[256][256]) {
        std::queue<std::pair<int, int>> new_queue;

        while (!queue.empty()) {
            auto coord = queue.front();
            queue.pop();

            if (data[coord.first][coord.second] == 'S') {
                queue = std::queue<std::pair<int, int>>();
                return 1;
            }

            if (check_coord({coord.first + 1, coord.second}, data))
                new_queue.push({coord.first + 1, coord.second});
            if (check_coord({coord.first - 1, coord.second}, data))
                new_queue.push({coord.first - 1, coord.second});
            if (check_coord({coord.first, coord.second + 1}, data))
                new_queue.push({coord.first, coord.second + 1});
            if (check_coord({coord.first, coord.second - 1}, data))
                new_queue.push({coord.first, coord.second - 1});
        }
        if (new_queue.empty()) return -1;
        queue = new_queue;
        return 0;
    }

    bool check_coord(std::pair<int, int> coord, char data[256][256]) {
        if (coord.first < 0 || coord.first > 255 || coord.second < 0 || coord.second > 255)
            return false;
        if (visited[coord.first][coord.second])
            return false;
        visited[coord.first][coord.second] = true;
        if (data[coord.first][coord.second] == 'P')
            return false;

        return true;
    }
};

Shops solution;

int main() {
    freopen("in/Shops4.in", "r", stdin);
    judge::run(&solution);
    return 0;
}