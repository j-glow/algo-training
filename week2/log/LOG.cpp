#include <cstdio>

#include "judge.h"

class LOG : public iLOG {
   public:
    virtual int solve(int n, char logo[10][10], char stamps[][4][4]) {
        int result = 0;
        return result;
    }
};

LOG solution;

int main() {
    judge::run(&solution);
    return 0;
}