/*
 start : 2014-12-21 10:46:01 Sunday
 start : 2014-12-21 17:00:19 Sunday
 */

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

bool mp[205][205];
vector<pair<int, int> > ps;
vector<pair<pair<int, int>, pair<int, int> > > rs;

int n;

bool inside(int x, int y, int xx1, int yy1, int xx2, int yy2) {
    if (x <= xx2 && x >= xx1 && y <= yy2 && y >= yy1) {
        return true;
    }
    return false;
}

int solve(int pp1, int pp2) {
    pair<pair<int, int>, pair<int, int> > r1 = rs[pp1];
    pair<pair<int, int>, pair<int, int> > r2 = rs[pp2];
    
    pair<pair<int, int>, pair<int, int> > te;
    
    if (r1.first.first > r2.first.first && r1.first.second > r2.first.second &&
        r1.second.first < r2.second.first && r1.second.second < r2.second.second) {
        return (r2.second.first - r2.first.first) * (r2.second.second - r2.first.second);
    }
    if (r2.first.first > r1.first.first && r2.first.second > r1.first.second &&
        r2.second.first < r1.second.first && r2.second.second < r1.second.second) {
        return (r1.second.first - r1.first.first) * (r1.second.second - r1.first.second);
    }
    if (inside(r1.first.first, r1.first.second, r2.first.first, r2.first.second, r2.second.first, r2.second.second)) {
        return 0;
    }
    if (inside(r1.second.first, r1.first.second, r2.first.first, r2.first.second, r2.second.first, r2.second.second)) {
        return 0;
    }
    if (inside(r1.first.first, r1.second.second, r2.first.first, r2.first.second, r2.second.first, r2.second.second)) {
        return 0;
    }
    if (inside(r1.second.first, r1.second.second, r2.first.first, r2.first.second, r2.second.first, r2.second.second)) {
        return 0;
    }
    
    te = r1;
    r1 = r2;
    r2 = te;
    
    if (inside(r1.first.first, r1.first.second, r2.first.first, r2.first.second, r2.second.first, r2.second.second)) {
        return 0;
    }
    if (inside(r1.second.first, r1.first.second, r2.first.first, r2.first.second, r2.second.first, r2.second.second)) {
        return 0;
    }
    if (inside(r1.first.first, r1.second.second, r2.first.first, r2.first.second, r2.second.first, r2.second.second)) {
        return 0;
    }
    if (inside(r1.second.first, r1.second.second, r2.first.first, r2.first.second, r2.second.first, r2.second.second)) {
        return 0;
    }
    return (r2.second.first - r2.first.first) * (r2.second.second - r2.first.second) +
    (r1.second.first - r1.first.first) * (r1.second.second - r1.first.second);
}
int main() {
    int n, xx, yy;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        ps.clear();
        rs.clear();
        memset(mp, false, sizeof(mp));
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &xx, &yy);
            mp[xx][yy] = true;
            ps.push_back(make_pair(xx, yy));
        }
        
        for (int i = 0; i < ps.size() - 1; i++) {
            for (int j = i + 1; j < ps.size(); j++) {
                int minx = min(ps[i].first, ps[j].first);
                int maxx = max(ps[i].first, ps[j].first);
                int miny = min(ps[i].second, ps[j].second);
                int maxy = max(ps[i].second, ps[j].second);
                
                if (minx == maxx) continue;
                if (miny == maxy) continue;
                
                if (mp[minx][miny] && mp[minx][maxy] &&
                    mp[maxx][miny] && mp[maxx][maxy]) {
                    rs.push_back(make_pair(make_pair(minx, miny),
                                           make_pair(maxx, maxy)));
                }
            }
        }
        int rssz = rs.size();
        int ma = 0;
        for (int i = 0; i < rssz - 1; i++) {
            for (int j = i + 1; j < rssz; j++) {
                int res = solve(i, j);
                if (res > ma) {
                    ma = res;
                }
            }
        }
        if (ma == 0) {
            printf("imp\n");
        } else {
            printf("%d\n", ma);
        }
    }
}