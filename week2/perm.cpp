#include <cstdio>

#include <string>
using namespace std;

string s;

void genPerm(int pos) { // s[pos..]
	if (pos >= s.size()) {
		printf("next perm: %s\n", s.c_str());
		return;
	}

	for (int i = pos; i < s.size(); ++i) {
		// na pozycje pos wkladamy s[i]
		std::swap(s[i], s[pos]);
		genPerm(pos + 1);
		std::swap(s[i], s[pos]);
	}
}


int main() {
	s = string("ABCD");
	genPerm(0);

	return 0;
}

