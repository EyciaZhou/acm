#include <stdio.h>
#define MAX 0x7fffffffffffffff

int main()
{
    int n, i;
    const char *s = "xT.T^__^";
    long long m, a[128];

    for (a[0] = 7, a[1] = 10, n = 2; a[n - 1] > 0; n++)
        a[n] = a[n - 1] + a[n - 2];
    n--;
    while (scanf("%lld", &m) != EOF) {
        while (m > 7) {
            for (i = 0; i < n && m > a[i]; i++);
            m -= a[i - 1];
        }
        printf("%c\n", s[m]);
    }
    return 0;
}