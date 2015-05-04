#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ww, hh, k;
long int l, minl, maxd;
int si, sj, ei, ej, totjw;
long int jw[10], jwi[60][60];
bool w[60][60];
int v[60][60];
long int vt[60][60];
long int vv[60][60];
bool s;
int jui[4] = {1, 0, 0, -1}, juj[4] = {0, 1, -1, 0};

void bfs() {
	int i, j, ii, jj, iii, jjj;
	for (i = 0; i < 60; i++) {
		for (j = 0; j < 60; j++) {
			v[i][j] = -1;
		}
	}
	int li[30000], lj[30000];
	long int h, t;
	v[si][sj] = 0;
	li[0] = si;
	lj[0] = sj;
	h = t = 0;
	while ((h + 1) % 30000 != t) {
		ii = li[t];
		jj = lj[t];
		if (v[ii][jj] > l) {
			break;
		}
		t = (t + 1) % 30000;
		for (i = 0; i < 4; i++) {
			iii = ii + jui[i];
			jjj = jj + juj[i];
			if (totjw > 0) {
				if (v[iii][jjj] < 0 && !w[iii][jjj]) {
					v[iii][jjj] = v[ii][jj] + 1;
					h = (h + 1) % 30000;
					li[h] = iii;
					lj[h] = jjj;
				}
			}
		}
	}
	minl = v[ii][jj];
	if (minl < 0) {
		minl = l + 1;
	}
}

void dfs(int ii, int jj, int time, long int coin) {
	/*printf("%d %d %d %ld %d\n", ii, jj, time, coin, totjw);*/
	if (s) {
		return;
	}
	if (time > (l - (minl - v[ii][jj]))) {
		return;
	}
	if (ii == ei && jj == ej) { 
		if (coin > maxd) {
			maxd = coin;
		}
		if (coin == totjw) {
			s = true;
		}
		return;
	}
	int cc = jwi[ii][jj];
	if (jwi[ii][jj] >= 0) {
		coin += jw[jwi[ii][jj]];
	}
	jwi[ii][jj] = -1;
	if (coin > vv[ii][jj] || (coin == vv[ii][jj] && time < vt[ii][jj])) {
		vv[ii][jj] = coin;
		vt[ii][jj] = time;
	}
	int i, iii, jjj;
	for (i = 0; i < 4; i++) {
		iii = ii + jui[i];
		jjj = jj + juj[i];
		if (!w[iii][jjj]) {
				if (time + 1 < vt[iii][jjj] || coin > vv[iii][jjj]) {
					
					dfs(iii, jjj, time + 1, coin);
				}
		}
	}
	jwi[ii][jj] = cc;
}

int main() {
	int d, ff;
	scanf("%d\n", &d);
	for (ff = 1; ff <= d; ff++) {
		int i, j;
		char c;
		scanf("%d %d %ld %d\n", &ww, &hh, &l, &k);
		for (i = 0; i < k; i++) {
			scanf("%ld", &jw[i]);
		}
		for (i = 1; i <= hh; i++) {
			w[i][0] = true;
			w[i][ww + 1] = true;
		}
		for (i = 1; i <= ww; i++) {
			w[0][i] = true;
			w[hh + 1][i] = true;
		}	
		getchar();
		totjw = 0;
		for (i = 0; i < 60; i++) {
			for (j = 0; j < 60; j++) {
				vv[i][j] = 0;
				vt[i][j] = 1000001;
			}
		}
		for (i = 1; i <= hh; i++) {
			for (j = 1; j <= ww; j++) {
				scanf("%c", &c);
				w[i][j] = false;
				if (c == '*') {
					w[i][j] = true;
				}
				if (c == '@') {
					si = i;
					sj = j;
				}
				if (c == '<') {
					ei = i;
					ej = j;
				}
				jwi[i][j] = -1;
				if (c <= 'Z' && c >= 'A') {
					jwi[i][j] = c - 'A';
					totjw += jw[jwi[i][j]];
				}
			}
			getchar();
		}
		minl = l + 1;
		maxd = 0;
		s = false;
		printf("Case %d\n", ff);
		bfs();
		if (l < minl) {
			printf("Impossible\n");
		}else{
			long int tk = 0;
			long int md = 0;

			for (i = 1; i <= hh; i++) {
				for (j = 1; j <= ww; j++) {
					/*printf("%4d", v[i][j]);*/
					if (jwi[i][j] >= 0) {
						if (v[i][j] >= 0) {
							tk += v[i][j] * 2;
							md += jw[jwi[i][j]];
						}
					}
				}
				/*printf("\n");*/
			}
			if (tk <= l) {
				/*printf("%ld %ld\n", tk, md);*/
				printf("The best score is %ld\n", md);
			} else {
				dfs(si, sj, 0, 0);
				printf("The best score is %ld.\n", maxd);
			}
		}
		printf("\n");/*
		for (i = 1; i <= hh; i++) {
			for (j = 1; j <= ww; j++) {
				if (vt[i][j] == 1000001) {
					printf("%d:%ld	", -1, vv[i][j]);
				}else {
					printf("%ld:%ld	", vt[i][j], vv[i][j]);
				}
			}
			printf("\n");
		}*/
	}
}