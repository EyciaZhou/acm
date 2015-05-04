#include <stdio.h>

int main() {
	int T;
	long a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%ld %ld", &a, &b);
		a = a % 100;
		b = b % 100;
		printf("%ld\n", (a+b) % 100);
	}
}