#include <stdio.h>

int main() {
    int pi[4] = {-1, 0, 0, 1};
    int pj[4] = {0, 1, -1, 0};
    int i, j, n, m, e, ti, tj;
    int ch[12][12];
    char c;
    int pa[12][12];
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }
        scanf("%d", &e);
        for (i = 0; i < n; i++) {
            getchar();
            for (j = 0; j < m; j++) {
                scanf("%c", &c);
                switch (c) {
                    case 'N' : ch[i][j] = 0; break;
                    case 'E' : ch[i][j] = 1; break;
                    case 'W' : ch[i][j] = 2; break;
                    case 'S' : ch[i][j] = 3; break;
                }
            }
        }
        for (i = 0; i < 11; i++) {
            for (j = 0; j < 11; j++) {
                pa[i][j] = 30000;
            }
        }
        i = 0;
        j = e - 1;
        pa[i][j] = 0;
        
        while (1) {
            ti = i;
            tj = j;
            i = ti + pi[ch[ti][tj]];
            j = tj + pj[ch[ti][tj]];
            if (i < 0 || i >= n || j < 0 || j >= m) {
                printf("%d step(s) to exit\n", pa[ti][tj] + 1);
                break;
            }
            if (pa[i][j] < 30000) {
                printf("%d step(s) before a loop of %d step(s)\n", pa[i][j], pa[ti][tj] - pa[i][j] + 1);
                break;
            }
            pa[i][j] = pa[ti][tj] + 1;
        }
    }
}