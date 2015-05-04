#include <stdio.h>
#include <stdbool.h>

typedef struct NODE {
	int n[11];
	int f, fath, d;
	bool b;
} node;

node actrie[350];
int triep;
long long int f[355][15][10];
long long int g[355][15][10];
long long int ff[355][15][10];
long long int gg[355][15][10];
bool t[355][15][10];
long long int fib[60];

int getnext(int f, int n) {
	int p = f;
	while (true) {
		if (actrie[p].n[n] > 0) {
			return actrie[p].n[n];
		}
		if (p == 0) {
			return 0;
		}
		p = actrie[p].f;
	}
}

void pref() {
	actrie[0].b = false;
	int l, n, a, n2, p;
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	memset(t, false, sizeof(t));
	g[0][0][0] = 1;
	for (l = 1; l < 13; l++) {
		for (n = 0; n <= 9; n++) {
			for (a = 0; a <= triep; a++) {
				p = getnext(a, n);
				for (n2 = 0; n2 <= 9; n2++) {
					g[p][l][n] += g[a][l-1][n2];
				}
				if (actrie[p].b) {
					t[p][l][n] = true;
				}else{
					for (n2 = 0; n2 <= 9; n2++) {
						f[p][l][n] += f[a][l-1][n2];
					}
				}
			}
		}
		for (n = 0; n <= 9; n++) {
			for (a = 0; a <= triep; a++) {
				if (t[a][l][n]) {
					f[a][l][n] += g[a][l][n];
				}
			}
		}
	}
}
	
long long getn(long long k) {
	int ll = 0;
	int bit[20] = {0} ;
	int l, n, a, p, n2;
	memset(gg, 0, sizeof(gg));
	memset(ff, 0, sizeof(ff));
	gg[0][0][0] = 1;
	while (k > 0) {
		bit[++ll] = k % 10;
		k /= 10;
	}
	for (l = 1; l <= ll; l++) {
		for (n = 0; n < bit[l]; n++) {
			for (a = 0; a <= triep; a++) {
				gg[a][l][n] = g[a][l][n];
				ff[a][l][n] = f[a][l][n];
			}
		}
		for (a = 0; a <= triep; a++) {
			p = getnext(a, bit[l]);
			for (n2 = 0; n2 <= bit[l-1]; n2++) {
				gg[p][l][n] += gg[a][l-1][n2];
			}
			if (actrie[p].b) {
				ff[p][l][n] = gg[p][l][n];
			} else {
				for (n2 = 0; n2 <= bit[l-1]; n2++) {
					ff[p][l][n] += ff[a][l-1][n2];
				}
			}
		}
	}
	long long tot = 0;
	for (a = 0; a <= triep; a++) {
		for (n = 0; n <= bit[ll]; n++) {
			tot += ff[a][ll][n];
		}
	}
	return tot;
}

void dof() {
	int i, j, q, r;
	int p = 0;
	int list[305];
	int h = -1, t = 0;
	for (i = 0; i < 11; i++) {
		if (actrie[0].n[i] >= 0) {
			actrie[0].f = 0;
			for (j = 0; j < 11; j++) {
				if (actrie[actrie[0].n[i]].n[j] > 0) {
					h = (h + 1) % 305;
					list[h] = actrie[actrie[0].n[i]].n[j];
				}
			}
		}
	}
	while ((h + 1) % 305 != t) {
		p = list[t];
		t = (t + 1) % 305;

		for (i = 0; i < 11; i++) {
			if (actrie[p].n[i] >= 0) {
				h = (h + 1) % 305;
				list[h] = actrie[p].n[i];
			}
		}
		q = actrie[actrie[p].fath].f;
		while (true) {
			r = actrie[q].n[actrie[p].d];
			if (r >= 0) {
				actrie[p].f = r;
				if (actrie[r].b) {
					actrie[p].b = true;
				}
				break;
			}
			if (q == 0) {
				actrie[p].f = 0;
				break;
			}
			q = actrie[q].f;
		}
	}
}

long long erfen(long long target) {
	long long int l = 0, r = 130000000000, m = (l + r)/2;
	while (r - l > 1) {
		if (getn(m) >= target) {
			r = m;
		}else{
			l = m;
		}
		m = (l + r) / 2;
	}
	return r;
}

int main() {
	long int i, j, p;
	long long int k;
	fib[0] = 1;
	fib[1] = 1;
	for (i = 2; i <= 58; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	memset(actrie, 0, sizeof(actrie));
	for (i = 0; i < 300; i++) {
		for (j = 0; j < 11; j++) {
			actrie[i].n[j] = -1;
		}
	}
	actrie[0].f = -1;
	actrie[0].fath = -1;
	actrie[0].d = -2;
	actrie[0].b = false;
	triep = 0;
	for (i = 6; i <= 55; i++) {
		k = fib[i];
		p = 0;
		while (k > 0) {
			if (actrie[p].n[k%10] < 0) {
				triep++;
				actrie[triep].fath = p;
				actrie[triep].d = k % 10;
				actrie[p].n[k%10] = triep;
			}
			p = actrie[p].n[k%10];
			k = k / 10;
		}
		actrie[p].b = true;
	}
	dof();
	pref();
	long long int tot = 0;
	long long fibfib[60] = {0};
	fibfib[0] = -1000000;
	for (i = 1; i < 53; i++) {
		fibfib[i] = erfen(fib[i]);
	}
	for (i = 0; i < 53; i++) {
		printf("%lld\n", fibfib[i]);
	}
	long long int rd;
	while (true) {
		scanf("%lld", &rd);
		if (rd < 0) {
			break;
		}
		for (i = 1; i < 53; i++) {
			if (fibfib[i] > rd) {
				break;
			}
		}
		if (i == 53) {
			printf("%lld\n", rd - fibfib[i-1]);
			continue;
		}
		if (fibfib[i] - rd > rd - fibfib[i-1]) {
			printf("%lld\n", rd - fibfib[i-1]);
		}else{
			printf("%lld\n", fibfib[i] - rd);
		}
	}
}
