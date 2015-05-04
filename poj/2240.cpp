#include <iostream>
#include <map>
using namespace std;

int main() {
	int ff = 0;
	while (true) {
		int n, m;
		map<string, int> ref;
		cin >> n;
		ff++;
		if (n == 0) {
			return 0;
		}
		string st, st2;
		double rate;
		double table[35][35];
		for (int i = 0; i < n; i++) {
			cin >> st;
			ref[st] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				table[i][j] = -1;
			}
		}
		for (int i = 0; i < n; i++) {
			table[i][i] = 1;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> st >> rate >> st2;
			table[ref[st]][ref[st2]] = rate;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (table[i][k] >= 0 && table[k][j] >= 0) {
						if (table[i][j] < 0 || table[i][j] < table[i][k] * table[k][j]) {
							table[i][j] = table[i][k] * table[k][j];
						}
					}
				}
			}
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (table[i][i] > 1) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "Case " << ff << ": Yes" << endl;
		} else {
			cout << "Case " << ff << ": No" << endl;
		}
	}
}