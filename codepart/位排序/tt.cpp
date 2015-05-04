#include <iostream>
#include <cstdio>
using namespace std;


int main(){
	std::ios::sync_with_stdio(false);
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	unsigned long int k, n;
unsigned char a[125000];
	for (long int i = 0; i < 125000; i++) {
		a[i] = 0;
	}
	cin >> n;
	for (long int i = 0; i < n; i++) {
		cin >> k;
		a[k/8] = a[k/8] | (1 << (k % 8));
	}
	k = 0;
	for (long int i = 0; i < 125000; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[i] & (1 << j)) {
				cout << k << endl;
			}
			k++;
		}
	}	
	return 0;
}
