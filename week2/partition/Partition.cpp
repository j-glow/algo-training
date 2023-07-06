#include "judge.h"

class Partition : public iPartition {
 public:
  virtual bool checkPartition(int* array, int n) {
    return 0;
  }
};

int main() {
  // Uncomment to use file instead of stdin
  // REMEMBER TO CHANGE BACK, WHEN SENDING
  //
  // freopen("../Partition0.in", "r", stdin);
  Partition solution;
  judge::run(&solution);
}