#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
	bool f;
	long l, r;
	long k;
	char buf[15], buf2[15];
	while (true) {
		l = -2147483647;
		r = 2147483647;
		f = true;
		while (true) {
			if (scanf("%ld", &k) == EOF) {
				return 0;
			}

			scanf("%s %s", buf, buf2);
			if (strcmp(buf, "too") == 0) {
				if (strcmp(buf2, "high\0") == 0) {
					if (r >= k) {
						r = k;
					}
				}
				if (strcmp(buf2, "low\0") == 0) {
					if (l <= k) {
						l = k;
					}
				}
			}
			if (r <= l) {
				f = false;
			}
			if (strcmp(buf, "right\0") == 0) {
				if (k >= r || l >= k) {
					f = false;
				}
				break;
			}
		}
		if (f) {
			printf("GF may be honest.\n");
		}else{
			printf("GF is dishonest.\n");
		}
	}
}