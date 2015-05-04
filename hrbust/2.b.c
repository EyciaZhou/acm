#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2005;
int n, r;
int a[N], b[N];
struct node {
    int vol, num;
    node(int x, int y): vol(x), num(y) {}
};
vector<node>v;

bool Ac(int M) { 
    int x, y; 
    if (r & 1) x = 0, y = M;
    else x = M, y = 0;
    memcpy(b, a, sizeof (a));
    v.clear();
  
    if (r & 1) {
        for (int i = 0; i < n && y; ++i) {
            if (b[i] & 1) {
                b[i] -= 3, y -= 1, x += 1;
            }
        }
        for (int i = 0; i < n && y >= 2; ++i) {
            while (b[i] >= 6 && y >= 2) {
                b[i] -= 6, y -= 2, x += 2;
            }
        }
        if (x) v.push_back(node(r-3, x));
        if (y) v.push_back(node(r, y));
    } else {
        v.push_back(node(r, x));
    }
    int p3 = 0, p2 = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] & 1) {
            b[i] -= 3, p3 += 1;
        }
        p2 += b[i] / 2;
    }
    for (int i = 0; i < v.size() && p3 >= 2; ++i) {
        if (v[i].vol >= 6) {
            int t1 = v[i].vol / 6;
            int t2 = min(v[i].num, p3/(2*t1)); 
            if (t2 > 0) {
                p3 -= t2*t1*2;
                v[i].num -= t2;
                v.push_back(node(v[i].vol-6*t1, t2));
            }
            if (v[i].num > 0 && p3 >= 2) {
                t2 = min(t1, p3/2);
                if (t2 > 0) {
                    p3 -= t2*2;
                    v[i].num -= 1;
                    v.push_back(node(v[i].vol-6*t2, 1));
                }
            }
        }
    }
    for (int i = 0; i < v.size() && p3 > 0; ++i) {
        if(v[i].vol >=3 && v[i].num > 0) {
            int tmp = min(v[i].num, p3);
            p3 -= tmp;
            v[i].num -= tmp;
            v.push_back(node(v[i].vol-3, tmp));
        }
    }
    if (p3 <= 0) {
        for (int i = 0; i < (int)v.size() && p2 > 0; ++i) {
            p2 -= (v[i].vol/2)*v[i].num;
        }
    }
    return p3 <= 0 && p2 <= 0;
}

int main() {
    while (scanf("%d %d", &n, &r) != EOF) {
        int ret;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int l = 1, r = n * 2000;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (Ac(mid)) {
                ret = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}