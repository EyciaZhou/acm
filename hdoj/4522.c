#include <stdio.h>
#include <stdbool.h>

char buff[10010];
bool g[2][205][205];
int n;

void deal(int p) {
	long q = 0, a;
	char *c = buff;

	while (c[0] != '+' && c[0] != '\0') {
		q = q * 10 + c[0] - '0';
		c++;
	}
	a = q;
	q = 0;
	c++;

	while (c[0] != '\0') {
		if (c[0] == '+') {
			g[p][a][q] = true;
			c++;
			a = q;
			q = 0;
			continue;
		}
		q = q * 10 + c[0] - '0';
		c++;
	}
	g[p][a][q] = true;
}

long run(int p, int s, int e) {
	bool v[205];
	int list[205];
	int dis[205];
	int h = 0, t = 0, q, i;
	memset(v, false, sizeof(v));
	list[0] = s;
	v[s] = true;
	dis[s] = 0;
	while ((h + 1) % 205 != t) {
		q = list[t++];
		if (q == e) {
			/*for (i = 1; i <= n; i++) {
				printf("%d ", dis[i]);
			}
			printf("\n");
			*/
			return dis[q];
		}
		for (i = 1; i <= n; i++) {
			if (g[p][q][i] > 0 && !v[i]) {
				list[++h] = i;
				v[i] = true;
				dis[i] = dis[q] + 1;
			}
		}
	}
	return -1;
}

int main() {
	int Q, t, p, A, B;
	long min0, min1, D1, D2;
	int i, j, k;
	scanf("%d", &Q);
	while (Q--) {
		memset(g, false, sizeof(g));
		scanf("%d %d", &n, &t);
		while (t--) {
			scanf("%s %d", &buff, &p);
			deal(0);
			if (p) {
				deal(1);
			}
		}/*
		for (i = 0; i < 2; i++) {
			for (j = 1; j <= n; j++) {
				for (k = 1; k <= n; k++) {
					printf("%d	", g[i][j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}*/
		scanf("%d %d", &D1, &D2);
		scanf("%d %d", &A, &B);
		min0 = run(0, A, B);
		min1 = run(1, A, B);
		if (min0 < 0 && min1 < 0) {
			printf("-1\n");
		}else if (min0 < 0) {
			printf("%ld\n", min1*D2);
		}else if (min1 < 0) {
			printf("%ld\n", min0*D1);
		}else if (min0*D1 < min1*D2) {
			printf("%ld\n", min0*D1);
		}else{
			printf("%ld\n", min1*D2);
		}
	}
}
