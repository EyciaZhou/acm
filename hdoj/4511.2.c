#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdbool.h>
#define MAX 1005
#define MAXSON 50
struct {
    int id, next[MAXSON], fail;
} node[1000000];

int n, tot;
char mod[1000005];
int len[MAX];
int q[1000000];
void clr() {
    int i;
    tot++;
    for(i = 0; i < MAXSON; i++)
        node[tot].next[i] = 0;
    node[tot].id = node[tot].fail = 0;
}
void ins() {
    int tmp, i, n;
    int h = 0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &tmp);
        tmp--;
        if(node[h].next[tmp] == 0) {
            clr();
            node[h].next[tmp] = tot;
        }
        h = node[h].next[tmp];
    }
    node[h].id++;
}
void get_fail() {
    int h = 0, i;
    int f = -1, r = 0;
    int tmp, fail, k;
    q[0] = 0;
    while(f != r) {
        tmp = q[++f];
        if(node[node[tmp].fail].id > 0)
            node[tmp].id = 1;
        for(i = 0; i < MAXSON; i++) {
            if(node[tmp].next[i] == 0) {
                fail = node[tmp].fail;
                node[tmp].next[i] = node[fail].next[i];
                continue;
            }
            k = node[tmp].next[i];
            fail = node[tmp].fail;
            if(node[fail].next[i] != k)
                node[k].fail = node[fail].next[i];
            else
                node[k].fail = 0;
            q[++r] = k;
        }
    }
}
const double EPS = 1.0e-8;
bool dblcmp(double x) {
    if(fabs(x) < EPS)return 0;
    return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
} p[55];
double disPP(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
const double INF = 1000000000.0 * 100000000.0;
double dp[55][5 * 110];
int main() {
    int n, m;
    int i, j, k;
    while(scanf("%d%d", &n, &m) != EOF) {
        if(n == 0 && m == 0)break;
        for(i = 1; i <= n; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        tot = -1;
        clr();
        while(m--) {
            ins();
        }
        get_fail();

        for(i = 0; i <= n; i++) {
            for(j = 0; j <= tot; j++) {
                dp[i][j] = INF;
            }
        }

        int h = node[0].next[0];

        if(node[h].id > 0) {
            puts("Can not be reached!");
            continue;
        }

        dp[1][h] = 0;
        double cost = 0;
        for(i = 1; i <= n; i++) {
            for(j = 0; j <= tot; j++) {
                if(dblcmp(dp[i][j] - INF) == 0)continue;
                for(k = i + 1; k <= n; k++) {
                    h = node[j].next[k - 1];
                    if(node[h].id)continue;
                    cost = disPP(p[i], p[k]) + dp[i][j];
                    if(cost < dp[k][h])dp[k][h] = cost;
                }
            }
        }

        double ans = INF;
        for(i = 0; i <= tot; i++) {
            if(dp[n][i] < ans)ans = dp[n][i];
        }

        if(dblcmp(INF - ans) != 0)printf("%.2f\n", ans);
        else puts("Can not be reached!");

    }
    return 0;
}
