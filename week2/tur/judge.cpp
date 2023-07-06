#include "judge.h"
#include <cstdio>

struct Scanner {
	static int nextInt() {
		int n;
		scanf("%d", &n);
		return n;
	}
};
Scanner sc;

int board[64];

void Judge::run(ITUR *solution) {
	while (true) {
		int size = sc.nextInt();
		if (0 == size) break;
		for (int i=0; i<size; ++i)
			board[i] = sc.nextInt();
		int res = solution->getBestResult(board, size);
		printf("%d\n", res);
	}
}

