#include <map>
#include <iostream>
using namespace std;

int main() {
	map<string, int> bz = map<string, int>();
	string st, maohao, cai;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> st;
			bz.insert(pair<string, int>(st, i));
		}
	}
	int t;
	int max = -1;
	int num = 0;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		int count = 0;
		while (k--) {
			int f = 0;
			cin >> st >> maohao >> cai;
			if (cai == "gold") {
				f = 0;
			}
			if (cai == "silver") {
				f = 1;
			}
			if (cai == "bronze") {
				f = 2;
			}
			if (bz.find(st) != bz.end()) {
				if (bz[st] == f) {
					count += 5;
				}
			}
		}
		if (count == max) {
			num++;
		}
		if (count > max) {
			max = count;
			num = 1;
		}
	}
	cout << 5 * num;
}