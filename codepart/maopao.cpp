#include <iostream>
using namespace std;

long int a[1000000];

void insert(long int *cc, long int n) {
	long int tt, tj;
	for (long int i = 0; i < n - 1; i++) {
		tt = cc[i];
		tj = i;
		for (long int j = i + 1; j < n; j++) {
			if (tt > cc[j]) {
				tt = cc[j];
				tj = j;
			}
		}
		cc[tj] = cc[i];
		cc[i] = tt;
	}
}

int main() {
	long int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	insert(a, n);
	for (i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
