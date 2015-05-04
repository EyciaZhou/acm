/*
 start : 2014-12-18 01:18:05 Thursday
 aced : 2014-12-18 01:43:36 Thursday
 */

#include <cstdio>
#include <cstring>

char mat[105][105];

int n, m;

bool dr[105];

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s", mat[i]);
        }
        int vv = 0;
        memset(dr, true, sizeof(dr));
        for (int i = 0; i < m; i++) {
            bool flag = false;
            for (int j = 1; j < n; j++) {
                if (dr[j] && mat[j][i] < mat[j-1][i]) {
                    vv++;
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            for (int j = 1; j < n; j++) {
                if (dr[j] && mat[j][i] > mat[j-1][i]) {
                    dr[j] = false;
                }
            }
        }
        printf("%d\n", vv);
    } 
}