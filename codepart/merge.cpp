#include <iostream>
using namespace std;

long int a[1000000];

void _guibin(long int *cc, long int *tt, long int s, long int e) {
	if (s - e == 0) {
		return;
	}
	long int mid = (s + e) / 2;
	_guibin(cc, tt, s, mid);
	_guibin(cc, tt, mid + 1, e);
	long int i = s;
	long int j = mid + 1;
	long int k = 0;
	while (i <= mid && j <= e) {
		if (cc[i] < cc[j]) {
			tt[k] = cc[i];
			i++;
		}else {
			tt[k] = cc[j];
			j++;
		}
		k++;
	}
	if (i <= mid) {
		for (long int ii = i; ii <= mid; ii++) {
			tt[k] = cc[ii];
			k++;
		}
	}
	if (j <= e) {
		for (long int ii = j; ii <= e; ii++) {
			tt[k] = cc[ii];
			k++;
		}
	}
	for (long int i = 0; i <= e - s; i++) {
		cc[s + i] = tt[i];
	}
}

void guibin(long int *cc, long int n) {
	long int tt[n];
	_guibin(cc, tt, 0, n - 1);	
}

int main() {
	long int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	guibin(a, n);
	for (i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
