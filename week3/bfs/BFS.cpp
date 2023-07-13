#include "judge.h"
#include <cstdio>
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
        int result = 0;
        return result;
    }
};

BFS solution;

int main() {
    judge::run(&solution);
    return 0;
}