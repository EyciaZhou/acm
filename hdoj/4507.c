#include <stdio.h>
#include <stdbool.h>
#define MOD 1000000007

long long int ff, tt, gg;
long long int f[19][10][7][7], t[19][10][7][7], g[19][10][7][7];
long long int fk, fl;
long long int ns, ttt;
long long int ten[19];
long long int i, j, k, l, jj;

long long fix(long long kk) {
	long long int f2[19][10][7][7], t2[19][10][7][7], g2[19][10][7][7];
	memset(f2, 0, sizeof(f2));
	memset(t2, 0, sizeof(t2));
	memset(g2, 0, sizeof(g2));
	int bit[19];
	int ll = 0;
	while (kk > 0) {
		bit[++ll] = kk % 10;
		kk = kk / 10;
	}
	t2[0][0][0][0] = 1;
	for (i = 1; i <= ll; i++) {
		for (j = 0; j <= 9; j++) {
		if (j == 7) continue;
		for (k = 0; k < 7; k++) {
			for (l = 0; l < 7; l++) {
				ff = 0;
				tt = 0;
				gg = 0;
				for (jj = 0; jj < bit[i]; jj++) {
					if (jj == 7) continue;
					fk = (k - j + 14) % 7;
					ns = j * ten[i - 1] % MOD;
					fl = (l - ns % 7 + 7) % 7;
					ttt = t[i - 1][jj][fk][fl];
					ff = (ff + f[i - 1][jj][fk][fl]) % MOD;
					tt = (tt + ttt) % MOD;
					gg = (gg + ttt * ns % MOD + g[i - 1][jj][fk][fl]) % MOD;
				}
				if (bit[i] != 7) {
					jj = 7;
					fk = (k - j + 14) % 7;
					ns = j * ten[i - 1] % MOD;
					fl = (l - ns % 7 + 7) % 7;
					tt = t2[i - 1][jj][fk][fl];
					ff = (ff + f2[i - 1][jj][fk][fl]) % MOD;
					tt = (tt + ttt) % MOD;
					gg = (gg + ttt * ns % MOD + g2[i - 1][jj][fk][fl]) % MOD;

				}
				f2[i][j][k][l] = ff;
				g2[i][j][k][l] = gg;
				t2[i][j][k][l] = tt;
			}
		}
	}
	}
	long int tot = 0;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (i != 0 && j != 0) {
				tot = (tot + f2[ll][bit[ll]][i][j]) % MOD;
			}
		}
	}
	printf("%d\n", ll);
	printf("%lld\n", tot);
	return tot;
}

int main() {
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(f));
	memset(t, 0, sizeof(t));
	ten[0] = 1;
	for (i = 1; i < 19; i++) {
		ten[i] = ten[i - 1] * 10 % MOD;
	}
	t[0][0][0][0] = 1;
	for (i = 1; i <= 18; i++) {
		for (j = 0; j <= 9; j++) {
			if (j == 7) continue;
			for (k = 0; k < 7; k++) {
				for (l = 0; l < 7; l++) {
					ff = 0; 
					tt = 0;
					gg = 0;
					for (jj = 0; jj <= 9; jj++) {
						if (jj == 7) continue;
						fk = (k - j + 14) % 7;
						ns = j * ten[i - 1] % MOD;
						fl = (l - ns % 7 + 7) % 7;
						ttt = t[i - 1][jj][fk][fl];
						ff = (ff + f[i - 1][jj][fk][fl]) % MOD;
						ff = (ff + ttt * ns % MOD * ns % MOD) % MOD;
						ff = (ff + 2 * ns % MOD * g[i - 1][jj][fk][fl] % MOD) % MOD;
						tt = (tt + ttt) % MOD;
						gg = (gg + ttt * ns % MOD + g[i - 1][jj][fk][fl]) % MOD;
					}
					f[i][j][k][l] = ff;
					g[i][j][k][l] = gg;
					t[i][j][k][l] = tt;
				}
			}
		}
	}
	int d;
	long long s, e;
	scanf("%d", &d);
	while (d--) {
		long long ans = 0;
		scanf("%lld %lld", &s, &e);
		ans += fix(s);
		ans -= fix(e);
		ans += MOD;
		ans = ans % MOD;
		printf("%lld\n", ans);
	}
}
