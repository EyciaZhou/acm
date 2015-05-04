#include <stdio.h>

int main() {
	int l, a, b, i;
	int t[3] = {0};
	char st[205];
	int ans[205], s[205];
	scanf("%d %d %d%s", &l, &a, &b, st);
	for (i = 0; i < l; i++) {
		s[i] = st[i] - '0';
		t[s[i]]++;
	}

	for (i = 0; i < l; i++) {
		if (s[i] == 0) {
			if (t[0] <= a) {
				ans[i] = 0;
				continue;
			}
			if (t[0] > a) {
				t[0]--;
				if (t[1] >= b) {
					ans[i] = 2;
				} else {
					ans[i] = 1;
					t[1]++;
				}
			} else {
				ans[i] = 0;
			}
		}

		if (s[i] == 1) {
			if (t[1] <= b) {
				ans[i] = 1;
				continue;
			}
			if (t[1] > b) {
				t[1]--;
				if (t[0] >= a) {
					ans[i] = 2;
				} else {
					ans[i] = 0;
					t[0]++;
				}
			}else {
				ans[i] = 1;
			}
		}

		if (s[i] == 2) {
			ans[i] = 2;
		}
	}
	for (i = 0; i < l; i++) {
		if (s[i] == 2) {
			if (t[0] < a) {
				a--;
				ans[i] = 0;
			} else if (t[1] < b) {
				b--;
				ans[i] = 1;
			} else {
				ans[i] = 2;
			}
		}
	}
	if (a != t[0] || b != t[1]) {
		printf("-1\n");
	} else {
		int tot = 0;
		for (i = 0; i < l; i++) {
			if (ans[i] != s[i]) {
				tot++;
			}
		}
		printf("%d\n", tot);
		for (i = 0; i < l; i++) {
			putchar(ans[i] + '0');
		}
		printf("\n");
	}
}