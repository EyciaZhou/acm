#include "stdio.h"
#include "stdlib.h"

#define MAX_A 20
long long resultA[MAX_A];
long long resultB[MAX_A] = { 0, 1 };

void Init();
long long C(long x, long y);

int main(){
	long num;
	long num1;
	long num2;
	Init();
	C(20, 10);
	scanf("%ld", &num);
	while (num--){
		scanf("%ld %ld", &num1, &num2);
		printf("%lld\n", C(num1, num2)*resultB[num2 - 1]);
	}
	return EXIT_SUCCESS;
}

void Init(){
	long i;
	resultA[0] = 1;
	for (i = 1; i < MAX_A; i++){
		resultA[i] = resultA[i - 1] * (i + 1);
	}
	for (i = 2; i < MAX_A; i++){
		//错排公式
		resultB[i] = i*(resultB[i - 1] + resultB[i - 2]);
	}
}

long long C(long x, long y){
	long long result;
	result = resultA[x - 1] / resultA[y - 1];
	if (x != y)
		result /= resultA[x - y - 1];
	return result;
}