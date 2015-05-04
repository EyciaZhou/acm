#include <stdio.h>


	unsigned char a[1250000];
int main(){
	unsigned long int k, n;
	for (long int i = 0; i < 1250000; i++) {
		a[i] = 0;
	}
	scanf("%lu", &n);
	for (long int i = 0; i < n; i++) {
		scanf("%uld", &k);
		a[k/8] = a[k/8] | (1 << (k % 8));
	}
	k = 0;
	for (long int i = 0; i < 1250000; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[i] & (1 << j)) {
				printf("%lu\n", k);
			}
			k++;
		}
	}	
	return 0;
}
