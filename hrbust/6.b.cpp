#include <iostream>
#include <cstdio>
using namespace std;

char s[5];
int f[20][70000];
int dic[70000];

int masks[16] = {
	0x0000,

	0x000f,
	0x00f0,
	0x0f00,
	0xf000,

	0x00ff,
	0x0f0f,
	0x0ff0,
	0xf00f,
	0xf0f0,
	0xff00,

	0x0fff,
	0xf0ff,
	0xff0f,
	0xfff0,

	0xffff,
};

int mm[255];

int main() {
	int n;
	for (int i = 0; i <= 9; i++) {
		mm[i + '0'] = i;
	}
	for (int i = 0; i < 6; i++) {
		mm[i + 'a'] = 10 + i;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		int tt = 0;
		for (int k = 0; k < 4; k++) {
			tt = tt * 16 + mm[s[k]];
		}
		dic[i] = tt;
	}
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < n; j++) {
			f[i][masks[i] & dic[j]]++;
		}
	}
	int t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	for (int k = 0; k <= 0; k++) {
		for (int i = 0; i < 0xffff; i++) {
			t4 += f[k][i] * (f[k][i] - 1) / 2;
		}
	}
	for (int k = 1; k <= 4; k++) {
		for (int i = 0; i < 0xffff; i++) {
			t3 += f[k][i] * (f[k][i] - 1) / 2;
		}
	}
	for (int k = 5; k <= 10; k++) {
		for (int i = 0; i < 0xffff; i++) {
			t2 += f[k][i] * (f[k][i] - 1) / 2;
		}
	}
	for (int k = 10; k <= 14; k++) {
		for (int i = 0; i < 0xffff; i++) {
			t1 += f[k][i] * (f[k][i] - 1) / 2;
		}
	}
	for (int  k = 15; k <= 15; k++) {
		for (int i = 0; i < 0xffff; i++) {
			t0 += f[k][i] * (f[k][i] - 1) / 2;
		}
	}

	printf("%d %d %d %d\n", t1 - t0, t2 - t1, t3 - t2, t4 -t3);
}