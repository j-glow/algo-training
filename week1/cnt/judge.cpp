#include "judge.h"
#include <cstdio>
#include <cstdlib>

namespace {
	int nextInt() { int n; scanf("%d", &n); return n; }
	long long seed;
	int nextRand() {
		seed = seed * 134775813 + 1;
		return ((seed >> 31) & 0xFFFFFFFFLL);
	}
	long long h;
	void hashAdd(int value) {
		h = h * 10007 + value;
	}
}

void Judge::run(ICNT *solution) {
	seed = nextInt();
	int TC = nextInt();
	int mask = nextInt();
	int fullOut = nextInt();
	h = nextRand();

	for (int tc=1; tc<=TC; ++tc) {
		int value = nextRand() & mask;
		int res = solution->popCount(value);
		hashAdd(res);
		if (fullOut > 0) {
			printf("#%d: %d -> %d\n", tc, value, res);
		}
	}
	printf("Hash: %lld\n", h);
}
