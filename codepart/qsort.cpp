#include <iostream>
using namespace std;

long int a[1000000];

void _qsort(long int *cc, long int s, long int e) {
	if (s < e) {
		long int te;
		long int k = cc[e];
		long int i = s - 1;
		for (long int j = s; j <= e - 1; j++) {
			if (cc[j] <= k) {
				i++;
				te = cc[i];
				cc[i] = cc[j];
				cc[j] = te;
			}
		}
		te = cc[i + 1];
		cc[i + 1] = cc[e];
		cc[e] = te;
		_qsort(cc, s, i);
		_qsort(cc, i + 2, e);
	}
}

void qsort(long int *cc, long int n) {
	_qsort(cc, 0, n - 1);
}

int main() {
	long int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	qsort(a, n);
	for (i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
