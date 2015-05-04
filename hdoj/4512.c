#include <stdio.h>

int l[300];

int tt(int s1, int e1, int s2, int e2, int limit) {	
	int f[300];
	memset(f, 0, sizeof(f));
	int i, j, m;
	for (i = s1; i <= e1; i++) {
		if (l[i] >= limit) continue;
		m = 0;
		for (j = e2; j >= s2; j--) {
			if (l[j] >= limit) continue;
			if (l[i] == l[j]) {
				if (f[m] + 1 > f[j]) {
					f[j] = f[m] + 1;
				}
			}
			if (l[j] < l[i]) {
				if (f[j] > f[m]) {
					m = j;
				}
			}
		}
	}
	int max = 0;
	for (i = e2; i >= s2; i--) {
		if (f[i] > max) {
			max = f[i];
		}
	}
	return max;
}

int main() {
	int d, n, i, j, res, r;
	scanf("%d", &d);
	while (d--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &(l[i]));
		}
		res = -1;
		for (i = 1; i <= n; i++) {
			r = tt(1, i, i+1, n, 10000);
			if (2 * r > res) {
				res = 2 * r;
			}
			r= tt(1, i-1, i+1, n, l[i]);
			if (2 * r +1 > res) {
				res = 2 * r + 1;
			}
		}
		printf("%d\n", res);
	}
}
