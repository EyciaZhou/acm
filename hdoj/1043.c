#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
	struct node *prev;
	char c;
} NODE;

bool hash[1][362885];
NODE path[1][362885];
int list[1][30000][10];
int h[1], t[1];

void eprint(long int k) {
	char s[10000];
	int po = 0, i;
	NODE p = path[0][k];
	while (p.prev != NULL) {
		printf("%c", p.c);
		p = *p.prev;
	}
	printf("\n");
}

long int kt[9] = {40320, 5040, 720, 120, 24, 6, 2, 1, 1};

int * dekangtuo(long k) {
	int i, j;
	int b[9] = {0};
	for (i = 0; i < 9; i++) {
		b[i] = k / kt[i];
		k = k % kt[i];
		for (j = 0; j < i; j++) {
			if (b[j] < b[i]) {
				b[i]++;
			}
		}
		b[i]++;
	}
	return b;
}

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
		b[i] = a[i] - b[i] - 1;
	}
	long int k = 0;
	for (i = 0; i < 9; i++) {
		k += kt[i] * b[i];
	}
	return k;
}

int main() {
	int a[10];
	char c;
	int i, px;
	long int j;
	list[0][0][9] = 8;
	hash[0][0] = true;
	path[0][0].prev = NULL;
	h[0] = t[0] = 0;
	for (i = 0; i < 9; i++) {
		list[0][0][i] = i + 1;
	}
	while (scanf("") != EOF) {
		for (i = 0; i < 9; i++) {
			c = getchar();
			if (getchar() < 0) {
				return;
			}
			if (c == 'x') {
				a[i] = 9;
				px = i;
			}else{
				a[i] = c - '0';
			}
		}
		int q = 0;

		while (h[0] != (t[0] + 1) % 30000) {
			int *a = list[q][h[q]];
			int p = a[9];
			long int kp = kangtuo(a);
			int temp;
			if (p > 2) {
				int t3 = (t[q] + 1) % 30000;
				int i;
				int *b = list[q][t3];
				for (i = 0; i < 9; i++) {
					b[i] = a[i];
				}
				temp = b[p];
				b[p] = b[p - 3];
				b[p - 3] = temp;
				b[9] = p - 3;
				long int k = kangtuo(b);
				if (!hash[q][k]) {
					t[q] = t3;
					if (q == 1) {
						path[q][k].c = 'u';
					} else {
						path[q][k].c = 'd';
					}
					path[q][k].prev = &(path[q][kp]);
					hash[q][k] = true;
				}
			}
			if (p < 6) {
				int t3 = (t[q] + 1) % 30000;
				int i;
				int *b = list[q][t3];
				for (i = 0; i < 9; i++) {
					b[i] = a[i];
				}
				temp = b[p];
				b[p] = b[p + 3];
				b[p + 3] = temp;
				b[9] = p + 3;
				long int k = kangtuo(b);
				if (!hash[q][k]) {
					t[q] = t3;
					if (q == 1) {
						path[q][k].c = 'd';
					} else {
						path[q][k].c = 'u';
					}
					path[q][k].prev = &(path[q][kp]);
					hash[q][k] = true;
				}
			}
			if (p % 3 != 0) {
				int t3 = (t[q] + 1) % 30000;
				int i;
				int *b = list[q][t3];
				for (i = 0; i < 9; i++) {
					b[i] = a[i];
				}
				temp = b[p];
				b[p] = b[p - 1];
				b[p - 1] = temp;
				b[9] = p - 1;
				long int k = kangtuo(b);
				if (!hash[q][k]) {
					t[q] = t3;
					if (q == 1) {
						path[q][k].c = 'l';
					} else {
						path[q][k].c = 'r';
					}
					path[q][k].prev = &(path[q][kp]);
					hash[q][k] = true;
				}
			}
			if (p % 3 != 2) {
				int t3 = (t[q] + 1) % 30000;
				int i;
				int *b = list[q][t3];
				for (i = 0; i < 9; i++) {
					b[i] = a[i];
				}
				temp = b[p];
				b[p] = b[p + 1];
				b[p + 1] = temp;
				b[9] = p + 1;
				long int k = kangtuo(b);
				if (!hash[q][k]) {
					t[q] = t3;
					if (q == 1) {
						path[q][k].c = 'r';
					} else {
						path[q][k].c = 'l';
					}
					path[q][k].prev = &(path[q][kp]);
					hash[q][k] = true;
				}
			}
			h[q] = (h[q] + 1) % 30000;
		}
		if (hash[0][kangtuo(a)]) {
			eprint(kangtuo(a));
		}else{
			printf("unsolvable\n");
		}
	}
}