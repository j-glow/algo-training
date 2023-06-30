#include "judge.h"
#define MAX_PEOPLE 64

class Friends : public iFriends {
    long long contacts[MAX_PEOPLE];

    public:

	void addFriend(int a, int b) {
        contacts[a] |= 1ll << b;
        contacts[b] |= 1ll << a;
    }
	
    bool haveCommonFriend(int a, int b) {
        for(int i = 0; i<MAX_PEOPLE; i++){
            if(i==a || i==b) continue;
            if((contacts[a]>>i & 1) && (contacts[b]>>i & 1)) return true;
        }
        return false;
    }
};

Friends solution;

int main() {
    judge::run(&solution);
    return 0;
}