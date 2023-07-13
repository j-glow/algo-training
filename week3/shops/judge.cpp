#include "judge.h"
#include <iostream>
#include <string>
using namespace std;
char theMap[256][256];

void judge::run(iShops *solution) {
    string s;
    for(int i = 0; i < 256; i++) {
        cin >> s;
        for(int j = 0; j < 256; j++) {
            theMap[i][j] = s[j];
        }
    }
    cout << solution->getDistance(theMap) << "\n";
}