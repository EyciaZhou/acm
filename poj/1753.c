#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool v[70000];
long l[70000];
long s[70000];

long temp[4][4];

long check(long k, long ii, long jj) {
	int si = 0, ei = 2, sj = 0, ej = 2;
	long i, j, t;
	if (ii == 0) {
		si = 1;
	}
	if (ii == 3) {
		ei = 1;
	}
	if (jj == 0) {
		sj = 1;
	}
	if (jj == 3) {
		ej = 1;
	}
	for (i = 3; i >= 0; i--) {
		for (j = 3; j >= 0; j--) {
			temp[i][j] = (k & 1);
			k = (k >> 1);
		}
	}
	for (i = si; i <= ei; i++) {
		temp[i + ii - 1][jj] = 1 - temp[i + ii - 1][jj];
	}
	for (i = sj; i <= ej; i++) {
		temp[ii][i + jj - 1] = 1 - temp[ii][i + jj - 1]; 
	}
	temp[ii][jj] = 1 - temp[ii][jj];
	t = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			t += temp[i][j];
			t = (t << 1);
		}
	}
	t = (t >> 1);
	return t;
}

long bfs(long start) {
	long h = 0, w = 0;
	long k, i, j, t;
	memset(l, 0, sizeof(l));
	memset(s, 0, sizeof(s));
	l[0] = start;
	v[start] = true;
	s[0] = 0;
	if (start == 0 || start == 65535) {
		return 0;
	}
	while ((h + 1) % 70000 != w) {

		k = l[w];
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				t = check(k, i, j);
				if (t == 0 || t == 65535) {
					return s[w] + 1;
				}
				if (!v[t]) {
					h = (h + 1) % 70000;
					l[h] = t;
					v[t] = true;
					s[h] = s[w] + 1;
				}
			}
		}
		w = (w + 1) % 70000;
	}
	return -1;
}

int main() {
	int i, j;
	char c;
	long tot = 0;
	memset(v, 0, sizeof(v));
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			c = getchar();
			tot = (tot << 1);
			if (c == 'b') {
				tot += 1;
			}
		}
		getchar();
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			check(51200, i, j);
		}
	}

	tot = bfs(tot);
	if (tot == -1) {
		printf("Impossible\n");
	}else {
		printf("%ld\n", tot);
	}
}