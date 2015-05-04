#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

long m, n;
long p, l, x, u, cost;
long level[105];
long map[105][105];

int main() {
    cin >> m >> n;
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            if (i == j) {
                map[i][j] = 0;
            } else {
                map[i][j] = 100000000;
            }
        }
    }
    for (int i = 1; i <=n; i++){
        cin >> p >> l >> x;
        level[i] = l;
        map[0][i] = p;
        for (int j = 0; j < x; j++) {
            cin >> u;
            cin >> cost;
            map[u][i] = cost;
        }
    }
    level[0] = level[1];
    long min = 100000000;
    for (int ll = level[1] - m; ll <= level[1]; ll++) {
        queue<int> *que = new queue<int>();
        bool v[105];
        memset(v, sizeof(v), false);
        v[0] = true;
        long dis[105];
        for (int i = 0; i < 105; i++) {
            dis[i] = 100000000;
        }
        dis[0] = 0;
        que->push(0);
        long start = ll;
        long end = ll + m;
        while (!que->empty()) {
            long k = que->front();
            que->pop();
            v[k] = false;
            for (int i = 0; i <= n; i++) {
                if (level[i] <= end && level[i] >= start && map[k][i] > 0) {
                    if (dis[k] + map[k][i] < dis[i]) {
                        dis[i] = dis[k] + map[k][i];
                        if (!v[i]) {
                            v[i] = true;
                            que->push(i);
                        }
                    }
                }
            }
        }
        if (min > dis[1]) {
            min = dis[1];
        }
    }
    cout << min << endl;
}
