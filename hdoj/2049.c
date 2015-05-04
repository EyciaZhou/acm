#include <stdio.h>

int main() {
	int t, i;
	int n, m;
	long long t1, t2;
	long long D[21];
	D[1] = 0;
	D[2] = 1;
	for (i = 3; i <= 20; i++) {
		D[i] = (i-1)*(D[i-1]+D[i-2]);
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		t1 = 1;
		t2 = 1;
		for (i = n; i > n - m; i--) {
			t1 *= i;
		}
		for (i = 1; i <= m; i++) {
			t2 *= i;
		}
		t1 = t1 / t2;
		printf("%lld\n", D[m]*t1);
	}
}