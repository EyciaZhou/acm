#include <iostream>
using namespace std;

void modify_heap(int *cc, int k, int n) {
	int kk = k;
	int ii, jj;
	int l, te;
	do {
		ii = kk * 2 + 1;
		jj = kk * 2 + 2;
		l = kk;
		if ((ii < n) && (cc[ii] > cc[l])) {
			l = ii;
		}
		if ((jj < n) && (cc[jj] > cc[l])) {
			l = jj;
		}
		if (l == kk) {
			break;
		}
		te = cc[l];
		cc[l] = cc[kk];
		cc[kk] = te;
		kk = l;
	}while (1);
}

void build_heap(int *cc, int n) {
	for (int i = n/2; i >= 0; i--) {
		modify_heap(cc, i, n);
	}
}

void heap_sort(int *cc, int n) {
	int tt;
	for (int i = n - 1; i > 0; i--) {
		tt = cc[0];
		cc[0] = cc[i];
		cc[i] = tt;
		modify_heap(cc, 0, i);
	}
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build_heap(a, n);
	heap_sort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
