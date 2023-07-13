#include "judge.h"

class water : public iwater {
public:
	virtual int minMoves(int n, int c[4], int b[4]) { return 0; }
};

int main() {
	water w;
	judge::run(&w);
}
