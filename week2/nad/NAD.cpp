#include <malloc.h>

#include "judge.h"

class NAD : public INAD {
    bool workers_used[15];
    long long min;
    long long cur;

   public:
    long long getMinimumCost(int n, int k, long long c[15][8]) {
        min = __LONG_LONG_MAX__;
        for (int i = 0; i < 15; i++) workers_used[i] = false;

        iterate(n, k, c, 0);

        return min;
    }
    void iterate(int worker_count, int task_count, long long c[15][8], int task) {
        if (cur > min) return;
        if (task == task_count) {
            min = cur;
            return;
        }

        for (int worker = 0; worker < worker_count; worker++) {
            if (workers_used[worker]) continue;

            workers_used[worker] = true;
            cur += c[worker][task];

            iterate(worker_count, task_count, c, task + 1);

            cur -= c[worker][task];
            workers_used[worker] = false;
        }
    }
};

NAD solution;
int main() {
    Judge::run(&solution);
    return 0;
}
