#include <stdio.h>

int main()
{
	int year,mon,day,l,sum,i;
	int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	while(scanf("%d/%d/%d",&year,&mon,&day)!=EOF)
	{
		sum = 0;
    	if ((year%4==0 && year % 100 != 0) || year % 400 == 0)
     	{
     		if (mon > 2) {
     			sum += 1;
     		}
    	}
    	
    	for (i = 1; i < mon; i++) {
    		sum += m[i];
    	}
		sum += day;
		printf("%d\n", sum);
	}
}