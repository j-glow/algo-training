#include "judge.h"

class REV : public IREV {
   public:
    int bitReverse(int value) {
        value = *(unsigned int*)&value;

        value = ((value & 0xffff0000) >> 16) | ((value & 0x0000ffff) << 16);
        value = ((value & 0xff00ff00) >> 8) | ((value & 0x00ff00ff) << 8);
        value = ((value & 0xf0f0f0f0) >> 4) | ((value & 0x0f0f0f0f) << 4);
        value = ((value & 0xcccccccc) >> 2) | ((value & 0x33333333) << 2);
        value = ((value & 0xaaaaaaaa) >> 1) | ((value & 0x55555555) << 1);

        return *(int*)&value;
    }
};

REV solution;
int main() {
    Judge::run(&solution);
    return 0;
}