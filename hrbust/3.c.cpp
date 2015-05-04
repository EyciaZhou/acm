#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a[105];
	int n;
	double tot = 0, tot2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tot += a[i];
	}
	double ave = tot / (double)(n + 1);
	for (int i = 0; i < n; i++) {
		a[i] -= ave;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			tot2 += a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			cout << floor(100 * a[i] / tot2 + 0.0001) << " ";
		} else {
			cout << "0 ";
		}
	}
	cout << endl;
}