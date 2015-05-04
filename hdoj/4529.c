#include <stdio.h>
#include <stdbool.h>
#include <string.h>

long long dp[2][12][300][300];
bool vd[9][300][300];
int hh[9];
int count[300];
int masks[9];

int cc(int n) 
{ 
    n = (n&0x55555555) + ((n>>1)&0x55555555); 
    n = (n&0x33333333) + ((n>>2)&0x33333333); 
    n = (n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f); 
    n = (n&0x00ff00ff) + ((n>>8)&0x00ff00ff); 
    n = (n&0x0000ffff) + ((n>>16)&0x0000ffff); 
  
    return n; 
}

void bin(int k) {
	int i;
	for (i = 0; i < 16; i++) {
		if (k & (1 << i)) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}

int main() {
	int T;
	int ha, j1, j2, jj1, jj2, t, yx, n, i, j, now, now2;
	scanf("%d", &T);
	for (i = 0; i < 256; i++) {
		count[i] = cc(i);
	}
	for (i  = 0; i < 8; i++) {
		masks[i] = (1 << i) - 1;
	}
	while (T--) {
		scanf("%d", &n);
		memset(vd, false, sizeof(vd));
		memset(dp, false, sizeof(dp));
		for (i = 0; i < 8; i++) {
			getchar();
			for (j = 0; j < 8; j++) {
				if (getchar() == '*') {
					hh[i] = j;
				}
			}
		}

		for (ha = 1; ha < 8; ha++) {
			for (j1 = 0; j1 <= 127; j1++) {
				for (j2 = 0; j2 <= 127; j2++) {
					jj1 = ((j1 & (masks[7-hh[ha-1]] << hh[ha-1])) << 1) + (j1 & masks[hh[ha-1]]);
					jj2 = ((j2 & (masks[7-hh[ha]] << hh[ha])) << 1) + (j2 & masks[hh[ha]]);
					vd[ha][j1][j2] = true;
					if ((((jj1 << 2) | (jj1 >> 2)) & 0xff) & jj2) {
						vd[ha][j1][j2] = false;
					}
				}
			}
		}

		for (j1 = 0; j1 <= 127; j1++) {
			if (count[j1] <= n) {
				dp[0][count[j1]][j1][0] = 1;
			}
		}
		for (j1 = 0; j1 <= 127; j1++) {
			for (j2 = 0; j2 <= 127; j2++) {
				if (count[j1]+count[j2] > n) {
					continue;
				}
				if (!vd[1][j1][j2]) {
					continue;
				}
				dp[1][count[j1]+count[j2]][j1][j2] += 1;
			}
		}

		int sig=1;
		for (ha = 2; ha < 8; ha++) {
			sig = 1-sig;
			memset(dp[sig], 0, sizeof(dp[sig]));
			for (t = 0; t <= n; t++) {
				for (j1 = 0; j1 <= 127; j1++) {
					if (count[j1] > t) {
						continue;
					}
					for (j2 = 0; j2 <= 127; j2++) {
						if (count[j1] + count[j2] > t) {
							continue;
						}

						jj1 = ((j1 & (masks[7-hh[ha-2]] << hh[ha-2])) << 1) + (j1 & masks[hh[ha-2]]);
						jj2 = ((j2 & (masks[7-hh[ha-1]] << hh[ha-1])) << 1) + (j2 & masks[hh[ha-1]]);


						yx = (((jj1 << 1) | (jj1 >> 1) | (jj2 << 2) | (jj2 >> 2)) & 0xff);
						

						for (now = 0; now < 128; now++) {
							now2 = ((now & (masks[7-hh[ha]] << hh[ha])) << 1) + (now & masks[hh[ha]]);
							if (count[j1] + count[j2] + count[now] > t) {
								continue;
							}
							if ((now2 & yx) > 0) {
								continue;
							}
							
							dp[sig][t][j2][now] += dp[1-sig][t-count[now]][j1][j2];
						}
					}
				}
			}
		}
		/*int c;
		for (c = 0; c <= 7; c++) {*/
			long long tot = 0;
			for (i = 0; i <= 127; i++) {
				for (j = 0; j <= 127; j++) {

					tot += dp[1][n][i][j];
				}
			}
			printf("%I64d\n", tot);
	
	}
}