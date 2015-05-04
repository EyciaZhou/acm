#include <stdio.h>

int main() {
	long n, m, i;
	long t1, t2;
	while (scanf("%ld %ld", &n, &m) != EOF) {
		t1 = 0;
		t2 = 0;
		if (n > m) {
			n = n ^ m;
			m = n ^ m;
			n = n ^ m;
		}
		for (i = n; i <= m; i++) {
			if (i % 2 == 0) {
				t1 += i * i;
			}else{
				t2 += i * i * i;
			}
		}
		printf("%ld %ld\n", t1, t2);
	}
}