#include "judge.h"
class TUR : public ITUR {
public:
	int getBestResult(int *board, int size) {
		return -1;
	}
};

TUR solution;
int main() {
	Judge::run(&solution);
	return 0;
}
