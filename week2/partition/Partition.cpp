#include "judge.h"

class Partition : public iPartition {
   public:
    virtual bool checkPartition(int* array, int n) {
        int sum =0;
        for (int i = 0; i < n; i++) {
            sum+=array[i];
        }
        if(sum%2!=0) return false;
        return check(array, n, sum);
    }
    bool check(int* array, int n, int sum){
        if(sum==0) return true;
        if(n==0) return false;
        return check(array+1, n-1, sum-array[0]) || check(array+1, n-1, sum);
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