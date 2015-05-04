#include <stdio.h>
#include <stdbool.h>

int main() {
	int t, m, n, s, e, i;
	long int tt[105], c;
	scanf("%d", &t)
	for (; t > 0; t--) {
		memset(tt, 0, sizeof(tt));
		scanf("%d %d", &m, &n);
		for (; n > 0; n--) {
			scanf("%d %d %ld", &s, &e, &c);
			long int max = 0;
			for (i = 0; i < s; i++) {
				if (t[i] > max) {
					max = t[i];
				}
			}
			if (c + max > t[e]) {
				t[e] = c + max;
			}
		}
		long int max = 0;
		for (i = 0; i < m; i++) {
			if (t[i] > max) {
				max = t[i]
			}
		}
		printf("%ld", max);
	}
}