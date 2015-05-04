#include <stdio.h>

long a[100005];
long bin[100005];
long n, d;
long f[100005];
long ff[100005];

long erfen(long target) {
	long l, r, m;
	l = 0; r = n + 4;
	while (l + 1 != r) {
		m = (l + r) / 2;
		if (ff[m] >= target) {
			r = m;
		} else {
			l = m;
		}
	}
	return l;
}

int main() {
	long i, ind, max;
	while (scanf("%ld %ld", &n, &d) != EOF) {
		for (i = 1; i <= n; i++) {
			scanf("%ld", &a[i]);
		}
		for (i = 1; i <= n + 4; i++) {
			ff[i] = 200000;
		}
		a[0] = -1;
		f[i] = 0;
		ff[0] = -1;
		for (i = 1; i <= n; i++) {
			ind = erfen(a[i]);
			f[i] = ind + 1;
			if (i >= d) {
				if (ff[f[i-d]] > a[i-d]) {
					ff[f[i-d]] = a[i-d];
				}
			}
		}
		max = -1;
		for (i = 0; i <= n; i++) {
			if (f[i] > max) {
				max = f[i];
			}
		}
		printf("%ld\n", max);
	}
}