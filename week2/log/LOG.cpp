#include <algorithm>
#include <cstdio>

#include "judge.h"

#define STAMP_SIZE 4
#define LOGO_SIZE 10

class LOG : public iLOG {
    int best_result = -1;

   public:
    virtual int solve(int n,
                      char logo[LOGO_SIZE][LOGO_SIZE],
                      char stamps[][STAMP_SIZE][STAMP_SIZE]) {
        best_result = -1;
        iterate(n, logo, stamps, 0);
        return best_result;
    }

    void iterate(int n,
                 char logo[LOGO_SIZE][LOGO_SIZE],
                 char stamps[][STAMP_SIZE][STAMP_SIZE],
                 int count) {
        if (check_logo(logo)){ // IF LOGO READY UPDATE RESULTS
            if(best_result==-1 || count<best_result) best_result=count;  
        }
        if(n==0) return;

        // SKIP STAMP
        iterate(n - 1, logo, stamps, count);

        // DONT SKIP STAMP
        for (int i = 0; i < 4; i++) {                                         // ALL POSSIBLE ROTATIONS
            for (int row = 0; row < LOGO_SIZE - STAMP_SIZE + 1; row++) {      // ITERATE LOGO OVER ROWS
                for (int col = 0; col < LOGO_SIZE - STAMP_SIZE + 1; col++) {  // ITERATE LOGO OVER COLS
                    if (check_stamp(row, col, logo, stamps[n - 1])) {         // IF STAMP MATCHES THE PLACE
                        insert_stamp(row, col, logo, stamps[n - 1]);          // INSERT IT
                        iterate(n - 1, logo, stamps, count + 1);
                        remove_stamp(row, col, logo, stamps[n - 1]);  // IF NOT REMOVE STAMP AND TRY ANTOHER PLACE
                    }
                }
            }
            rotate(stamps[n - 1]);
        }
    }

    void insert_stamp(int row0, int col0,
                      char logo[LOGO_SIZE][LOGO_SIZE],
                      char stamp[STAMP_SIZE][STAMP_SIZE]) {
        for (int row = 0; row < STAMP_SIZE; row++) {
            for (int col = 0; col < STAMP_SIZE; col++) {
                if (stamp[row][col] == 1) logo[row + row0][col + col0]++;
            }
        }
    }

    void remove_stamp(int row0, int col0,
                      char logo[LOGO_SIZE][LOGO_SIZE],
                      char stamp[STAMP_SIZE][STAMP_SIZE]) {
        for (int row = 0; row < STAMP_SIZE; row++) {
            for (int col = 0; col < STAMP_SIZE; col++) {
                if (stamp[row][col] == 1) logo[row + row0][col + col0]--;
            }
        }
    }

    // CLOCKWISE ROTATION
    void rotate(char stamp[STAMP_SIZE][STAMP_SIZE]) {
        // TRANSPOSE
        for (int row = 0; row < STAMP_SIZE; row++) {
            for (int col = row; col < STAMP_SIZE; col++) {
                std::swap(stamp[row][col], stamp[col][row]);
            }
        }
        // REVERSE ROWS
        for (int row = 0; row < STAMP_SIZE; row++) {
            for (int col = 0; col < STAMP_SIZE / 2; col++) {
                std::swap(stamp[row][col], stamp[row][STAMP_SIZE - 1 - col]);
            }
        }
    }

    // CHECK IF LOGO IS FULLY STAMPED
    bool check_logo(char logo[LOGO_SIZE][LOGO_SIZE]) {
        for (int row = 0; row < LOGO_SIZE; row++) {
            for (int col = 0; col < LOGO_SIZE; col++) {
                if (logo[row][col] == 1) return false;
            }
        }
        return true;
    }

    // CHECK IF STAMP FITS
    bool check_stamp(int row0, int col0,
                     char logo[LOGO_SIZE][LOGO_SIZE],
                     char stamp[STAMP_SIZE][STAMP_SIZE]) {
        for (int row = 0; row < STAMP_SIZE; row++) {
            for (int col = 0; col < STAMP_SIZE; col++) {
                if (logo[row + row0][col + col0] == 0 && stamp[row][col] == 1) return false;
            }
        }
        return true;
    }

    void display_stamp(char stamp[STAMP_SIZE][STAMP_SIZE]) {
        for (int row = 0; row < STAMP_SIZE; row++) {
            for (int col = 0; col < STAMP_SIZE; col++) {
                printf("%d ", stamp[row][col]);
            }
            printf("\n");
        }
    }
};

LOG solution;

int main() {
    // char stamp[4][4] = {{0, 0, 0, 1},
    //                     {0, 1, 1, 1},
    //                     {0, 1, 0, 1},
    //                     {0, 1, 1, 1}};
    // solution.rotate(stamp);
    // return 0;
    judge::run(&solution);
    return 0;
}