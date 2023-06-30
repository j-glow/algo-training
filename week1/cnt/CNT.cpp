#include "judge.h"
#include <fstream>

class CNT : public ICNT {
public:
	int popCount(int value) {
		int res = 0;
		unsigned int x = *(unsigned int*) &value;
		while(value){
			res += x & 1;
			x >>= 1;
		}
		return res;
	}
};

CNT solution;
int main() {
	freopen("out.txt", "w+", stdout);
	Judge::run(&solution);
	return 0;
}
