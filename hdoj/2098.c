#include <stdio.h>
#include <string.h>

short prime[10005];

int main() {
	int n;
	int i, j;

	for (i = 2; i < 10005; i++) {
		prime[i] = 1;
	}
	
	prime[2] = 1;
	for (i = 2; i < 10005; i++) {
		if (prime[i]) {
			for (j = 2 * i; j < 10005; j += i) {
				prime[j] = 0;
			}
		}
	}

	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		int tot = 0;
		for (i = 2; i < n / 2; i++) {
			if (prime[i] && prime[n - i]) {
				tot++;
			}
		}
		printf("%d\n", tot);
	}
}