#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int f[105][105][105][6];

int main() {
	int n, v1, v2, kk, k, i, j, l;
	int a[105] = {0}, b[105] = {0}, v[105] = {0};
	while (true) {
		memset(f, 0, sizeof(f));
		if (scanf("%d %d %d %d", &n, &v1, &v2, &kk) == EOF) {
			break;
		}
		for (i = 1; i <= n; i++) {
			scanf("%d %d %d", &a[i], &b[i], &v[i]);
		}
		
		for (i = 1; i <= n; i++) {
		for (l = 0; l <= kk; l++) {
			for (j = 0; j <= v1; j++) {
				for (k = 0; k <= v2; k++) {
					f[i][j][k][l] = f[i-1][j][k][l];
					if (j >= a[i]) {
						if (f[i][j][k][l] < f[i - 1][j - a[i]][k][l] + v[i]) {
							f[i][j][k][l] = f[i - 1][j - a[i]][k][l] + v[i];
						}
					}
					if (k >= b[i]) {
						if (f[i][j][k][l] < f[i - 1][j][k - b[i]][l] + v[i]) {
							f[i][j][k][l] = f[i - 1][j][k - b[i]][l] + v[i];
						}
					}
					if (l > 0) {
						if (f[i][j][k][l] < f[i - 1][j][k][l - 1] + v[i]) {
							f[i][j][k][l] = f[i - 1][j][k][l - 1] + v[i];
						}
					}
				}
			}
		}
		}
		printf("%d\n", f[n][v1][v2][kk]);
	}
	return 0;
}