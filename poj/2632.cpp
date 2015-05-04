#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int didfx(char fx)
{
    if (fx == 'N') {
        return 0;
    }
    if (fx == 'E') {
        return 1;
    }
    if (fx == 'W') {
        return 3;
    }
    if (fx == 'S') {
        return 2;
    }
    return -1;
}

int sx[4] = { 0, 1, 0, -1 };
int sy[4] = { 1, 0, -1, 0 };

int main()
{
    int t, w, h, n, m;
    int x, y;
    char fx;
    cin >> t;
    while (t--) {
        cin >> w >> h;
        int map[105][105];
        memset(map, 0, sizeof(map));
        cin >> n >> m;
        int robotx[101], roboty[101];
        int robotfx[101];
        for (int i = 1; i <= n; i++) {
            cin >> x >> y >> fx;
            map[x][y] = i;
            robotx[i] = x;
            roboty[i] = y;
            robotfx[i] = didfx(fx);
        }
        bool finded = false;
        for (int i = 1; i <= m; i++) {
            cin >> x >> fx >> y;
            if (!finded) {
                int xx = robotx[x];
                int yy = roboty[x];
                if (fx == 'F') {
                    for (int j = 1; j <= y; j++) {
                        xx += sx[robotfx[x]];
                        yy += sy[robotfx[x]];

                        if (xx <= 0 || yy <= 0 || xx > w || yy > h) {
                            finded = true;
                            printf("Robot %d crashes into the wall\n", x);
                        }
                        if (finded) {
                            break;
                        }
                        if (map[xx][yy] != 0) {
                            finded = true;
                            printf("Robot %d crashes into robot %d\n", x, map[xx][yy]);
                        }

                        if (finded) {
                            break;
                        }
                    }
                    map[robotx[x]][roboty[x]] = 0;
                    map[xx][yy] = x;
                    robotx[x] = xx;
                    roboty[x] = yy;
                }
                if (fx == 'L') {
                    robotfx[x] -= y;
                    robotfx[x] += y * 4;
                    robotfx[x] = robotfx[x] % 4;
                }
                if (fx == 'R') {
                    robotfx[x] += y;
                    robotfx[x] = robotfx[x] % 4;
                }
            }
        }
        if (!finded) {
            printf("OK\n");
        }
    }
}