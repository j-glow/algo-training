#include <fstream>
#include <iostream>
#include <vector>

#include "judge.h"

class TUR : public ITUR {
    int best_result;

   public:
    int getBestResult(int* board, int size) {
        best_result = INT32_MIN;
        play(board, size, 3);
        return best_result;
    }
    void play(int* board, int size, int depth) {
        if (depth == 0) {
            int result = calculate_points(board, size);
            if (result > best_result) best_result = result;
            return;
        }
        for (int i = 0; i < size; i++) {
            if (board[i] != 0) continue;
            int new_board[size];
            copy_board(new_board, board, size);
            update_board(new_board, size, i, 1);
            int enemy_move = get_enemy_move(new_board, size);
            update_board(new_board, size, enemy_move, 2);
            play(new_board, size, depth - 1);
        }
    }

    int get_enemy_move(int* board, int size) {
        int min = INT32_MAX;
        int move = -1;
        int new_board[size];
        for (int i = 0; i < size; i++) {
            if (board[i] != 0) continue;
            copy_board(new_board, board, size);
            update_board(new_board, size, i, 2);
            int cur = calculate_points(new_board, size);
            if (cur < min) {
                min = cur;
                move = i;
            }
        }
        return move;
    }
    void update_board(int* board, int size, int place, int stone) {
        int ptr = place;
        board[place] = stone;

        bool fill = false;
        // SCAN BELOW
        do {
            ptr--;
        } while (ptr >= 0 && board[ptr] != stone && board[ptr] != 0);
        if (ptr < 0 || board[ptr] == stone) fill = true;

        // FILL WHILE GOING BACK UP
        do {
            ptr++;
            if (fill) board[ptr] = stone;
        } while (ptr != place);

        fill = false;
        // SCAN OVER
        do {
            ptr++;
        } while (ptr < size && board[ptr] != stone && board[ptr] != 0);
        if (ptr >= size || board[ptr] == stone) fill = true;

        // FILL WHILE GOING DOWN
        do {
            ptr--;
            if (fill) board[ptr] = stone;
        } while (ptr != place);
    }

    int calculate_points(int* board, int size) {
        int points = 0;
        for (int i = 0; i < size; i++) {
            if (board[i] == 1) points++;
            if (board[i] == 2) points--;
        }
        return points;
    }

    void copy_board(int* new_board, int* board, int size) {
        for (int i = 0; i < size; i++) {
            new_board[i] = board[i];
        }
    }
};

TUR solution;
int main() {
    //freopen("in/TUR0a.in", "r", stdin);
    Judge::run(&solution);
    return 0;
}
