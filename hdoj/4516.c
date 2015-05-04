#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int a[10], b[10], c[10];
int s[100];
int p, t;

bool fix(int i) {
	int j;
	for (j = 0; j <= 6; j++) {
		b[j] = a[j];
		c[j] = 0;
	}
	for (j = t - 1; j >= 0; j--) {
		c[j] = b[j + 1];
		b[j] = b[j] - i * b[j + 1];
		b[j + 1] = 0;
	}
	if (b[0] == 0) {
		for (j = 0; j <= 6; j++) {
			a[j] = c[j];
		}
		t--;
		s[p++] = i;
		return true;
	}
	return false;
}

int main() {
	char r[10005];
	char *raw = r;
	bool z;
	int i, j, d, m, y, k;
	scanf("%d", &d);
	for (k = 1; k <= d; k++) {
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		p = 0;
		y = 0;
		scanf("%s", &r);
		raw = r;
		
		if (strlen(r) == 1 && (r[0] == '1' || r[0] == '0')) {
			printf("Case #%d: -1\n", k);
			continue;
		}

		while (raw[0] != '\0') {

			z = true;
			if (raw[0] == '-'){
				z = false;
			}
			if (raw[0] == '-' || raw[0] == '+') {
				raw++;
			}
			t = 1;
			if (raw[0] <= '9' && raw[0] >= '0') {
				t = 0;
			}
			while (raw[0] <= '9' && raw[0] >= '0') {
				t = t * 10 + raw[0] - '0';
				raw++;
			}

			if (raw[0] == 'x') {
				raw++;
				m = 1;
			} else {
				m = 0;
			}
		
			if (raw[0] == '^') {
				m = 0;
				raw++;
				while (raw[0] <= '9' && raw[0] >= '0') {
					m = m * 10 + raw[0] - '0';
					raw++;
				}
			}
		
			if (!z) {
				t = -t;
			}
			a[m] += t;
		
		}
		for (i = 6; i >= 0; i--) {
			if (a[i] != 0) {
				break;
			}
		}

		if (i == -1) {
			printf("Case #%d: -1\n", k);
			continue;
		}

		if (i == 0 && a[i] == 1) {
			printf("Case #%d: -1\n", k);
			continue;
		}

		t = i;

		while (fix(0)) {
			y++;
			p--;
		}

		for (i = abs(a[0]); i >= 1; i--) {
			if (abs(a[0]) % i == 0) {
				if (fix(-i)) {
					i++;
				}
			}
		}
		while (fix(0)) {
			y++;
			p--;
		}

		for (i = 1; i <= a[0]; i++) {
			if (a[0] % i == 0) {
				if (fix(i)) {
					i--;
				}
			}
		}
		
		bool f = false;
		for (i = 6; i >= 1; i--) {
			if (a[i] != 0) {
				f =true;
			}
		}
		if (f || a[0] != 1) {
			printf("Case #%d: -1", k);
		} else {
			printf("Case #%d: ", k);
			for (i = 0; i < p; i++) {
				if (s[i] > 0) {
					break;
				}
				printf("(x%d)", s[i]);
			}
			for (j = 0; j < y; j++) {
				printf("x");
			}
			for (j = i; j < p; j++) {
				printf("(x+%d)", s[i]);
			}

		}
		printf("\n");

	}
}
