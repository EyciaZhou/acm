#include <stdio.h>

short map[2005][2005];

int main() {
	int m, n;
	int x, y, i, j;

	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			return ;
		}
		scanf("%d %d", &x, &y);
		memset(map, 0, sizeof(map));
		for (i = 0; i < n; i++) {
			getchar();
			for (j = 0; j < m; j++) {
				if (getchar() == '*') {
					map[i][j] = 1;
				}
			}
		}

		
	}
}
