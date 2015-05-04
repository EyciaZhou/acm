#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
	while (true) {
		int m, n, i, j, k;
		int max = 0, mi, mj;
		int v[25][25];
		int s;
		int ji[4] = {0, 1, -1, 0};
		int jj[4] = {1, 0, 0, -1};
		memset(v, 0, sizeof(v));
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			break;
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				scanf("%d", &v[i][j]);
			}
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				s = 0;
				for (k = 0; k < 4; k++) {
					s += v[i + ji[k]][j + jj[k]];
				}
				if (v[i][j] > 0) {
					s = -s;
				}
				if (s > max) {
					max = s;
					mi = i;
					mj = j;
				}
			}
		}
		printf("%d %d %d\n", mi, mj, max);
	}
	return 0;
}