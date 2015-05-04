#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

long map[505][505];
bool v[505];
long dis[505];

int main() {
	int ff;
	scanf("%d", &ff);
	while (ff--) {
		int n;
		scanf("%d", &n);
		memset(v, false, sizeof(v));
		memset(map, 0, sizeof(map));
		memset(dis, 0, sizeof(dis));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%ld", &map[i][j]);
			}
		}

		v[0] = true;
		int tot = 1;
		int res = -1;
		for (int i = 0; i < n; i++) {
			dis[i] = map[0][i];
		}
		while (tot < n) {
			long min = 1000000000;
			long dst = 0;
			for (int i = 0; i < n; i++) {
				if (!v[i] && dis[i] < min) {
					min = dis[i];
					dst = i;
				}
			}
			v[dst] = true;
			tot++;
			if (min > res) {
				res = min;
			}
			
			for (int i = 0; i < n; i++) {
				if (!v[i] && dis[i] > map[dst][i]) {
					dis[i] = map[dst][i];
				}
			}
		}
		cout << res << endl;
	}
}