#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

unsigned long long fib[100];

int p = 3;

void init() {
	fib[0] = 0;
	fib[1] = 3;
	fib[2] = 7;
	while (fib[p - 1] > fib[p-2]) {
		fib[p] = fib[p-1] + fib[p-2];
		p++;
	} 
}

unsigned long long gg(unsigned long long k) {
	for (int i = 0; i < p; i++) {
		if (fib[i] >= k) {
			return fib[i-1];
		}
	}
	return fib[p-2];
}

int main() {
	unsigned long long n;
	init();
	while (scanf("%llu", &n) != EOF) {
		while (n > 7) {
			n = n - gg(n);
		}
		cout << "T.T^__^"[n - 1] << endl;
	}
}