#include <stdio.h>

int main() {
	int n;
	long int m, i, j;
	long int w[105], v[105];
	long int f[100005];
	while (scanf("%d", &n) != EOF) {
		memset(f, 0, sizeof(f));
		for (i = 0; i < n; i++) {
			scanf("%ld %ld", &v[i], &w[i]);
		}
		scanf("%ld", &m);
		for (i = 0; i <= m; i++) {
			for (j = 0; j < n; j++) {
				if (i >= w[j] && f[i - w[j]] + v[j] > f[i]) {
					f[i] = f[i - w[j]] + v[j];
				}
			}
		}
		printf("%ld\n", f[m]);
	}
}
