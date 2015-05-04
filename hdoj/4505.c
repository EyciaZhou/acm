#include <stdio.h>
#include <stdbool.h>

int main() {
	int c, n, k, i;
	bool v[105];
	scanf("%d", &c);
	for (; c > 0; c--) {
		int max = 0;
		memset(v, false, sizeof(v));
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &k);
			v[k] = true;
			if (k > max) {
				max = k;
			}
		}
		int tot = 0;
		for (i = 0; i <= max; i++) {
			if (v[i]) {
				tot++;
			}
		}
		printf("%d\n", max * 10 + tot * 5 + n);
	}
}
