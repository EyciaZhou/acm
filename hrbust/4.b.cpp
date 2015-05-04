#include <iostream>
#include <cstdio>

int main() {
	int n, m;
	int temp;
	while (~scanf("%d%d", &n, &m)) {
		int a1 = 0, a2 = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			if (temp > m) {
				a1 += temp - m;
			} else {
				a2 += m - temp;
			}
		}
		printf("%d %d\n", a1, a2);
	}
}