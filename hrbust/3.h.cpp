#include <iostream>
using namespace std;

int main() {
	int n;
	int a[105][105];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	long c = 0;
	long cars = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			c -= a[j][i];
		}
		for (int j = i + 1; j <= n; j++) {
			c += a[i][j];
		}
		if (c > cars) {
			cars = c;
		}
	}
	for (int i = n; i >= 1; i--) {  
        for (int j = n; j > i; j--) {
            c -= a[j][i];  
        }
        for (int j = i - 1; j >= 1; j--) {  
            c += a[i][j];  
        }  
        if (c > cars) {
			cars = c;
		}
    }  
	cout << (cars + 35) / 36;
}