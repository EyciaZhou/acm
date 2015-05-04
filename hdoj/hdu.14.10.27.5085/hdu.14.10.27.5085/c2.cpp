#include <iostream>
#include <functional>
#include <map>
using namespace std;

map<int, int> pre[16];

int pow[10][16];

int k, s;

inline int boom(int n, int k) {
    int result = 0;
    while (n > 0) {
        result += pow[n%10][k];
        n/=10;
    }
    return result;
}

int get(int n) {
    int result = 0;
    for (int i = 0; i < n / 100000; i++) {
        int r = boom(i, k);
        if (pre[k].find(s-r) != pre[k].end()) {
            result = result + pre[k][s-r];
        }
    }
    for (int i = n / 100000 * 100000; i <= n; i++) {
        int r = boom(i, k);
        if (r == s) {
            result ++;
        }
    }
    return result;
}

void pr() {
    for (int i = 0; i < 10; i++) {
        pow[i][0] = 1;
    }
    for (int k = 1; k <= 15; k++) {
        for (int i = 0; i < 10; i++) {
            pow[i][k] = pow[i][k-1] * i;
        }
    }
    for (int k = 1; k <= 15; k++) {
        for (int i = 0; i < 100000; i++) {
            int re = boom(i, k);
            if (pre[k].find(re) != pre[k].end()) {
                pre[k][re] = pre[k][re] + 1;
            } else {
                pre[k].insert(make_pair(re, 1));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    pr();
    int a, b;
    while (scanf("%d %d %d %d", &a, &b, &k, &s) != EOF) {
        printf("%d\n", get(b) - get(a-1));
    }
}
