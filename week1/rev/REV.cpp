#include "judge.h"

class REV : public IREV {
   public:
    int bitReverse(int value) {
        unsigned int res = 0;
        value = *(unsigned int*)&value;


        for (unsigned int i = 0; i<32 && value; i++) {
            res |= (value & 1) << (31 - i);
            value >>= 1;
        }

        return *(int*)&res;
    }
};

REV solution;
int main() {
    Judge::run(&solution);
    return 0;
}