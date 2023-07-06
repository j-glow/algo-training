#include "judge.h"

#include <iostream>
using namespace std;

char s[10][4][4];
char p[10][10];

void judge::run(iLOG *solution) {
    int T, N, tmp;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++) {
                scanf("%d", &tmp);
                p[i][j] = tmp;
            }
        scanf("%d", &N);
        for(int n = 0; n < N; n++){
            for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                scanf("%d", &tmp);
                s[n][i][j] = tmp;
            }
        }
        printf("%d\n", solution->solve(N, p, s));
    }
}