#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
	int n[27];
	int f;
	int d;
	int fa;
	bool b;
} NODE;

int n = 26;

NODE tire[1005];

void dof() {
	int i, j;
	int list[1005];
	int h = -1, t = 0;
	for (i = 0; i <= n; i++) {
		if (tire[0].n[i] >= 0) {
			tire[tire[0].n[i]].f = 0;
			for (j = 0; j <= n; j++) {
				if (tire[tire[0].n[i]].n[j] >= 0) {
					h = (h + 1) % 1005;
					list[h] = tire[tire[0].n[i]].n[j];
				}
			}
		}
	}
	while ((h + 1) % 1005 != t) {
		//printf("%d\n", t);
		int p = list[t];
		t = (t + 1) % 1005;
		for (i = 0; i <= n; i++) {
			if (tire[p].n[i] >= 0) {
				h = (h + 1) % 1005;
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
	long T;
	int n, i, j, q, p;
	char st[55], c;
	bool f;
	scanf("%ld", &T);
	while (T--) {
		for (i = 0; i < 1005; i++) {
			for (j = 0; j <= 26; j++) {
				tire[i].n[j] = -1;
			}
			tire[i].f = 0;
			tire[i].d = -1;
			tire[i].b = false;
		}
		scanf("%d", &n);
		p = 0;
		for (i = 0; i < n; i++) {
			scanf("%s", st);
			q = 0;
			for (j = 0; j < strlen(st); j++) {
				
				if (st[j] >= 'a' && st[j] <= 'z') {
					if (tire[q].n[st[j] - 'a'] < 0) {
						tire[q].n[st[j] - 'a'] = ++p;
						tire[p].d = st[j] - 'a';
						tire[p].fa = q;
					}
					q = tire[q].n[st[j] - 'a'];
				}
			}
			tire[q].b = true;
		}
		getchar();
		dof();
		q = 0;
		f = true;
		while (true) {
			c = getchar();
			if (c == '\n' || c == EOF) {
				break;
			}

			q = getnext(q, c - 'a');
			if (tire[q].b) {
				f = false;
			}
			
		}
		if (f) {
			printf("not infected\n");
		}else{
			printf("infected\n");
		}
	}
}