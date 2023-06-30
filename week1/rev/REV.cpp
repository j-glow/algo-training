#include "judge.h"
class REV : public IREV {
public:
	int bitReverse(int value) {
		unsigned int res = 0;
		value = *(unsigned int*) &value;
		for(int i = 31; i>=0 && value; i--){
			res |= (value & 1) << i;
		}
		return *(int*) &res;
	}
};

REV solution;
int main() {
	Judge::run(&solution);
	return 0;
}
