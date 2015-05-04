#include <iostream>
using namespace std;
int main() {
	int n, k, tot = 0, max = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		tot += k;
		max = k > max ? k : max;
	}
	cout << max + tot << endl;
}