#include "judge.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

void Judge::run(ISUD *solution) {
	int mode; cin >> mode;

	int board[9][9];

	for (int i=0; i<9; ++i) {
		string s; cin >> s;
		for (int j=0; j<9; ++j) board[i][j] = s[j] - '0';
	}

	solution->solve(board);

	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j)
			cout << board[i][j];
		cout << "\n";
	}
}

