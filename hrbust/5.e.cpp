#include <cstdio>

int f[505][505];

int main() {
	int T;
	int t;
	int n, m;
	int k, a, b, c, d;
	int te;
	scanf("%d", &T);
	for (int ff = 1; ff <= T; ff++) {
		printf("Case %d:\n", ff);
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			te = 0;
			for (int j = 1; j <= m; j++) {
				scanf("%d", &t);
				te += t * t;
				f[i][j] = f[i-1][j] + te;
			}
		}
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			printf("%d\n", f[c][d] - f[a-1][d] - f[c][b-1] + f[a - 1][b - 1]);
		}
	}
}