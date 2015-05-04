#include <stdio.h>

int main() {
	int d;
	long int f, f2;
	int i;
	long k1, k2;
	scanf("%d\n", &d);
	for (; d > 0; d--) {
		k2 = 0;
		scanf("%ld", &f);
		k1 = f * (f - 1) * (f - 2) / 6;
		for (i = 0; i < f; i++) {
			scanf("%ld", &f2);
			k2 += f2 * (f - f2 - 1);
		}
		k2 = k2 / 2;
		printf("%.3lf\n", 1 - (1.0 * k2 / k1));
	}
}
