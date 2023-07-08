#include <algorithm>
#include <cstdio>

#include "judge.h"

#define STAMP_SIZE 4
#define LOGO_SIZE 10

class LOG : public iLOG {
   public:
    virtual int solve(int n, char logo[LOGO_SIZE][LOGO_SIZE], char stamps[][STAMP_SIZE][STAMP_SIZE]) {
        // INIT EMPTY
        char empty[10][10];
        for (int row = 0; row < LOGO_SIZE; row++) {
            for (int col = 0; col < LOGO_SIZE; col++) {
                empty[row][col] = 0;
            }
        }
        return n-solver(logo, empty, stamps, n);
    }
    int solver(char logo[LOGO_SIZE][LOGO_SIZE],
               char logo_new[LOGO_SIZE][LOGO_SIZE],
               char stamps[][STAMP_SIZE][STAMP_SIZE],
               int n) {
        // if no more stamps left and logo isnt filled return -1
        if (n == 0 & check_logo(logo, logo_new)) return -1;

        char curr[10][10];
        for (int row = 0; row < LOGO_SIZE; row++) {
            for (int col = 0; col < LOGO_SIZE; col++) {
                curr[row][col] = logo_new[row][col];
            }
        }

        // ROTATIONS CALL LOOP
        for (int i = 0; i < 4; i++) {
            for (int row = 0; row < LOGO_SIZE - STAMP_SIZE; row++) {
                for (int col = 0; col < LOGO_SIZE - STAMP_SIZE; col++) {
                    bool check = insert_stamp(row, col, logo, stamps[0], curr);
                    if (check) solver(logo, curr, stamps + 1, n - 1);
                    if (check_logo(logo,curr)) return n;
                }
            }

            rotate(stamps[0]);
        }

        // SKIP STAMP CALL
        solver(logo, logo_new, stamps + 1, n - 1);
    }
    bool insert_stamp(int row0, int col0, char logo[LOGO_SIZE][LOGO_SIZE], char stamp[STAMP_SIZE][STAMP_SIZE], char curr[LOGO_SIZE][LOGO_SIZE]) {
        for (int row = 0; row < LOGO_SIZE; row++) {
            for (int col = 0; col < LOGO_SIZE; col++) {
                if (stamp[row][col] == 1 && logo[row + row0][col + col0]) return false;
            }
        }
        for (int row = 0; row < LOGO_SIZE; row++) {
            for (int col = 0; col < LOGO_SIZE; col++) {
                curr[row + row0][col + col0] = stamp[row][col];
            }
        }
        return true;
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

    bool check_logo(char logo[LOGO_SIZE][LOGO_SIZE], char check[LOGO_SIZE][LOGO_SIZE]) {
        for (int row = 0; row < LOGO_SIZE; row++) {
            for (int col = 0; col < LOGO_SIZE; col++) {
                if (logo[row][col] != check[row][col]) return false;
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