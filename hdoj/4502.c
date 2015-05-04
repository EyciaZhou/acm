#include <stdio.h>
#include <stdbool.h>

typedef struct nn {
	int s;
	int e;
	long int c;
} ;

int main() {
	int t, m, n, i, j;
	long int tt[105];
	struct nn s[1000], te;
	scanf("%d", &t);
	for (; t > 0; t--) {
		memset(tt, 0, sizeof(tt));
		scanf("%d %d", &m, &n);
		for (i = 0; i < n; i++) {
			scanf("%d %d %ld", &s[i].s, &s[i].e, &s[i].c);
		}
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				if (s[i].e > s[j].e) {
					te = s[i];
					s[i] = s[j];
					s[j] = te;
				}
			}
		}
		for (j = 0; j < n; j++) {
			long int max = 0;
			for (i = 0; i < s[j].s; i++) {
				if (tt[i] > max) {
					max = tt[i];
				}
			}
			if (s[j].c + max > tt[s[j].e]) {
				tt[s[j].e] = s[j].c + max;
			}
		}
		long int max = 0;
		for (i = 0; i <= m; i++) {
			if (tt[i] > max) {
				max = tt[i];
			}
		}
		printf("%ld\n", max);
	}
}