#include "judge.h"

class Partition : public iPartition {
   public:
    virtual bool checkPartition(int* array, int n) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += array[i];
        }
        if(sum % 2) return false;
        sum >>= 1;

        return isSubsetSum(array, n, sum);
    }

    bool isSubsetSum(int* array, int n, int sum){
        if(!sum) return true;
        if(!n) return false; 
        return isSubsetSum(array, n-1, sum) || isSubsetSum(array, n-1, sum-array[n-1]);
    }
};

int main() {
    // Uncomment to use file instead of stdin
    // REMEMBER TO CHANGE BACK, WHEN SENDING
    //
    // freopen("Partition0.in", "r", stdin);
    Partition solution;
    judge::run(&solution);
}