#include <stdio.h>
#include <string.h>

long f[105][105][105];
int main() {
	int T;
	int N, K, D, S;
	long t[105], w[105];
	int i, j, k, p, pp, d, l;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &N, &K, &D, &S);
		memset(t, 0, sizeof(t));
		memset(w, 0, sizeof(w));
		for (i = 0; i < K; i++) {
			scanf("%d %d", &t[i], &w[i]);
		}
		for (i = 0; i < 105; i++) {
			for (j = 0; j < 105; j++) {
				for (k = 0; k < 105; k++) {
					f[i][j][k] = 1000000000;
				}
			}
		}
		f[0][0][N] = 0;
		p = 0;
		d = 0;
		for (i = 1; i <= S; i++) {
			for (k = N; k >= 0; k--) {
				f[i][0][k] = f[i-1][d][k] + k;
			}
			d = 0;
			while (t[p] == i) {
				d++;
				for (j = 1; j <= w[p]; j++) {
					for (k = N; k >= 0; k--) {
						if (f[i][d-1][k] < f[i][d][k]) {
							f[i][d][k] = f[i][d-1][k];
						}
						if (k+j <= N) {
							if (f[i][d-1][k+j]+D < f[i][d][k]) {
								f[i][d][k] = f[i][d-1][k+j]+D;
							}
						}
					}
				}
				p++;
			}
		}/*
		for (j = 0; j <= S; j++) {
			for (i = 0; i <= N; i++) {
				printf("%ld	", f[j][1][i]);
			}
			printf("\n");
		}
		printf("\n");

		for (j = 0; j <= S; j++) {
			for (i = 0; i <= N; i++) {
				printf("%ld	", f[j][0][i]);
			}
			printf("\n");
		}*/
		if (f[S][d][0] < 1000000000) {
			printf("%ld\n", f[S][d][0]);
		}else{
			printf("impossible\n");
		}
	}
}
