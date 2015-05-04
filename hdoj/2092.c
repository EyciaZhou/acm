#include <stdio.h>
#include <math.h>

int main() {
	int n, m;
	int a;
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			break;
		}
		for (a = -fabs(m); a <= fabs(m); a++) {
			if (a * (n - a) == m) {
				printf("Yes\n");
				break;
			}
		}
		if (a * (n-a) != m) {
			printf("No\n");
		}
	}
}