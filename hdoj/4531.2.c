#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 9! = 362880
const int LIM = 362880;
int fac[9]; // 递增进制数的权值 
int tot[4]; // 四种颜色的个数 
char vis[LIM]; // hash九宫格 
char op[6]; // 滚动的操作的限制 
char hav[50]; // 4*9个格子的标记 

struct Block {
    char color[6];
    int id;
}bk[3][3];

struct Node {
    Block *ptr[3][3];
    int key;
    int ti;
    Node() {}
    Node(Block (*x)[3]) {
        ti = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ptr[i][j] = &x[i][j]; 
            }
        }
        getkey();
    }
    void show() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                printf("%5d", ptr[i][j]->id);
            }
            puts("");
        }
        puts("");
    }
    void getkey() {
        int cnt;
        key = 0;
        for (int i = 0; i < 8; ++i) {
            cnt = 0;
            for (int j = i+1; j < 9; ++j) {
                if (ptr[j/3][j%3]->id < ptr[i/3][i%3]->id) ++cnt;
            }
            key += cnt * fac[8-i];
        }
    }
    int dfs(int x, int y, int z) {
        if (hav[(x*3+y)*4+z]) return 0;
        hav[(x*3+y)*4+z] = 1;
        char ch = ptr[x][y]->color[z];
        int ret = 1;
        if (z == 0) {
            if (ptr[x][y]->color[2] == ch) ret += dfs(x, y, 2);
            if (ptr[x][y]->color[3] == ch) ret += dfs(x, y, 3);
            if (x > 0 && ptr[x-1][y]->color[1] == ch) ret += dfs(x-1, y, 1);
        } else if (z == 1) {
            if (ptr[x][y]->color[2] == ch) ret += dfs(x, y, 2);
            if (ptr[x][y]->color[3] == ch) ret += dfs(x, y, 3);
            if (x < 2 && ptr[x+1][y]->color[0] == ch) ret += dfs(x+1, y, 0);
        } else if (z == 2) {
            if (ptr[x][y]->color[0] == ch) ret += dfs(x, y, 0);
            if (ptr[x][y]->color[1] == ch) ret += dfs(x, y, 1);
            if (y > 0 && ptr[x][y-1]->color[3] == ch) ret += dfs(x, y-1, 3);
        } else {
            if (ptr[x][y]->color[0] == ch) ret += dfs(x, y, 0);
            if (ptr[x][y]->color[1] == ch) ret += dfs(x, y, 1);
            if (y < 2 && ptr[x][y+1]->color[2] == ch) ret += dfs(x, y+1, 2);
        }
        return ret;
    }
    bool judge() {
        memset(hav, 0, sizeof (hav));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (!hav[(i*3+j)*4+k]) {
                        int cnt = dfs(i, j, k);
                        switch(ptr[i][j]->color[k]) {
                            case 'R': if (cnt != tot[0]) return false; break;
                            case 'G': if (cnt != tot[1]) return false; break;
                            case 'B': if (cnt != tot[2]) return false; break;
                            default : if (cnt != tot[3]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

void pre() {
    fac[1] = 1;
    for (int i = 2; i < 9; ++i) {
        fac[i] = fac[i-1] * i;
    }
}

void swapr(Block *x[], Block *y[], int dir) { // 横向的滚动
    if (dir == 0) { // 向左
        y[0] = x[1], y[1] = x[2], y[2] = x[0];
    } else { // 向右
        y[0] = x[2], y[1] = x[0], y[2] = x[1];
    }
}

void swapc(Block *x[], Block *y[], int dir) { // 纵向的滚动
    if (dir == 0) { // 向上 
        y[0] = x[3], y[3] = x[6], y[6] = x[0];
    } else { // 向下 
        y[0] = x[6], y[3] = x[0], y[6] = x[3];
    }
}

int bfs() {
    queue<Node>q;
    Node tmp = Node(bk);
    Node pos;
    memset(vis, 0, sizeof (vis));
    q.push(tmp); // 初始化是没有逆序对的
    vis[tmp.key] = 1;
    while (!q.empty()) {
        pos = q.front();
        q.pop();
        if (pos.judge()) {
            return pos.ti;
        }
        for (int i = 0; i < 6; ++i) {
            if (op[i]) continue;
            tmp = pos;
            if (i < 3) { // 横向的滚动 
                for (int j = 0; j < 2; ++j) {
                    swapr(&pos.ptr[i][0], &tmp.ptr[i][0], j);
                    tmp.getkey();
                    tmp.ti = pos.ti + 1;
                    if (!vis[tmp.key]) {
                        vis[tmp.key] = 1;
                        q.push(tmp);
                    }
                }
            } else { // 纵向的 
                for (int j = 0; j < 2; ++j) {
                    swapc(&pos.ptr[0][i%3], &tmp.ptr[0][i%3], j);
                    tmp.getkey();
                    tmp.ti = pos.ti + 1;
                    if (!vis[tmp.key]) {
                        vis[tmp.key] = 1;
                        q.push(tmp);
                    }
                }
            }
        }
    }
}

int main() {
    int T, ca = 0;
    pre();
    scanf("%d", &T);
    while (T--) {
        memset(op, 0, sizeof (op));
        memset(tot, 0, sizeof (tot));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                scanf("%s", bk[i][j].color);
                for (int k = 0; k < 4; ++k) {
                    switch(bk[i][j].color[k]) {
                        case 'R': ++tot[0]; break;
                        case 'G': ++tot[1]; break;
                        case 'B': ++tot[2]; break;
                        default : ++tot[3];
                    }
                }
                bk[i][j].id = i*3+j; // 0-8
                if (bk[i][j].color[4] == '1') {
                    op[i] = op[3+j] = 1; // 两种操作无法进行
                }
            }
        }
        printf("Case #%d: %d\n", ++ca, bfs());
    }
    return 0;
}