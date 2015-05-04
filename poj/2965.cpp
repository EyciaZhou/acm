#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

struct node {
	long date;
	long step;
	long x;
	long y;
	long p;

	
};
bool v[70000];
struct node list[70000];

void printTrack(long nownode) {
	if (list[nownode]. p == -1) {
		return;
	}
	printTrack(list[nownode].p);
	cout << 3 - list[nownode].x + 1 << " " << 3 - list[nownode].y + 1 << endl;
}

long did(long raw, long i, long j) {
	j = 3 - j;
	i = 3 - i;
	raw = raw ^ ((16 - 1) << (i * 4));
	for (int k = 0; k < 4; k++) {
		raw = raw ^ (1 << (k * 4 + j));
	}
	raw = raw ^ (1 << (i * 4 + j));
	return raw;
}

int main() {
	long start = 0;
	memset(v, false, sizeof(v));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			start = (start << 1);
			if (getchar() == '+') {
				start += 1;
			}
		}
		getchar();
	}
	list[0].date = start;
	list[0].p = -1;
	list[0].step = 0;
	list[0].x = 0;
	list[0].y = 0;
	long h = 0, t = 0;
	v[start] = true;
	if (start == 0) {
		cout << 0 << endl;
		return 0;
	}
	while (true) {
		struct node *k = &(list[t]);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				long raw = k->date;
				raw = raw ^ ((16 - 1) << (i * 4));
				for (int l = 0; l < 4; l++) {
					raw = raw ^ (1 << (l * 4 + j));
				}
				raw = raw ^ (1 << (i * 4 + j));

				if (!v[raw]) {
					h++;
					list[h].date = raw;
					list[h].step = k->step + 1;
					list[h].x = i;
					list[h].y = j;
					list[h].p = t;
					v[raw] = true;
				}
				if (raw == 0) {
					printf("%ld\n", k->step + 1);
					printTrack(h);
					return 0;
				}
			}
		}
		t++;
	}
}