/*
 start : 2014-12-17 21:15:13 Wednesday
 aced : 2014-12-17 22:03:03 Wednesday
 */

#include <cstdio>
#include <vector>
#include <cstring>

char S[10];

long long ten[20];

int main() {
    long long A;
    long long a, b, s;
    bool hz;
    
    ten[0] = 1;
    for (int i = 1; i < 20; i++) {
        ten[i] = ten[i-1] * 10;
    }
    
    while (scanf("%I64d %s", &A, S) != EOF) {
        b = strlen(S);
        s = 0;
        hz = (S[0] == '0');
        for (int i = 0; i < strlen(S); i++) {
            s = s * 10 + S[i] - '0';
        }
        bool flag = false;
        long long ma = -1;
        for (a = 0; a <= 5; a++) {
            if (flag) {
                break;
            }
            long long c2 = 0;
            if (hz) {
                c2 = 1;
            }
            for (; c2 <= A; c2++) {
                if (flag) {
                    break;
                }
                long long te = (c2 * ten[a+b] + s * ten[a]) % A;
                if (te == 0) {
                    if (ma < 0 || ma > (c2 * ten[a+b] + s * ten[a]) / A && (c2 * ten[a+b] + s * ten[a]) / A > 0) {
                        ma = (c2 * ten[a+b] + s * ten[a]) / A;
                    }
                } else if (A - te < ten[a]) {
                    if (ma < 0 || ma > (c2 * ten[a+b] + s * ten[a] + A - te) / A && (c2 * ten[a+b] + s * ten[a] + A - te) / A > 0) {
                        ma = (c2 * ten[a+b] + s * ten[a] + A - te) / A;
                    }
                }
            }
        }
        printf("%I64d\n", ma);
    }
}