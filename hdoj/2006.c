#include <stdio.h>

int main() {
	int d, t;
	long long tot;
	while (scanf("%d", &d) != EOF) {
		tot = 1;
		while (d--) {
			scanf("%d", &t);
			if (t % 2 == 1) {
				tot *= t;
			}
		}
		printf("%I64d\n", tot);
	}
}