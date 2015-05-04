#include <stdio.h>
#include <stdbool.h>
#include <string.h>

long int kt[9] = {40320, 5040, 720, 120, 24, 6, 2, 1, 1};

int 	block[10][4];
bool	pin[10];
bool 	pinh[3];
bool 	pinl[3];
bool 	v[400000];

long int kangtuo(int *a) {
	int i, j;
	int b[9] = {0};
	for (i = 0; i < 9; i++) {
		for (j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				b[i]++;
			}
		}
	}
	for (i = 0; i < 9; i++) {
		b[i] = a[i] - b[i];
	}
	long int k = 0;
	for (i = 0; i < 9; i++) {
		k += kt[i] * b[i];
	}
	return k;
}

int l[400000][9];
long step[400000];

bool tb[10][4];

int l2[40][2];

void bfs2(int iii, int jjj, int k) {
	int h = 0, t = 0, vi, vj;
	int value = block[l[k][iii]][jjj];
	l2[0][0] = iii;
	l2[0][1] = jjj;
	tb[iii][jjj] = true;
	while ((h + 1) % 40 != t) {
		vi = l2[t][0];
		vj = l2[t][1];
		t = (t + 1) % 40;
		if (vj == 0) {
			if (vi / 3 != 0 && (!tb[vi - 3][1]) && (block[l[k][vi - 3]][1] == value)) {
				tb[vi - 3][1] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi - 3;
				l2[h][1] = 1;
			}
			if ((!tb[vi][2]) && (block[l[k][vi]][2] == value)) {
				tb[vi][2] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi;
				l2[h][1] = 2;
			}
			if ((!tb[vi][3]) && (block[l[k][vi]][3] == value)) {
				tb[vi][3] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi;
				l2[h][1] = 3;
			}
		}else if (vj == 1) {
			if (vi / 3 != 2 && (!tb[vi + 3][0]) && (block[l[k][vi + 3]][0] == value)) {
				tb[vi + 3][0] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi + 3;
				l2[h][1] = 0;
			}
			if ((!tb[vi][2]) && (block[l[k][vi]][2] == value)) {
				tb[vi][2] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi;
				l2[h][1] = 2;
			}
			if ((!tb[vi][3]) && (block[l[k][vi]][3] == value)) {
				tb[vi][3] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi;
				l2[h][1] = 3;
			}
		} else if (vj == 2) {
			if (vi % 3 != 0 && (!tb[vi - 1][3]) && (block[l[k][vi - 1]][3] == value)) {
				tb[vi - 1][3] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi - 1;
				l2[h][1] = 3;
			}
			if ((!tb[vi][1]) && (block[l[k][vi]][1] == value)) {
				tb[vi][1] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi;
				l2[h][1] = 1;
			}
			if ((!tb[vi][0]) && (block[l[k][vi]][0] == value)) {
				tb[vi][0] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi;
				l2[h][1] = 0;
			}
		} else if (vj == 3) {
			if (vi % 3 != 2 && (!tb[vi + 1][2]) && (block[l[k][vi + 1]][2] == value)) {
				tb[vi + 1][2] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi + 1;
				l2[h][1] = 2;
			}
			if ((!tb[vi][1]) && (block[l[k][vi]][1] == value)) {
				tb[vi][1] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi;
				l2[h][1] = 1;
			}
			if ((!tb[vi][0]) && (block[l[k][vi]][0] == value)) {
				tb[vi][0] = true;
				h = (h + 1) % 40;
				l2[h][0] = vi;
				l2[h][1] = 0;
			}
		}
	}
}

bool lt(int k) {
	int i, j, ii, jj;
	memset(tb, 0, sizeof(tb));
	for (i = 0; i < 9; i++) {
		for (j = 3; j >= 0; j--) {
			if (!tb[i][j]) {
				bfs2(i, j, k);
				int value = block[l[k][i]][j] ; 
				for (ii = 0; ii < 9; ii++) {
					for (jj = 0; jj < 4; jj++) {
						if ((!tb[ii][jj]) && (block[l[k][ii]][jj] == value)) {
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

long bfs() {
	int i, j;
	long kan;
	memset(v, false, sizeof(v));
	for (i = 0; i < 9; i++) {
		l[0][i] = i;
	}
	step[0] = 0;
	long h = 0, w = 0;
	int *p;
	int temp[9];
	while ((h + 1) % 400000 != w) {
		p = l[w];
		if (lt(w)) {
			return step[w];
		}
		for (i = 0; i < 3; i++) {
			if (!pinh[i]) {
				for (j = 0; j < 9; j++) {
					temp[j] = p[j];
				}
				for (j = 0; j < 3; j++) {
					temp[3 * i + j] = p[3 * i + (j + 1)%3];
				}
				kan = kangtuo(temp);
				if (!v[kan]) {
					v[kan] = true;
					h = (h + 1) % 400000;
					for (j = 0; j < 9; j++) {
						l[h][j] = temp[j];
					}
					step[h] = step[w] + 1;
				}

				for (j = 0; j < 9; j++) {
					temp[j] = p[j];
				}
				for (j = 0; j < 3; j++) {
					temp[3 * i + j] = p[3 * i + (j + 2)%3];
				}
				kan = kangtuo(temp);
				if (!v[kan]) {
					v[kan] = true;
					h = (h + 1) % 400000;
					for (j = 0; j < 9; j++) {
						l[h][j] = temp[j];
					}
					step[h] = step[w] + 1;
				}
			}
		}

		for (i = 0; i < 3; i++) {
			if (!pinl[i]) {
				for (j = 0; j < 9; j++) {
					temp[j] = p[j];
				}
				for (j = 0; j < 3; j++) {
					temp[3 * j + i] = p[3 * ((j + 1)%3) + i];
				}
				kan = kangtuo(temp);
				if (!v[kan]) {
					v[kan] = true;
					h = (h + 1) % 400000;
					for (j = 0; j < 9; j++) {
						l[h][j] = temp[j];
					}
					step[h] = step[w] + 1;
				}

				for (j = 0; j < 9; j++) {
					temp[j] = p[j];
				}
				for (j = 0; j < 3; j++) {
					temp[3 * j + i] = p[3 * ((j + 2)%3) + i];
				}
				kan = kangtuo(temp);
				if (!v[kan]) {
					v[kan] = true;
					h = (h + 1) % 400000;
					for (j = 0; j < 9; j++) {
						l[h][j] = temp[j];
					}
					step[h] = step[w] + 1;
				}
			}
		}
		w = (w + 1) % 400000;
	}
	return -1;
}

void escanf(int k) {
	int i;
	char c;
	for (i = 0; i < 4; i++) {
		c = getchar();
		switch (c) {
			case 'R' :
				block[k][i] = 0;
				break;
			case 'G' :
				block[k][i] = 1;
				break;
			case 'B' :
				block[k][i] = 2;
				break;
			case 'O' :
				block[k][i] = 3;
		}
	}
	c = getchar();
	if (c == '0') {
		pin[k] = false;
	}else{
		pin[k] = true;
		pinh[k/3] = true;
		pinl[k%3] = true;
	}
}

int main() {
	int T, ff, i;
	scanf("%d", &T);
	for (ff = 1; ff <= T; ff++) {
		memset(pinh, false, sizeof(pinh));
		memset(pinl, false, sizeof(pinl));
		for (i = 0; i < 9; i++) {
			getchar();
			escanf(i);
		}
		printf("Case #%d: %ld\n", ff, bfs());
	}
}