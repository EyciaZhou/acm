#include <stdio.h>
#include <string.h>

long long MOD = 1000000007;

long long f[50][500];

long long c[500][500];
long long a[500];

int main() {
	int T, ff, n, i, j, k, l;
	long long temp;
	int p[50], t[50];

    for(i=0; i<500; i++)  
    {  
        c[i][0]=c[i][i]=1;  
        for(j=1; j<i; j++)  
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;  //杨辉三角求组合
    }  
    a[0]=1;  
    for(i=1; i<500; i++)  
        a[i]=(a[i-1]*i)%MOD; 
	scanf("%d", &T);
	for (ff = 1; ff <= T; ff++) {
		scanf("%d", &n);
		t[0] = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
			t[i] = t[i-1] + p[i];
		}
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (i = 1; i <= n; i++) {
			for (j = 0; j < t[i] + 1; j++) {
				for (k = 1; k <= p[i]; k++) {
					for (l = 0; l <= k && l <= j; l++) {
						//l为丢到相同坑的人数，下行排列组合分别为：找出丢到相同坑的，丢到不同坑的，对人进行全排列，把人隔除k组
						//f[a][b]为前a个专业，排完座位后有b个空格为相同坑
						temp = ((((f[i-1][j] * c[j][l] % MOD) * c[t[i-1]-j+1][k-l] % MOD) * a[p[i]] % MOD) * c[p[i] - 1][k - 1]) % MOD;
						f[i][p[i] - k + j - l] = (f[i][p[i] - k + j - l] + temp) % MOD;
					}
				}
			}
		}
		printf("Case %d: %I64d\n",ff, f[n][0]);
	}
}