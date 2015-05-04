#include <iostream>
#include <string.h>
using namespace std;

bool dt[505][505];
int n;
int res;
bool v[1005];
bool match[1005];
int to[1005];

int dfs(int k) {
	for (int i = 1; i <= 2 * n; i++) {
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
	res = 0;
	memset(match, false, sizeof(match));
	for (int i = 1; i <= 2 * n; i++) {
		if (!match[i]) {
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
	int k;
	int x, y;
	memset(dt, false, sizeof(dt));
	cin >> n >> k;
	for (int i = 0 ; i < k; i++) {
		cin >> x >> y;
		dt[x][y + n] = true;
		dt[y + n][x] = true;
	}
	cout << get();
}