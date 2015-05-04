#include <iostream>
using namespace std;


int n;
long map[105][105];
long px[105];
long py[105];

bool ttry(long node) {
	if (node == n) {
		for (int i = 0; i < n; i++) {
			cout << px[i] << " " << py[i] << endl;
		}
		return true;
	}
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	px[0] = 0;
	py[0] = 0;
	ttry(1);
}