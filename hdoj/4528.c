#include <stdio.h>
#include <stdbool.h>

bool m[105][105];
bool dm[105][105];
bool em[105][105];

int dx, dy, ex, ey, sx, sy;
int T, n, mm, t;

void genbool() {
	int i, j;
	for (i = dx + 1; i <= n; i++) {
		if (!m[i][dy]) {
			break;
		}
		dm[i][dy] = true;
	}
	for (i = dx - 1; i >= 1; i--) {
		if (!m[i][dy]) {
			break;
		}
		dm[i][dy] = true;
	}
	for (j = dy + 1; j <= mm; j++) {
		if (!m[dx][j]) {
			break;
		}
		dm[dx][j] = true;
	}
	for (j = dy - 1; j >= 1; j--) {
		if (!m[dx][j]) {
			break;
		}
		dm[dx][j] = true;
	}

	for (i = ex + 1; i <= n; i++) {
        if (!m[i][ey]) {
            break;
        }   
        em[i][ey] = true;
    }   
    for (i = ex - 1; i >= 1; i--) {
        if (!m[i][ey]) {
            break;
        }   
        em[i][ey] = true;
    }   
    for (j = ey + 1; j <= mm; j++) {
        if (!m[ex][j]) {
            break;
        }   
        em[ex][j] = true;
    }   
    for (j = ey - 1; j >= 1; j--) {
        if (!m[ex][j]) {
            break;
        }   
        em[ex][j] = true;
    }
}

bool v[3][105][105];
int dr[3][105][105];
int lx[40005], ly[40005], lc[40005], ls[40005];

long walk() {
	memset(v, false, sizeof(v));
	int dx[] = {1, -1, 0, 0};
	long res, p, i;
	int dy[] = {0, 0, 1, -1};
	lx[0] = sx;
	ly[0] = sy;
	lc[0] = 0;
	if (dm[sx][sy]) {
		lc[0] = 1;
	}
	if (em[sx][sy]) {
		lc[0] = 2;
	}
	if (dm[sx][sy] && em[sx][sy]) {
		return 0;
	}
	ls[0] = 0;
	v[lc[0]][sx][sy] = true;
	dr[lc[0]][sx][sy] = 0;
	int hh = 0, ww = 0;
	while ((hh + 1) % 40000 != ww) {
		p = ww;
		if (ls[p] > t) {
			return -1;
		}
		ww = (ww + 1)% 40000;
	for (i = 0; i < 4; i++) {
		if (lx[p]+dx[i] <= n && lx[p]+dx[i] >= 1 && ly[p]+dy[i] <= mm && ly[p]+dy[i] >= 1 && m[lx[p]+dx[i]][ly[p]+dy[i]]) {
			if (em[lx[p]+dx[i]][ly[p]+dy[i]] && dm[lx[p]+dx[i]][ly[p]+dy[i]]) {
				return ls[p]+1;
			}
			if (em[lx[p]+dx[i]][ly[p]+dy[i]]) {
				if (lc[p]==1) {
					return ls[p] + 1;
				}
				if (!v[2][lx[p]+dx[i]][ly[p]+dy[i]]) {
				v[2][lx[p]+dx[i]][ly[p]+dy[i]] = true;
				hh = (hh+1)%40000;
				lx[hh] = lx[p]+dx[i];
				ly[hh] = ly[p]+dy[i];
				lc[hh] = 2;
				ls[hh] = ls[p]+1;
				dr[2][lx[p]+dx[i]][ly[p]+dy[i]] = ls[p]+1;
				}
				continue;
			}
			if (dm[lx[p]+dx[i]][ly[p]+dy[i]]) {
				if (lc[p]==2) {
					return ls[p] + 1;
				}
				if (!v[1][lx[p]+dx[i]][ly[p]+dy[i]]) {
				v[1][lx[p]+dx[i]][ly[p]+dy[i]] = true;
				hh = (hh+1)%40000;
				lx[hh] = lx[p]+dx[i];
				ly[hh] = ly[p]+dy[i];
				lc[hh] = 1;
				ls[hh] = ls[p]+1;
				dr[1][lx[p]+dx[i]][ly[p]+dy[i]] = ls[p]+1;
				}
				continue;
			}
			if (!v[lc[p]][lx[p]+dx[i]][ly[p]+dy[i]]) {
			v[lc[p]][lx[p]+dx[i]][ly[p]+dy[i]] = true;
			hh = (hh+1)%40000;
			lx[hh] = lx[p]+dx[i];
			ly[hh] = ly[p]+dy[i];
			lc[hh] = lc[p];
			ls[hh] = ls[p]+1;
			dr[lc[p]][lx[p]+dx[i]][ly[p]+dy[i]] = ls[p]+1;
			}
		}
	}
	}
	return -1;
}

int main() {
	scanf("%d", &T);
	long res;
	int i, j, k, ttt;
	char c;
	for (ttt = 1; ttt <= T; ttt++) {
		scanf("%d %d %d", &n, &mm, &t);
		memset(m, false, sizeof(m));
		memset(dm, false, sizeof(dm));
		memset(em, false, sizeof(em));
		for (i = 1; i <= n; i++) {
			getchar();
			for (j = 1; j <= mm; j++) {
				c = getchar();
				if (c == '.' || c == 'S') {
					m[i][j] = true;
				}
				if (c == 'D') {
					dx = i;
					dy = j;
				}
				if (c == 'E') {
					ex = i;
					ey = j;
				}
				if (c == 'S') {
					sx = i;
					sy = j;
				}
			}
		}
		genbool();
		res = walk();
		printf("Case %d\n", ttt);
		printf("%d\n", res);
		if (res > t) {
			printf("-1\n");
		}else{
			printf("%ld\n", res);
		}/*
		for (k = 0; k < 3; k++) {
			for (i = 0; i <= n+1; i++) {
				for (j = 0; j <= mm+1; j++) {
					printf("%d	", dr[k][i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
}
