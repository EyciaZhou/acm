#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int f[205][205][205];

int N, a, b;
char str[205];

void dfs(int i, int j, int k) {
    if (i == 0) return;
    if (str[i] == '0') {
        if (j - 1 >= 0 && f[i][j][k] == f[i-1][j-1][k]) dfs(i-1, j-1, k);
        else if (k - 1 >= 0 && f[i][j][k] == f[i-1][j][k-1] + 1) str[i] = '1', dfs(i-1, j, k-1);
        else if (f[i][j][k] == f[i-1][j][k] + 1) str[i] = '2', dfs(i-1, j, k);
    } else if (str[i] == '1') {
        if (j - 1 >= 0 && f[i][j][k] == f[i-1][j-1][k] + 1) str[i] = '0', dfs(i-1, j-1, k);
        else if (k - 1 >= 0 && f[i][j][k] == f[i-1][j][k-1]) dfs(i-1, j, k-1);
        else if (f[i][j][k] == f[i-1][j][k] + 1) str[i] = '2', dfs(i-1, j, k);
    } else {
        if (j - 1 >= 0 && f[i][j][k] == f[i-1][j-1][k] + 1) str[i] = '0', dfs(i-1, j-1, k);
        else if (k - 1 >= 0 && f[i][j][k] == f[i-1][j][k-1] + 1) str[i] = '1', dfs(i-1, j, k-1);
        else if (f[i][j][k] == f[i-1][j][k]) dfs(i-1, j, k);
    }
}

void gao() {
    memset(f, 0x3f, sizeof (f));
    f[0][0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= i-j; ++k) {
                int Min = 100000;
                if (str[i] == '0') {
                    if (j - 1 >= 0)
                        Min = min(Min, f[i-1][j-1][k]);
                    if (k - 1 >= 0)
                        Min = min(Min, f[i-1][j][k-1] + 1);
                    Min = min(Min, f[i-1][j][k] + 1);
                } else if (str[i] == '1') {
                    if (j - 1 >= 0)
                        Min = min(Min, f[i-1][j-1][k] + 1);
                    if (k - 1 >= 0)
                        Min = min(Min, f[i-1][j][k-1]);
                    Min = min(Min, f[i-1][j][k] + 1);
                } else {
                    if (j - 1 >= 0)
                        Min = min(Min, f[i-1][j-1][k] + 1);
                    if (k - 1 >= 0)
                        Min = min(Min, f[i-1][j][k-1] + 1);
                    Min = min(Min, f[i-1][j][k]);
                }
                f[i][j][k] = Min;
            }
        }
    }
    printf("%d\n", f[N][a][b]);
    dfs(N, a, b);
    for (int i = 1; i <= N; ++i) {
        printf("%c", str[i]);
    }
    puts("");
}

int main() {
    scanf("%d %d %d", &N, &a, &b);
        scanf("%s", str+1);
        if (strlen(str+1) != N || a + b > N) {
            puts("-1");
            return 0;
        }
        gao();
    return 0;
}