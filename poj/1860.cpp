#include <iostream>
using namespace std;

int main() {
    int n, m;
    int start;
    double start_m;
    int u, v;
    double p, pm;
    cin >> n >> m;
    cin >> start >> start_m;
    int mapu[205], mapv[205];
    double map[205], mapm[205];
    double dis[105];
    for (int i = 0; i < 105; i++) {
        dis[i] = 0;
    }
    dis[start] = start_m;
    int maplen = -1;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        cin >> p >> pm;
        maplen++;
        mapu[maplen] = u;
        mapv[maplen] = v;
        map[maplen] = p;
        mapm[maplen] = pm;
        cin >> p >> pm;
        maplen++;
        mapu[maplen] = v;
        mapv[maplen] = u;
        map[maplen] = p;
        mapm[maplen] = pm;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= maplen; j++) {
            if (mapm[j] < dis[mapu[j]]) {
                if ((dis[mapu[j]] - mapm[j]) * map[j] > dis[mapv[j]]) {
                    dis[mapv[j]] = (dis[mapu[j]] - mapm[j]) * map[j];
                }
            }
        }
    }
    for (int j = 0; j <= maplen; j++) {
        if ((dis[mapu[j]] - mapm[j]) * map[j] > dis[mapv[j]]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
}