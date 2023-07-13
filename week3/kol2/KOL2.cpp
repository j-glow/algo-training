#include "judge.h"

class KOL2 : public IKOL2 {
public:
	bool isGraph2Colorable(int vertexCount, int edgeCount, int *edge1, int *edge2) {
		return false;
	}
};

KOL2 solution;
int main() {
	Judge::run(&solution);
	return 0;
}
