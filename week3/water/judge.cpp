#include "judge.h"
#include <iostream>
using namespace std;

void judge::run(iwater *c) {
	int n;
	int o[4], w[4];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> o[i];
	for (int i = 0; i < n; ++i) cin >> w[i];
	cout << c->minMoves(n, o, w) << "\n";
}