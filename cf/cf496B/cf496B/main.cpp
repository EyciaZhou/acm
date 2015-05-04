/*
 start : 2014-12-18 00:42:24 Thursday
 aced : 2014-12-18 01:10:34 Thursday
 */

#include <cstdio>

char mm[1005];
int m[1005], temp[1005], min[1005];
int n;

bool less() {
    for (int i = 0; i < n; i++) {
        if (temp[i] > min[i]) {
            return false;
        } else if (temp[i] < min[i]) {
            return true;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    scanf("%s", mm);
    for (int i = 0; i < n; i++) {
        m[i] = mm[i] - '0';
    }
    for (int i = 0; i < n; i++) {
        min[i] = 9;
    }
    for (int j = 0; j <= 9; j++) {
        for (int i = 0; i < n; i++) {
            int p = 0;
            for (int k = i; k < n; k++) {
                temp[p++] = m[k];
            }
            for (int k = 0; k < i; k++) {
                temp[p++] = m[k];
            }
            if (less()) {
                for (int i = 0; i < n; i++) {
                    min[i] = temp[i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            m[i] = (m[i] + 1) % 10;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", min[i]);
    }
}