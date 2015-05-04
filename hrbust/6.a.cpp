#include <iostream>
#include <string.h>
using namespace std;

int ll[100005];
int c[100005];

int main() {
	int n;
	cin >> n;
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) {
		cin >> ll[i];
	}
	int now = 0;
	for (int i = 1; i < n; i++) {
		c[i]++;
		c[now]++;
		if (ll[i] < ll[now]) {
			now = i;
		}
	}
	int max = -1, p;
	for (int i = 0; i < n; i++) {
		if (c[i] > max) {
			max = c[i];
			p = i;
		}
	}
	cout << p + 1 << endl;
}