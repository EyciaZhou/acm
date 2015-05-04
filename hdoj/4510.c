#include <stdio.h>

int main() {
	long int n;
	long int s1, s2, s3, e1, e2, e3;
	long int s, e;
	scanf("%ld", &n);
	while (n--) {
		scanf("%ld:%ld:%ld %ld:%ld:%ld", &s1, &s2, &s3, &e1, &e2, &e3);
		s = s1 * 3600 + s2 * 60 + s3;
		e = (e1 * 3600 + e2 * 60 + e3) % 43200;
		s = (s - e + 43200) % 43200;
		printf("%0.2d:%0.2d:%0.2d\n", s / 3600, s / 60 % 60, s % 60);
	}
}
