/*
 start : 2014-12-18 00:30:50 Thursday
 aced : 2014-12-18 00:42:18 Thursday
 */

#include <cstdio>

int a[105];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ma = 0x7fffffff;
    for (int i = 0; i <= n - 3; i++) {
        if (a[i+2] - a[i] < ma) {
            ma = a[i+2] - a[i];
        }
    }
    for (int i = 0; i <= n - 2; i++) {
        if (a[i+1] - a[i] > ma) {
            ma = a[i+1] - a[i];
        }
    }
    printf("%d\n", ma);
}