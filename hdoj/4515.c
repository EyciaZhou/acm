#include <stdio.h>
#include <stdbool.h>

int mm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool iis(int i) {
	if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
		return true;
	}
	return false;
}

long int decode(int y, int m, int d) {
	long int tot = 0;
	int i;
	for (i = 0; i < y; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
			tot += 1;
		}
		tot += 365;
	}
	for (i = 1; i < m; i++) {
		tot += mm[i];
	}
	tot += d;
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
		tot++;
	}
	return tot;
}

void encode(int k, int *y, int *m, int *d) {
	int i;
	for (i = 0;; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
			k--;
		}
		k -= 365;
		if (k <= 0) {
			break;
		}
	}
	if (iis(i)) {
		k+=366;
	}else{
		k+=365;
	}
	*y = i;
	for (i = 1; i <= 12; i++) {
		k-=mm[i];
		if (i == 2 && iis(*y)) {
			k-=1;
		}
		if (k <= 0) {
			break;
		}
	}
	k += mm[i];
	if (i == 2 && iis(*y)) {
		k += 1;
	}
	*m = i;
	*d = k;
}

int main() {
	int t;
	long int k;
	int y = 2013, m = 3, d = 24;
	long int base = decode(y, m, d);
	encode(base, &y, &m, &d);
	scanf("%d", &t);
	while (t--) {
		scanf("%ld", &k);
		encode(base+k, &y, &m, &d);
		printf("%0.2d/%0.2d/%0.2d ", y, m, d);
		encode(base-k, &y, &m, &d);
		printf("%0.2d/%0.2d/%0.2d\n", y, m, d);
	}
}
