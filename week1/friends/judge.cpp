#include "judge.h"
#include <cstdio>

void judge::run(iFriends *solution) {
    int n, a, b;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        solution->addFriend(a, b);
    }

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", solution->haveCommonFriend(a, b) ? 1 : 0);
    }
}