#include "judge.h"
#include <iostream>

using namespace std;
static long seed = 0;
static int MOD = 1000000007;

static int pseudo_rand() {
	seed = seed * 13477581 + 1;
	return(((int)seed) & 0x7FFFFFFF) % MOD;
}

void Judge::run(IContainer* k) {
	ios_base::sync_with_stdio(false);
	char type;
	int size, operations;

	cin >> type;

	long long  hash = 0;
	if (type == 'R') {
		cin >> size >> operations >> seed;
		k->init(size);
		for (int o = 0; o < operations; o++) {
			int which = pseudo_rand() % 3;
			bool ret;
			if (which == 0) {
				ret = k->add(pseudo_rand() % size);
			} else if (which == 1) {
				ret = k->contains(pseudo_rand() % size);
			} else {
				ret = k->remove(pseudo_rand() % size);
			}
			hash = ((10009 * hash) + (ret ? 1 : 0)) % 1000000007;


		}
	} else {
		cin >> size >> operations;
		k->init(size);
		char which;
		int a;
		for (int o = 0; o < operations; o++) {
			cin >> which >> a;
			bool ret;
			if (which == 'A') {
				ret = k->add(a);
			} else if (which == 'C') {
				ret = k->contains(a);
			} else {
				ret = k->remove(a);
			}
			hash = ((10009 * hash) + (ret ? 1 : 0)) % 1000000007;

		}
	}



	cout << hash << "\n";


}
