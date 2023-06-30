#include "judge.h"
#include <iostream>
using namespace std;

void judge::run(iPartition* solution){
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		int* array = new int[N];
		for(int i=0;i<N;i++) {
			cin >> array[i];
		}
		bool ans = solution->checkPartition(array, N);
		cout << (ans ? 1 : 0) << "\n";
	}
}