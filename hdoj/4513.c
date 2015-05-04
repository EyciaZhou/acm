#include <stdio.h>
#include <stdbool.h>

int d[100005];
long int p1[100005], p2[100005], p3[100005];
long int pp1, pp2, pp3;
long int n;
long int res;

void try(long int d1, long int d2) {
	while (true) {
		if (d1 - 1 < 0 || d2 + 1 > n || d[d1 - 1] != d[d2 + 1] || d[d1 - 1] > d[d1]) {
			break;
		}
		d1--;
		d2++;
	}
	if (d2 - d1 + 1 > res) {
		res = d2 - d1 + 1;
	}
}

void try1(long int k) {
	return try(k, k);
}

void try2(long int k) {
	return try(k, k + 1);
}

void try3(long int k) {
	return try(k, k);
}

void init() {
	pp1 = -1;
	pp2 = -1;
	pp3 = -1;
	long int i;
	long int k, s, e;
	for (i = 2; i < n; i++) {
		if (d[i-1] == d[i+1] && d[i] > d[i-1]) {
			p1[++pp1] = i;
		}
	}
	k = -1;
	s = 0;
	e = 0;
	d[n + 1] = -1;
	for (i = 1; i <= n + 1; i++) {
		if (d[i] != k) {
			k = d[i];
			if (s - e > 0) {
				if ((s - e) % 2 == 1) {
					p2[++pp2] = e + (s - e) / 2;
				}else{
					p3[++pp3] = e + (s - e) / 2;
				}
			}
			s = i;
			e = i;
		}else{
			s++;
		}
	}
}

int main() {
	int t;
	long int i;
	scanf("%d", &t);
	while (t--) {
		scanf("%ld", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &d[i]);
		}
		init();
		res = -1;
		for (i = 0; i <= pp1; i++) {
			try1(p1[i]);
		}
		for (i = 0; i <= pp2; i++) {
			try2(p2[i]);
		}
		for (i = 0; i <= pp3; i++) {
			try3(p3[i]);
		}
		printf("%ld\n", res);
	}
}
