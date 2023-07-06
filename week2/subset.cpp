#include <cstdio>

#include <string>
using namespace std;

string s;
string subset;

void genSubset(int pos) { // s[pos..]
	if (pos >= s.size()) {
		printf("next subset: %s\n", subset.c_str());
		return;
	}

	// co robimy z literka s[pos]?

	// opcja 2: nie dodajemy do podzbioru
	genSubset(pos + 1);

	// opcja 1: dodajemy do podzbioru
	subset.push_back(s[pos]);
	genSubset(pos + 1);
	subset.pop_back();
}


int main() {
	s = string("ABCDE");
	genSubset(0);

	return 0;
}

