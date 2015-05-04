#include <iostream>
using namespace std;

int main() {
	int n, k;
	long dst, far;
	long map[105][105];
	while (cin >> n, n != 0) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				map[i][j] = -1;
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> k;
			for (int j = 0; j < k; j++) {
				cin >> dst >> far;
				map[i][dst] = far;
			}
		}

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (map[i][k] >= 0 && map[k][j] >= 0) {
						if (map[i][j] < 0 || map[i][j] > map[i][k] + map[k][j]) {
							map[i][j] = map[i][k] + map[k][j];
						}
					}
				}
			}
		}

		int min = 1000000000;
		int pp = 0;
		for (int i = 1; i <= n; i++) {
			int max = -1;
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					if (map[i][j] >= 0 && map[i][j] > max) {
						max = map[i][j];
					}
					if (map[i][j] < 0) {
						max = 1000000000;
					}
				}
			}
			if (max >= 0 && max < min) {
				pp = i;
				min = max;
			}
		}
		if (min == 1000000000) {
			cout << "disjoint" << endl;
		} else {
			cout << pp << " " << min << endl;
		}
	}
}