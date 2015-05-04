#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

long map[105][105];
bool v[105];
long dis[105];

int main() {
	while (true) {
		int n;
		if (scanf("%d", &n) == EOF) {
			return 0;
		}
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
		int res = 0;
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
			res += min;
			
			for (int i = 0; i < n; i++) {
				if (!v[i] && dis[i] > map[dst][i]) {
					dis[i] = map[dst][i];
				}
			}
		}
		cout << res << endl;
	}
}