#include <stdio.h>

int main() {
	char c;
	int i, j, d;
	int f = 1;
	while (1) {
		scanf("%c", &c);
		if (c == '@') {
			break;
		}
		scanf("%d", &d);
		if (!f) {
			printf("\n");
		}
		f = 0;
		if (d == 1) {
			printf("%c\n", c);
			getchar();
			continue;
		}
		for (j = 0; j < d - 1; j++) {
			printf(" ");
		}
		printf("%c\n", c);
		for (i = 1; i < d - 1; i++) {
			for (j = 0; j < d - i - 1; j++) {
				printf(" ");
			}
			printf("%c", c);
			for (j = 0; j < 2 * i - 1; j++) {
				printf(" ");
			}
			printf("%c\n", c);
		}
		for (j = 0; j < 2 * d - 1; j++) {
			printf("%c", c);
		}
		printf("\n");
		getchar();
	}
}