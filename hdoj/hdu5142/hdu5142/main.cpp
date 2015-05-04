/*
 start : 2014-12-16 18:58:42 Tuesday
 aced : 2014-12-16 19:42:43 Tuesday
 */

#include <cstdio>

int main() {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        int n, t = 0;
        scanf("%d", &n);
        while (n > 0) {
            t = t * 2 + n % 2;
            n /= 2;
        }
        printf("%d\n", t);
    }
}