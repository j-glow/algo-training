#include "judge.h"
#include <iostream>
#include <string>
using namespace std;

long long seed;
int pseudoRand() {
    seed = seed * 134775813 + 1;
    return (seed >> 33) & 0x7FFFFFFF;
}

string randomCity() {
    int maxLen = 10;
    const char* vowels = "aeiouy"; // 6
    const char* consonants = "bcdfghjklmnprstvwxz"; // 19

    unsigned len = 3 + pseudoRand() % (maxLen - 3);
    string s(len, '\0');
    s[0] = consonants[pseudoRand() % 19] + 'A' - 'a';
    for (unsigned i = 1; i < len; i++) {
        if (i & 1) s[i] = vowels[pseudoRand() % 6];
        else s[i] = consonants[pseudoRand() % 19];
	}
    return s;
}

const int MAX_N = 1000;
const int MAX_M = 10000;
string cities[MAX_N];
const char* a[MAX_M];
const char* b[MAX_M];

void judge::run(iBFS *solution) {
    int T, N, M, s;
    scanf("%d %d %d %d", &T, &N, &M, &s);
    seed = s;

    for (int tc = 1; tc <= T; tc++) {
        for (int i = 0; i < N; i++) {
            cities[i] = randomCity();
        }

        const char *start = cities[0].c_str();
        const char *end = cities[N - 1].c_str();

        int path = pseudoRand() % (N - 1);
        for (int i = 0; i < path; i++) {
            a[i] = cities[i].c_str();
            b[i] = cities[i + 1].c_str();
        }

        for (int i = path; i < M; i++) {
            int x = pseudoRand() % N;
            int y = pseudoRand() % (N - 1);
            if (y == x) y = N - 1;
            a[i] = cities[x].c_str();
            b[i] = cities[y].c_str();
        }

        int answer = solution->solve(N, M, start, end, a, b);
        printf("%d: %d\n", tc, answer);
    }
}
