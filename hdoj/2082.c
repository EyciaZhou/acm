#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int n;
	int i, j, k;
	int a[27];
	long long b[55];
	scanf("%d", &n);
	while (n--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (i = 1; i <= 26; i++) {
			scanf("%d", &a[i]);
		}
		b[0] = 1;
		for (i = 1; i <= 26; i++) {
			for (k = 50 - i; k >= 0; k--) {
				for (j = 1; j <= a[i]; j++) {
					if (k + i * j <= 50) {
						b[k + i * j] += b[k];
					}
				}
			}
		}
		long long tot = 0;
		for (i = 1; i <= 50; i++) {
			tot += b[i];
		}
		printf("%I64d\n", tot);
	}
}