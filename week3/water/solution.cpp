#include <queue>
#include <set>
#include <vector>
#include <fstream>

#include "judge.h"

class water : public iwater {
    std::set<std::vector<int>> seen;
    std::queue<std::vector<int>> queue;

   public:
    virtual int minMoves(int n, int c[4], int b[4]) {
        seen.clear();
        queue = std::queue<std::vector<int>>();

        std::vector<int> jars;
        for (int i = 0; i < n; i++) {
            jars.push_back(c[i]);
        }
        queue.push(jars);

        int steps = 0;
        while (!queue.empty()) {
            if (solve(n, c, b)) return steps;
            steps++;
        }
        return -1;
    }

    bool solve(int n, int c[4], int b[4]) {
        std::vector<int> jars;
        std::queue<std::vector<int>> new_queue;

        while (!queue.empty()) {
            jars = queue.front();
            queue.pop();

            int i = 0;
            while (true) {
                // every jar matches output
                if (i == n) return true;

                // jar mismatch
                if (jars[i] != b[i]) break;
                i++;
            }

            // check if state was already reached
            if (seen.count(jars) != 0) continue;
            seen.insert(jars);

            // if water is negative, cant finish, return false
            int water = 0;
            for (int i = 0; i < n; i++) {
                water += jars[i];
                water -= b[i];
            }
            if (water < 0) continue;;

            std::vector<int> jars_new;
            // add next possible moves to next state queue
            for (int i = 0; i < n; i++) {
                if (jars[i] == 0) continue;
                // emptying jar     I
                jars_new = jars;
                jars_new[i] = 0;
                new_queue.push(jars_new);

                // moving jar       I->J
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    jars_new = jars;
                    int miejsce = c[j] - jars_new[j];
                    if (miejsce == 0 || jars[i] == 0)
                        continue;
                    else if (miejsce >= jars_new[i]) {
                        jars_new[j] += jars_new[i];
                        jars_new[i] = 0;
                    } else if (miejsce < jars_new[i]) {
                        jars_new[i] -= miejsce;
                        jars_new[j] = c[j];
                    }
                    new_queue.push(jars_new);
                }
            }
        }
        //solution not found, proceed to next state wave
        queue = new_queue;
        return false;
    }
};

int main() {
    // freopen("in/prz0a.in","r",stdin);
    water w;
    judge::run(&w);
}
