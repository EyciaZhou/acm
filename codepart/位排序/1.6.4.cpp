#include <iostream>
#include <cstdlib>
#define n 10000000
#define m 10000000
using namespace std;

unsigned long int a[n];

int main(){
	unsigned long int t;
	long int k;
	for (long int i = 0; i < n; i++) {
		a[i] = i;
	}
	for (long int i = 0; i < m; i++) {
		k = random() % (n - i) + i;
		t = a[k];
		a[k] = a[i];
		a[i] = t;
	}
	cout << m << endl;
	for (long int i = 0; i < m; i++) {
		cout << a[i] << endl;
	}
}
