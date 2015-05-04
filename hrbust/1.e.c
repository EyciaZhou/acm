#include <stdio.h>
#include <stdbool.h>

int main() {
	int n, i;
	long m, mm;
	long ss;
	while (true) {
		if (scanf("%d %ld", &n, &m) == EOF) {
			return 0;
		}
		mm = m;
		for (i = 0; i < n; i++) {
			scanf("%ld", &ss);
			while (m % ss == 0) {
				m = m / ss;
			}
		}
		if (mm == 1) {
			printf("YES\n");
		}else {
			while (m % 2 == 0) {
				m = m / 2;
			}
			while (m % 3 == 0) {
				m = m / 3;
			}
			while (m % 5 == 0) {
				m = m / 5;
			}
			if (m == 1) {
				printf("NO\n");
			}else{
				printf("YES\n");
			}
		}
	}
}