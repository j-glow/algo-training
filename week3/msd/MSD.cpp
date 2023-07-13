#include "judge.h"

class MSD : public IMSD {
public:
	void init() {
	}

	void makeDir(char *path, char *name) {
	}

	void makeLink(char *pathSrc, char *pathDst) {
	}

	void makeSystemFile(char *path) {
	}

	void getMostSafeDir(char *result) {
	}
};


MSD solution;
int main() {
	Judge::run(&solution);
	return 0;
}

