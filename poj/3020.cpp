#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

bool mmap[45][15];
bool dt[1005][1005];
bool po[1005];

int sx[4] = {0, 1, -1, 0};
int sy[4] = {1, 0, 0, -1};

bool v[1005];
bool match[1005];
int to[1005];

int N;

int dfs(int k) {
	for (int i = 1; i <= N; i++) {
		if (!po[i]) {
			continue;
		}
		if (v[i]) {
			continue;
		}
		v[i] = true;
		if (dt[k][i] && (dfs(to[i]) || !match[i])) {
			match[i] = true;
			to[i] = k;
			return true;
		}
		v[i] = false;
	}
	return false;
}

int get() {
	int res = 0;
	memset(match, false, sizeof(match));
	for (int i = 1; i <= N; i++) {
		if (po[i] && !match[i]) {
			memset(v, false, sizeof(v));
			if (dfs(i)) {
				res++;
				match[i] = true;
			}
		}
	}
	return res;
}

int main() {
	int ff;
	cin >> ff;
	while (ff--) {
		int n, m;
		cin >> n >> m;
		memset(mmap, false, sizeof(mmap));
		memset(dt, false, sizeof(dt));
		memset(po, false, sizeof(po));
		for (int i = 1; i <= n; i++) {
			getchar();
			for (int j = 1; j <= m; j++) {
				if (getchar() == '*') {
					mmap[i][j] = true;
				}
			}
		}
		int count = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (mmap[i][j]) {
					count++;
					po[i * (m + 1) + j] = true;
					for (int k = 0; k < 4; k++) {
						if (mmap[i + sx[k]][j + sy[k]]) {
							dt[i * (m + 1) + j][(i + sx[k]) * (m + 1) + (j + sy[k])] = true;
							dt[(i + sx[k]) * (m + 1) + (j + sy[k])][i * (m + 1) + j] = true;
						}
					}
				}
			}
		}
		N = n * (m+1) + m;
		cout << count - get() << endl;
	}
}