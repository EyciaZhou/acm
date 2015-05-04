#include <stdio.h>
#include <stdlib.h>
int main(){
	double s;
	while(scanf("%lf",&s)!=EOF)
	{
		if(s<0) s=-s;
		printf("%.2lf\n",s); 
	}
	return 0;
}
