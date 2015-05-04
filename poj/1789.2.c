#include <iostream>
#include <string.h>
using namespace std;

string list[2005];
long map[2005][2005];
bool v[2005];
long dis[2005];

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		memset(v, false, sizeof(v));
		memset(map, 0, sizeof(map));
		memset(dis, 0, sizeof(dis));
		for (int i = 0; i < n; i++) {
			cin >> list[i];
			for (int j = 0; j < i; j++) {
				int far = 0;
				for (int k = 0; k < 7; k++) {
					if (list[i][k] != list[j][k]) {
						far++;
					}
				}
				map[i][j] = map[j][i] = far;
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
		cout << "The highest possible quality is 1/" << res << ".\n";
	}
}