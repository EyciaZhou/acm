#include <stdio.h>

void sort(int *cc, int s, int e) {
	if (s >= e) {
		return;
	}
	int i = s - 1, j, k = cc[e], te;
	for (j = s; j <= e - 1; j++) {
		if (cc[j] <= k) {
			i++;
			te = cc[i];
			cc[i] = cc[j];
			cc[j] = te;
		}
	}
	te = cc[i+1];
	cc[i+1] = cc[e];
	cc[e] =te;
	sort(cc, s, i);
	sort(cc, i + 2, e);
}

int main() {
	int t;
	int ls[1005];
	scanf("%d", &t);
	for (; t > 0; t--) {
		int n, i;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &(ls[i]));
		}
		sort(ls, 0, n - 1);
		for (i = 0; i < n - 1; i++) {
			printf("%d ", ls[i]);
		}
		printf("%d", ls[n - 1]);
		if (t != 0) {
			printf("\n");
		}
	}
}