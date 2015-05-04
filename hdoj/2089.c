#include <stdio.h>

int main() {
	int n, i;
	double a0, an1, c, tot;
	while (scanf("%d", &n) != EOF) {
		scanf("%lf %lf", &a0, &an1);
		tot = 0;
		for (i = 0; i < n; i++) {
			scanf("%lf", &c);
			tot += (2 * (n - i) * c);
		}
		printf("%.2lf\n", a0*n/(n+1) + an1/(n+1) - tot/(n+1));
	}
}