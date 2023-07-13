#include "judge.h"
#include <cstdio>
#include <cstdlib>

namespace {
	int nextInt() { int n; scanf("%d", &n); return n; }
	char buf1[4096];
	char buf2[4096];
}

void Judge::run(IMSD *solution) {
	int tc = 0;
	while (true) {
		int cmd = nextInt();
		if (0 == cmd) break;
		if (1 == cmd) {
			++tc;
			solution->init();
			printf("#%d\n", tc);
		}
		if (2 == cmd) {
			scanf("%s%s", buf1, buf2);
			solution->makeDir(buf1, buf2);
		}
		if (3 == cmd) {
			scanf("%s%s", buf1, buf2);
			solution->makeLink(buf1, buf2);
		}
		if (4 == cmd) {
			scanf("%s", buf1);
			solution->makeSystemFile(buf1);
		}
		if (5 == cmd) {
			solution->getMostSafeDir(buf1);
			bool ok = false;
			int cnt = nextInt();
			for (int i=0; i<cnt; ++i) {
				scanf("%s", buf2);
				if (ok) continue;
				bool testok = true;
				for (int j=0; testok; ++j) {
					if (buf1[j] != buf2[j]) testok = false;
					if (buf2[j] == 0) break;
				}
				if (testok) ok = true;
			}
			if (ok) {
				printf("OK\n");
			} else {
				printf("ERR: %s\n", buf1);
			}
		}
	}
}
