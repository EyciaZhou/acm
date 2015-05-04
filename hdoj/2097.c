#include <stdio.h>

int main() {
	int d, e, i;
	int ta, tb, tc;
	for (; ; ) {
		scanf("%d", &d);
		if (d == 0) {
			break;
		}
		e = d;
		ta = 0;
		tb = 0;
		tc = 0;
		for (i = 0; i < 4; i++) {
			ta += d % 10;
			d = d / 10;
		}
		d = e;
		for (i = 0; i < 4; i++) {
			tb += d % 16;
			d = d / 16;
		}
		d = e;
		for (i = 0; i < 4; i++) {
			tc += d % 12;
			d = d / 12;
		}
		if (ta == tb && ta == tc) {
			printf("%d is a Sky Number.\n", e);
		} else {
			printf("%d is not a Sky Number.\n", e);
		}
	}
}