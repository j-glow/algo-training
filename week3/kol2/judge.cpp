#include "judge.h"
#include <iostream>
using namespace std;

namespace {
	const int M = 200000;
	int n;
	int m;
	int xx[M];
	int yy[M];
}

void Judge::run(IKOL2 *solution) {
	while (true) {
		cin >> n;
		cin >> m;
		if (n == 0) break;
		for (int i=0; i<m; ++i) {
			cin >> xx[i];
			cin >> yy[i];
		}
		bool res = solution->isGraph2Colorable(n, m, xx, yy);
		if (res)
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
}
