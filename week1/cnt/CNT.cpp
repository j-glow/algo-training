#include "judge.h"

class CNT : public ICNT {
public:
	int popCount(int value) {
		return __builtin_popcount(value);
	}
};

CNT solution;
int main() {
	Judge::run(&solution);
	return 0;
}
