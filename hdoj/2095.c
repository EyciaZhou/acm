#include <stdio.h>

int main() {
	int n;
	long a;
	long tot;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		tot = 0;
		while (n--) {
			scanf("%ld", &a);
			tot = tot ^ a;
		}
		printf("%ld\n", tot);
	}
}