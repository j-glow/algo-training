#include "judge.h"
// #include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class BFS : public iBFS {
    // Not part of task - may be useful when debugging.
    void printTestCase(int n, int m, const char *start, const char *end,
                       const char **a, const char **b) {
        for (int i = 0; i < m; i++) {
            printf("%s -> %s\n", a[i], b[i]);
        }
        printf("QUESTION: %s -> %s\n", start, end);
    }

   public:
    int solve(int n, int m, const char *start, const char *end, const char **a,
              const char **b) {
        // printTestCase(n, m, start, end, a, b);

        // PREPARE DATA
        string sstart{start};
        string send{end};
        if (sstart == send) return 0;
        string sa[m];
        string sb[m];
        for (int i = 0; i < m; i++) {
            sa[i] = string(a[i]);
            sb[i] = string(b[i]);
        }
        auto routes = create_map(m, sa, sb);
        unordered_map<string, int> shortest_path;
        queue<string> order;

        // PREPARE LOOP
        string city = sstart;
        shortest_path[city] = 0;
        while (true) {
            for (auto i : routes[city]) {
                if (shortest_path.count(i))
                    continue;
                else {
                    shortest_path[i] = shortest_path[city] + 1;
                    order.push(i);
                }
            }
            if (order.empty()) break;
            city = order.front();
            order.pop();
        }
        if (shortest_path[send])
            return shortest_path[send];
        else
            return -1;
    }

    map<string, vector<string>> create_map(int m, string a[], string b[]) {
        map<string, vector<string>> routes;
        for (int i = 0; i < m; i++) {
            routes[a[i]].push_back(b[i]);
        }
        return routes;
    }
};

BFS solution;

int main() {
    judge::run(&solution);
    return 0;
}