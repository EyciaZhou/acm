#include <iostream>
using namespace std;

long int a[1000000];

void insert(long int *cc, long int n) {
	for (long int i = 1; i < n; i++)  {
		long int j = i - 1;
		for (j = i - 1; j >= 0 && cc[j] > cc[i]; j--);
		long int temp = cc[i];
		for (long int k = i; k > j + 1; k--) {
			cc[k] = cc[k - 1];
		}
		cc[j + 1] = temp;
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
