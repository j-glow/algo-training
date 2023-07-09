#include <algorithm>
#include <cstdio>

#include "judge.h"

#define STAMP_SIZE 4
#define LOGO_SIZE 10

class LOG : public iLOG {
   public:
    virtual int solve(int n, char logo[LOGO_SIZE][LOGO_SIZE], char stamps[][STAMP_SIZE][STAMP_SIZE]) {
        if(n==0 && check_logo()) return -1;
        
        char curr[10][10];
        for (int row = 0; row < LOGO_SIZE - STAMP_SIZE; row++) {
            for (int col = 0; col < LOGO_SIZE - STAMP_SIZE; col++) {
                curr[row][col]
            }
        }

        // SKIP STAMP
        solve(n-1, logo, stamps + 1);

        // DONT SKIP STAMP
        for (int i = 0; i < 4; i++) { // ALL POSSIBLE ROTATIONS
            for (int row = 0; row < LOGO_SIZE - STAMP_SIZE; row++) {
                for (int col = 0; col < LOGO_SIZE - STAMP_SIZE; col++) {
                    
                }
            }
            rotate(stamps[0]);
        }
    }

    void insert_stamp(int row0, int col0, char logo[LOGO_SIZE][LOGO_SIZE], char stamp[STAMP_SIZE][STAMP_SIZE]) {
        for (int row = 0; row < STAMP_SIZE; row++) {
            for (int col = 0; col < STAMP_SIZE; col++) {
                if(stamp[row][col]==1 ) 
            }
        }
    }

    void rotate(char stamp[STAMP_SIZE][STAMP_SIZE]) {  // CLOCKWISE ROTATION
        // TRANSPOSE
        for (int row = 0; row < STAMP_SIZE; row++) {
            for (int col = row; col < STAMP_SIZE; col++) {
                std::swap(stamp[row][col], stamp[col][row]);
            }
        }
        // REVERSE ROWS
        for (int row = 0; row < STAMP_SIZE; row++) {
            for (int col = 0; col <= STAMP_SIZE / 2; col++) {
                std::swap(stamp[row][col], stamp[row][STAMP_SIZE - 1 - col]);
            }
        }
    }

    bool check_logo(char logo[LOGO_SIZE][LOGO_SIZE]) {
        for (int row = 0; row < LOGO_SIZE; row++) {
            for (int col = 0; col < LOGO_SIZE; col++) {
                if (logo[row][col]==1) return false;
            }
        }
        return true;
    }
};

LOG solution;

int main() {
    judge::run(&solution);
    return 0;
}