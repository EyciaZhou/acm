#include <stdio.h>
#include <stdlib.h>
int main()
{
	int score;
	while(scanf("%d",&score)!=EOF)
	{
		if (score > 100 || score < 0) {
			printf("Score is error!\n");
			continue;
		}
		if (score <= 59) {
			printf("E\n");
			continue;
		}
		if (score <= 69) {
			printf("D\n");
			continue;
		}
		if (score <= 79) {
			printf("C\n");
			continue;
		}
		if (score <= 89) {
			printf("B\n");
			continue;
		}
		printf("A\n");
	}
}