#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
	int n[51];
	int f;
	int d;
	int fa;
	bool b;
} NODE;

int n;

NODE tire[505];
double f[55][505];
double dis[55][55];

double p2(double i) {
	return i * i;
}

void dof() {
	int i, j;
	int list[505];
	int h = -1, t = 0;
	for (i = 0; i <= n; i++) {
		if (tire[0].n[i] >= 0) {
			tire[tire[0].n[i]].f = 0;
			for (j = 0; j <= n; j++) {
				if (tire[tire[0].n[i]].n[j] >= 0) {
					h = (h + 1) % 505;
					list[h] = tire[tire[0].n[i]].n[j];
				}
			}
		}
	}
	while ((h + 1) % 505 != t) {
		int p = list[t];
		t = (t + 1) % 505;
		for (i = 0; i <= n; i++) {
			if (tire[p].n[i] >= 0) {
				h = (h + 1) % 505;
				list[h] = tire[p].n[i];
			}
		}
		int n = tire[p].d;
		int q = tire[tire[p].fa].f;
		while (true) {
			if (tire[q].n[n] >= 0) {
				tire[p].f = tire[q].n[n];
				if (tire[tire[q].n[n]].b) {
					tire[p].b = true;
				}
				break;
			}else{
				if (q == 0) {
					tire[p].f = 0;
					break;
				}
			}
			q = tire[q].f;
		}
	}
}

int getnext(int f, int n) {
	while (true) {
		if (tire[f].n[n] >= 0) {
			return tire[f].n[n];
		}
		if (f == 0) {
			return 0;
		}
		f = tire[f].f;
	}
}

int main() {
	int m, i, j, k, l, p, q, ll;
	double px[55], py[55];
	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0 && m == 0){
			break;
		}
		for (i = 0; i < 505; i++) {
			for (j = 0; j <= 50; j++) {
				tire[i].n[j] = -1;
			}
			tire[i].f = 0;
			tire[i].d = -1;
			tire[i].b = false;
		}
		for (i = 0; i < 55; i++) {
			for (j = 0; j < 505; j++) {
				f[i][j] = -1;
			}
		}
		for (i = 1; i <= n; i++) {
			scanf("%lf %lf", &px[i], &py[i]);
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				dis[i][j] = sqrt(p2(px[i] - px[j]) + p2(py[i] - py[j]));
			}
		}
		tire[0].d = 0;
		p = 0;
		for (i = 0; i < m; i++) {
			scanf("%d", &k);
			q = 0;
			for (j = 0; j < k; j++) {
				scanf("%d", &l);
				if (tire[q].n[l] < 0) {
					tire[q].n[l] = ++p;
					tire[p].d = l;
					tire[p].fa = q;
				}
				q = tire[q].n[l];
			}
			tire[q].b = true;
		}
		ll = p;
		dof();
		if (tire[0].n[1] >= 0 && tire[tire[0].n[1]].b) {
			printf("Can not be reached!\n");
			continue;
		}
		if (tire[0].n[1] >= 0) {
			f[1][tire[0].n[1]] = 0;
		} else {
			f[1][0] = 0;
		}
		for (i = 0; i <= n; i++) {
			for (j = 0; j < i; j++) {
				for (l = 0; l <= ll; l++) {
					if (!tire[l].b && f[j][l] >= 0) {
						p = getnext(l, i);
						if (f[j][l] + dis[i][j] < f[i][p] || f[i][p] < 0) {
							f[i][p] = f[j][l] + dis[i][j];
						}
					}
				}
			}
		}
		double min = -1;
		for (i = 0; i <= ll; i++) {
			if ((f[n][i] > 0) && (!tire[i].b) && ((min < 0) || (f[n][i] < min))) {
				min = f[n][i];
			}
		}
		if (min < 0) {
			printf("Can not be reached!\n");
		}else{
			printf("%.2lf\n", min);
		}
	}
}
