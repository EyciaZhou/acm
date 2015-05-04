#include <stdio.h>

long long int getmu(long k, long t) {
	if (t == 0) {
		return 1;
	}
	if (t == 1) {
		return k;
	}
	long long temp = getmu(k, t / 2);
	temp = temp * temp % 1000000007;
	if (t % 2 == 1) {
		temp = temp * k % 1000000007;
	}
	return temp;
}

int main() {
	long int tt, n, t, k, i;
	long long tel;
	long long temp;
	long f[10005];
	scanf("%ld", &tt);
	for (; tt > 0; tt--) {
		scanf("%ld %ld %ld", &n, &t, &k);
		long long int mu = getmu(k, t);
		for (i = 0; i < n; i++) {
			scanf("%lld", &tel);
			f[(i + t) % n] = tel * mu % 1000000007;
		}
		for (i = 0; i < n - 1; i++) {
			printf("%I64d ", f[i]);
		}
		printf("%I64d\n", f[n - 1]);
	}
}
