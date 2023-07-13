#include "judge.h"

class Shops : public iShops {
  public:
    int getDistance(char data[256][256]) {
        return 0;
    }
};

Shops solution;

int main() {
    judge::run(&solution);
    return 0;
}