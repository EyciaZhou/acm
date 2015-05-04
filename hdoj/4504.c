#include <stdio.h>

int main() {
	int a, b, t, i, j;
	long long int f[21][260] = {0}, tot;
	while (scanf("%d %d %d", &a, &b, &t) != EOF) {
		tot = 0;
		for (i = 0; i < 21; i++) {
			for (j = 0; j < 260; j++) {
				f[i][j] = 0;
			}
		}
		b += (t) / 30;
		t = (t + 15) / 30;
		a = b - a;

		f[0][0] = 1;
		for (i = 1; i <= t; i++) {
			for (j = 1; j <= t * 3; j++) {
				f[i][j] += f[i - 1][j - 1];
				if (j >= 2) {
					f[i][j] += f[i - 1][j - 2];
				}
				if (j >= 3) {
					f[i][j] += f[i - 1][j - 3];
				}
			}
		}
		long long tot = 0;
		if (a < 0) {
			a = -1;
		}
		for (i = a + 1; i <= t * 3; i++) {
			tot += f[t][i];
		}
		printf("%I64d\n", tot);
	}
	return 0;
}
