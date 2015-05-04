#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
	char __[10];
	char n, h, l, f;
	char map[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = (i + j) % 2 ? ':' : '.';
		}
	}
	for (int ll = 0; ll < 2; ll++) {
		scanf("%s", __);
		getchar();
		if (strcmp(__, "Black:\0")) {
			while (true) {
				f = getchar();
				if (f >= 'A' && f <= 'Z') {
					n = f;
					h = getchar();
					l = getchar();
				} else {
					n = 'P';
					h = f;
					l = getchar();
				}
				map[7 - l + '1'][h-'a'] = n;
				l = getchar();
				if (l == '\n') {
					break;
				}
			}
		} else {
			while (true) {
				f = getchar();
				if (f >= 'A' && f <= 'Z') {
					n = f;
					h = getchar();
					l = getchar();
				} else {
					n = 'P';
					h = f;
					l = getchar();
				}
				map[7 - l + '1'][h-'a'] = n - 'A' + 'a';
				l = getchar();
				if (l == EOF || l == '\n') {
					break;
				}
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		puts("+---+---+---+---+---+---+---+---+");
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				printf("|.%c.", map[i][j]);
			} else {
				printf("|:%c:", map[i][j]);
			}
		}
		printf("|\n");
	}
	puts("+---+---+---+---+---+---+---+---+");
}