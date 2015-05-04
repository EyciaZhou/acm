#include <iostream>
using namespace std;

unsigned char a[1250000];

int main(){
	unsigned long int k, n;
	for (long int i = 0; i < 1250000; i++) {
		a[i] = 0;
	}
	cin >> n;
	for (long int i = 0; i < n; i++) {
		cin >> k;
		a[k/8] = a[k/8] | (1 << (k % 8));
	}
	k = 0;
	for (long int i = 0; i < 1250000; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[i] & (1 << j)) {
				cout << k << endl;
			}
			k++;
		}
	}	

	return 0;
}
