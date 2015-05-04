#include <stdio.h>

int fa[1445];

int getfather(int i) {
	if (fa[i] == i) {
		return i;
	}
	int r = getfather(fa[i]);
	fa[i] = r;
	return r;
}

int main() {
	long int n, i;
	int s1, s2, e1, e2, fs;
	while (scanf("%ld", &n) != EOF) {
		for (i = 0; i < 1445; i++) {
			fa[i] = i;
		}
		for (i = 0; i < n; i++) {
			scanf("%d:%d %d:%d", &s1, &s2, &e1, &e2);
			s1 = s1 * 60 + s2;
			e1 = e1 * 60 + e2;
			while (s1 <= e1) {
				s1 = getfather(s1);
				if (s1 + 1 <= e1) {
					fa[s1] = s1 + 1;
				}
				s1 = s1 + 1;
			}
		}
		int tot = 0;
		for (i = 0; i < 1440; i++) {
			if (getfather(i) == i) {
				tot++;
			}
		}
		printf("%d\n", tot);/*
		for (i = 0; i < 1440; i++) {
			printf("%d	%d\n", i, getfather(i) == i);
		}*/
	}
}
