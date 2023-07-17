#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>

#include "judge.h"

class KOL2 : public IKOL2 {
    std::map<int, std::set<int>> edges;
    std::vector<int> colors;
    std::queue<int> queue;

   public:
    bool isGraph2Colorable(int vertexCount, int edgeCount, int *edge1, int *edge2) {
        colors = std::vector<int>(vertexCount+1, -1);
        edges = std::map<int, std::set<int>>();
        queue = std::queue<int>();

        for (int i = 0; i < edgeCount; i++) {
            edges[edge1[i]].insert(edge2[i]);
            edges[edge2[i]].insert(edge1[i]);
        }
        return solve();
    }

    bool solve() {
        int source;
        while(true) {
            source = find_not_seen();
            if(source == -1) break;
            colors[source] = 0;
            if (bfs(source) == false) return false;
        }
        return true;
    }

    bool bfs(int vertex) {
        if(!queue.empty()) queue.pop();
        for (int i : edges[vertex]) {
            if (colors[vertex] == colors[i]) return false;
            if (colors[i] == -1) {
                queue.push(i);
                colors[i] = (colors[vertex] == 0) ? 1 : 0;
            }
        }
        while (!queue.empty()) {
            if (!bfs(queue.front())) return false;
        }
        return true;
    }

    int find_not_seen() {
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] == -1) return i;
        }
        return -1;
    };
};

KOL2 solution;
int main() {
    //freopen("in/KOL20c.in", "r", stdin);
    Judge::run(&solution);
    return 0;
}
