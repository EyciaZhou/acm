#include <iostream>
using namespace std;

int main() {
    int F;
    cin >> F;
    while (F--) {
        int n, m, w;
        int u, v, cost;
        int b[10000], bu[10000], bv[10000], bl = -1;
        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++) {
            bl++;
            bu[bl] = 0;
            bv[bl] = i;
            b[bl] = 0;
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> cost;
            bl++;
            bu[bl] = u;
            bv[bl] = v;
            b[bl] = cost;
            bl++;
            bu[bl] = v;
            bv[bl] = u;
            b[bl] = cost;
        }
        for (int i = 0; i < w; i++) {
            cin >> u >> v >> cost;
            bl++;
            bu[bl] = u;
            bv[bl] = v;
            b[bl] = -cost;
        }
        long dis[2505];
        dis[0] = 0;
        for (int i = 1; i <= n; i++) {
            dis[i] = 1000000000;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= bl; j++) {
                if (dis[bu[j]] + b[j] < dis[bv[j]]) {
                    dis[bv[j]] = dis[bu[j]] + b[j];
                }
            }
        }
        bool flag = false;
        for (int j = 0; j <= bl; j++) {
            if (dis[bu[j]] + b[j] < dis[bv[j]]) {
                flag = true;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}