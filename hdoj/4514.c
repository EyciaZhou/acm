#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct NODE {
	long int 		next;
	long int		d;
	long int		v;
}link;

link		mem[2000005];
long int	memp;
long int	fa[100005];			
long int	l[100005];			
long int	fath[100005];		
bool		v[100005];			
long long int	f[100005];			
long int	stack[100005];		
long int	stackl[100005];
long int 	stackp;				
long long int res;


long int gf(long int s) {
	long int k = s;
	while (fa[k] != k) {
		k = fa[k];
	}
	long int k2 = s, t;
	while (fa[k2] != k2) {
		t = fa[k2];
		fa[k2] = k;
		k2 = t;
	}
	return k;
}

void work(long int node) {
	long int p, q, now;
	link *qq;
	long long int m1, m2, temp;
	stackp = 0;
	stack[0] = node;
	stackl[0] = l[node];
	v[node] = true;
	while (stackp >= 0) {
		p = stackl[stackp];
		now = stack[stackp];
		if (p == 0) {
			q = l[now];
			qq = &(mem[q]);
			m1 = -1;
			m2 = -1;
			while (q != 0) {
				qq = &(mem[q]);
				if (fath[qq->d] == now && f[qq->d] + qq->v > m1) {
					m1 = f[qq->d] + qq->v;
					if (m1 > m2) {
						temp = m1;
						m1 = m2;
						m2 = temp;
					}
				}
				q = qq->next;
			}
			if (m1 >= 0 && m1 + m2 > res) {
				res = m1 + m2;
			}
			if (m2 >= 0) {
				f[now] = m2;
			}
			stackp--;
		} else {
			qq = &(mem[p]);
			stackl[stackp] = mem[stackl[stackp]].next;
			if (!v[qq->d]) {
				stack[stackp+1] = qq->d;
				stackl[stackp+1] = l[qq->d];
				v[qq->d] = true;
				fath[qq->d] = now;
				stackp++;
			}
		}
	}
} 

int main() {
	long int n, m, i;
	long int u, vv, w;
	n = 0;
	for (i = 0; i < 100005; i++) {
		l[i] = 0;
	}
	while (true) {
		memp = 0;
		memset(l, 0, sizeof(l));
		if (scanf("%ld %ld", &n, &m) == EOF) {
			return;
		}
		for (i = 1; i <= n; i++) {
			fa[i] = i;
		}
		bool find = false;
		for (i = 1; i <= m; i++) {
			scanf("%ld %ld %ld", &u, &vv, &w);
			
			if (!find) {

				memp++;
			
				mem[memp].d = vv;
				mem[memp].v = w;
				mem[memp].next = l[u];
				l[u] = memp;

				memp++;

				mem[memp].d = u;
				mem[memp].v = w;
				mem[memp].next = l[vv];
				l[vv] = memp;
			
				if (gf(u) == gf(vv)) {
					printf("YES\n");
					find = true;
				} else {
					fa[gf(u)] = gf(vv);
				}
			}
		}
		if (find) {
			continue;
		}
		memset(v, false, sizeof(v));
		memset(f, 0, sizeof(f));
		memset(fath, 0, sizeof(fath));
		res = -1;
		for (i = 1; i <= n; i++) {
			if (!v[i]) {
				work(i);
			}
		}
		for (i = 1; i <= n; i++) {
			if (res < f[i]) {
				res = f[i];
			}
		}
		printf("%I64d\n", res);
	}
}
