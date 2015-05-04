#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void deal(long a, long b, long i) {
	long k = b / i;
	if (k % 2 == 0) {
		if (i % 2 == 0) {
			return;
		}
		long l = (i - k + 1) / 2;
		long r = (i + k - 1) / 2;
		if (l >= 1 && r <= a) {
			printf("[%ld,%ld]\n", l, r);
		}
		return;
	}
	long l = (i - k + 1) / 2;
	long r = (i + k) / 2;
	if (l >= 1 && r <= a) {
		printf("[%ld,%ld]\n", l, r);
	}
}

int main() {
	long int a, b;
	while (true) {
		scanf("%ld %ld", &a, &b);
		if (a == 0 && b == 0) {
			return 0;
		}
		b = 2 * b;
		long int i, sb = (long int)sqrt(b);
		for (i = 2; i < sb; i++) {
			if (b % i == 0) {
				deal(a, b, i);
			}
		}
		for (i = sb; i >= 1; i--) {
			if (b % i == 0) {
				deal(a, b, b / i);
			}
		}
		printf("\n");
	}
}