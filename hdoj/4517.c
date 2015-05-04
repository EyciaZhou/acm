#include <stdio.h>
#include <stdbool.h>

//short map[2005][2005];
int  t[2005][2005]; 
int  t2[2005][2005];
int  l[2][2005];

int main() {
	int m, n;
	int x, y, i, j, ii;
	long r, tot, res;
	while (true) {
		scanf("%d %d", &n, &m);
		if (m == 0 && n == 0) {
			return ;
		}
		scanf("%d %d", &x, &y);
		memset(t, 0, sizeof(t));
		for (i = 0; i < n; i++) {
			getchar();
			for (j = 0; j < m; j++) {
				if (getchar() == '*') {
					t2[i][j] = 1;
				}
			}
		}

		for (i = 0; i < n; i++) {
			tot = 0;
			for (j = 0; j < m; j++) {
				tot += t2[i][j];
				t[i][j] = tot;
			}
		}
		r = x * y;
		res = 0;

		for (j = 0; j < m; j++) {
			tot = 0;
			for (i = 0; i < x; i++) {
				tot += t2[i][j];
			}
			l[0][j] = tot;
		}

		for (j = 0; j < m; j++) {
			tot = 0;
			for (i = 0; i < y; i++) {
				tot += t2[i][j];
			}
			l[1][j] = tot;
		}
		for (ii = 0; ii < 2; ii++) {
		
			if (ii == 1 && x == y) {
				continue ;
			}

			if (ii == 1) {
				tot = x;
				x = y;
				y = tot;
			}

			memset(t2, 0, sizeof(t2));

			tot = 0;
			for (j = 0; j < y; j++) {
				tot += l[ii][j];
			}
			if (tot == r) {
				res++;
			}
			t2[x-1][y-1] = tot;
	
			for (j = y; j < m; j++) {
				tot = tot - l[ii][j - y] + l[ii][j];
				t2[x-1][j] = tot;
				if (tot == r) {
					res++;
				}
			}
	
			for (i = x; i < n; i++) {
				for (j  = y - 1; j < m; j++) {
					t2[i][j] = t2[i -1][j] - t[i-x][j] + t[i-x][j-y] + t[i][j] - t[i][j-y];
					if (t2[i][j] == r) {
						res++;
					}
				}
			}
		}

		printf("%ld\n", res);
	}
}
