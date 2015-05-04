#include <iostream>
using namespace std;

int main() {
	int n;
	int a[1005];
	int bx[1005], by[1005];
	int xx[1005] = {0};
	int pp[1005];
	cin >> n;
	bool mark = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> bx[i] >> by[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] <= by[j] && a[i] >= bx[j]) {
				xx[j]++;
			}
		}
	}
	for (int ff = 0; ff < n; ff++) {
		int f = -1;
		for (int i = 0; i < n; i++) {
			if (xx[i] == 0) {
				f = i;
				break;
			}
		}
		if (f >= 0) {
			cout << "Let's search for another office.\n";
			return 0 ;
		}
		f = -1;
		long m = 1000000;
		for (int i = 0; i < n; i++) {
			if (xx[i] > 0) {
				if (xx[i] < m) {
				//if (xx[i] == 1) {
					f = i;
					m = xx[i];
				}
			}
		}
		if (m != 1) {
		//if (f < 0) {
			mark = true;
			
		}
		int g = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] <= by[f] && a[i] >= bx[f]) {
				g = i;
				break;
			}
		}
		xx[f] = -1;
		for (int i = 0; i < n; i++) {
			if (a[g] <= by[i] && a[g] >= bx[i]) {
				xx[i]--;
			}
		}
		pp[f] = g;
		a[g] = -1;

	}
	if (mark) {
		cout << "Ask Shiftman for help.\n";
		return 0;
	}
	cout << "Perfect!" << endl;
	for (int i = 0; i < n; i++) {
		cout << pp[i] + 1 << " ";
	}
	cout << endl;
}