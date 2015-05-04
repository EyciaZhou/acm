#include <stdio.h>
#include <stdbool.h>

int m[8][8];

int lx[200000];
int ly[200000];
int d[200000];
bool b[200000];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void deal() {
	int p = -1;
	int tot = 0;
	int i, j, k;
	do {
		for (k = 0; k <= p; k++) {
			if (b[k]) {
				if (m[lx[k]+dx[d[k]]][ly[k]+dy[d[k]]] != 0) {
					m[lx[k]+dx[d[k]]][ly[k]+dy[d[k]]]++;
					b[k] = false;
					tot--;
				}else{
					lx[k] += dx[d[k]];
					ly[k] += dy[d[k]];
					if (lx[k] < 1 || ly[k] < 1 || lx[k] > 6 || ly[k] > 6) {
						b[k] = false;
						tot--;
					}
				}
			}
		}

		for (i = 1; i <= 6; i++) {
			for (j = 1; j <= 6; j++) {
				if (m[i][j] > 4) {
					for (k = 0; k < 4; k++) {
						p++;
						lx[p] = i;
						ly[p] = j;
						b[p] = true;
						d[p] = k;
						tot++;
						m[i][j] = 0;
					}
				}
			}
		}
	}while (tot > 0);
}

int main() {
	int i, j, x, y, t;
	memset(m, 0, sizeof(m));
	while (scanf("%d %d %d %d %d %d", &m[1][1], &m[1][2], &m[1][3], &m[1][4], &m[1][5], &m[1][6]) != EOF) {
		for (i = 2; i <= 6; i++) {
			for (j = 1; j <= 6; j++) {
				scanf("%d", &m[i][j]);
			}
		}
		deal();
		scanf("%d", &t);
		while (t--) {
			scanf("%d %d", &x, &y);
			m[x][y]++;
			deal();
		}
		for (i = 1; i <= 6; i++) {
			for (j = 1; j < 6; j++) {
				printf("%d ", m[i][j]);
			}
			printf("%d\n", m[i][6]);
		}
		printf("\n");
		memset(m, 0, sizeof(m));
	}
}
