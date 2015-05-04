#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	a.out [样本容量]

	从stdin数据流中随机取样「样本容量」个字节
*/

int main(int argv, char **argc) {
	srandom(time(0));
	if (argv < 2) {
		printf("error par\n");
	}
	int m = atoi(argc[1]);

	int i;
	char c;
	char *l = (char *)malloc(m * sizeof(char));
	long long length = m;
	
	for (i = 0; i < m; i++) {
		l[i] = getchar();
	}
	while ((c = getchar()) != EOF) {
		length++;
		if (random() % (1 << 20) * length < m * (1 << 20)) {	//rand < m/length 第length个元素有m/length的概率被留下
			l[random() % m] = c;								//决定留下后随机替换样本中一个元素, 其中每个元素留下的概率为 
																//			(m/length-1) * (m/length * 1/m + length-m/length)
		}
		if (length % 100 == 0) {
			for (i = 0; i < m; i++) {
				printf("%c", l[i]);
			}
			printf("\n");
		}
	}
}
