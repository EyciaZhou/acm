#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool map[30][30];
int ii[30];
int oo[30];
int n, m;
char tt[30];

bool circle() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[j][i] = map[j][i] | (map[j][k] && map[k][i]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (map[i][i]) {
			return true;
		}
	}
	return false;
}

void top() {
	memset(ii, 0, sizeof(ii));
	memset(oo, 0, sizeof(oo));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				ii[j]++;
				oo[i]++;
			}
		}
	}
	int p = 0;
	while (true) {
		bool ff = false;
		for (int i = 0; i < n; i++) {
			if (oo[i] == 0) {
				ff = true;
				tt[p] = 'A' + i;
				p++;
				oo[i] = -1;
				for (int j = 0; j < n; j++) {
					if (map[j][i]) {
						oo[j]--;
					}
				}
				break;
			}
		}
		if (!ff) {
			break;
		}
	}
	tt[p] = '\0';
}

bool sorted() {
	memset(ii, 0, sizeof(ii));
	memset(oo, 0, sizeof(oo));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				ii[i]++;
				oo[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ii[i] + oo[i] != n - 1) {
			return false;
		}
	}
	return true;
}

int main() {
	while (true) {
		char a, b;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		memset(map, false, sizeof(map));
		bool flag = false;
		bool flag2 = false;
		int pos;
		for (int i = 0; i < m; i++) {
			getchar();
			a = getchar();
			getchar();
			b = getchar();
			map[a - 'A'][b - 'A'] = true;
			if (flag || flag2) {
				continue;
			}
			if (circle()) {
				pos = i;
				flag = true;
			}
			if (!flag2 && sorted()) {
				top();
				pos = i;
				flag2 = true;
			}
		}
		if (flag) {
			cout << "Inconsistency found after " << pos + 1 << " relations." << endl;
		} else {
			if (flag2) {
				cout << "Sorted sequence determined after "<< pos + 1 <<" relations: ";
				for (int i = strlen(tt) - 1; i >= 0; i--) {
					cout << tt[i];
				}
				cout << "." << endl;
			} else {
				cout << "Sorted sequence cannot be determined." << endl;
			}
		}
	}
}