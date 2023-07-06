#include "judge.h"
#include <iostream>
using namespace std;

namespace {

	long long cost[15][8];

} // namespace

void Judge::run(INAD *solution) {
	int mode; cin >> mode;

	int tc; cin >> tc;

	for (int t=1; t<=tc; ++t) {
		int n; cin >> n;
		int k; cin >> k;
		for (int i=0; i<n; ++i) for (int j=0; j<k; ++j) cin >> cost[i][j];

		long long res = solution->getMinimumCost(n, k, cost);
		cout << "#" << t << " " << res << "\n";
	}
}

