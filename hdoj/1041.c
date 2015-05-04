#include <stdio.h>

void getHex(int d) {
	int d1[4] = {2, 5, 10, 1};
	int d2[2] = {10, 5};
	int d3[2] = {11, 5};
	int d4[7] = {0, 0, 1, 1, 3, 5, 11};
	if (d <= 6) {
		printf("%d\n", d4[d]);
		return;
	}
	int a = d1[d % 4], b = d2[d % 2], c = d3[d % 2], l = (d - 7) / 4, i;
	int ls[350] = {0};
	ls[0] = a;
	for (; l > 0; l--) {
		for (i = 0;i < 340; i++) {
			ls[i] = ls[i] * 16;
		}
		ls[0] += b;
		for (i = 0; i < 340; i++) {
			ls[i + 1] += ls[i] / 10;
			ls[i] = ls[i] % 10;
		}
	}
	for (i = 0;i < 340; i++) {
		ls[i] = ls[i] * 16;
	}
	ls[0] += c;
	for (i = 0; i < 340; i++) {
		ls[i + 1] += ls[i] / 10;
		ls[i] = ls[i] % 10;
	}
	i = 350;
	while (ls[--i] == 0) {}
	while (i >= 0) {
		printf("%d", ls[i--]);
	}
	printf("\n");
}

int main() {
	int d;
	while (scanf("%d", &d) != EOF) {
		getHex(d);
	}
}