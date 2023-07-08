#include "judge.h"

class SUD : public ISUD {
   public:
    void solve(int t[9][9]) {
        int place = find_empty(t);
		int row = place / 9;
		int col = place % 9;
		for(int num = 1; num<=9;num++){
			if(check_num(t, row, col, num)){
				t[row][col] = num;
				solve(t);
				t[row][col] = 0;
			}
		}
		return;
    }
	
	int find_empty(int t[9][9]){
		for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (t[row][col]==0) return row*9+col;
            }
        }
	}

    bool check_num(int t[9][9], int row, int col, int num) {
        int block_row = row - row % 3;
        int block_col = col - col % 3;
        for (int i = 0; i < 9; i++) {
            if (t[row][i] == num) return false;
        }
        for (int i = 0; i < 9; i++) {
            if (t[i][col] == num) return false;
        }
        for (int row = block_row; row < block_row + 3; row++) {
            for (int col = block_col; col < block_col + 3; col++) {
                if (t[row][col] == num) return false;
            }
        }
        return true;
    }
};

SUD solution;
int main() {
    Judge::run(&solution);
    return 0;
}
