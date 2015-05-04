/*
 start : 2014-12-16 19:43:57 Tuesday
 aced : 2014-12-16 21:22:23 Tuesday
 */

#include <cstdio>

int ca[4];

bool dfs() {
    int zero = 0, zero2 = 0;
    for (int i = 0; i < 4; i++) {
        if (!ca[i]) {
            zero++;
        }
        if (ca[i] == 0 || ca[i] >= 3) {
            zero2++;
        }
    }
    if (zero2 == 4) {
        return true;
    }
    if (!ca[1]) {
        return false;
    }
    
    if (!ca[2]) {
        return false;
    }
    
    if (zero > 1) {
        return false;
    }
    int mi = -1;
    int p = -1;
    for (int i = 0; i < 4; i++) {
        if (ca[i] > 0 && (ca[i] < mi || mi == -1)) {
            p = i;
            mi = ca[i];
        }
    }
    if (p == 0) {
        if (ca[0] && ca[1] && ca[2]) {
            ca[0]--;
            ca[1]--;
            ca[2]--;
            if (dfs()) {
                return true;
            }
            if (ca[3]) {
                ca[3]--;
                if (dfs()) {
                    return true;
                }
                ca[3]++;
            }
            ca[0]++;
            ca[1]++;
            ca[2]++;
            
        }
    }
    if (p == 1 || p == 2) {
        if (ca[1] && ca[2]) {
            if (ca[0]) {
                ca[0]--;
                ca[1]--;
                ca[2]--;
                if (dfs()) {
                    return true;
                }
                if (ca[3]) {
                    ca[3]--;
                    if (dfs()) {
                        return true;
                    }
                    ca[3]++;
                }
                ca[0]++;
                ca[1]++;
                ca[2]++;
            }
            if (ca[3]) {
                ca[1]--;
                ca[2]--;
                ca[3]--;
                if (dfs()) {
                    return true;
                }
                ca[1]++;
                ca[2]++;
                ca[3]++;
            }
        }
    }
    if (p == 3) {
        if (ca[3] && ca[1] && ca[2]) {
            ca[3]--;
            ca[1]--;
            ca[2]--;
            if (dfs()) {
                return true;
            }
            if (ca[0]) {
                ca[0]--;
                if (dfs()) {
                    return true;
                }
                ca[0]++;
            }
            ca[3]++;
            ca[1]++;
            ca[2]++;
            
        }
    }
    return false;
}

int main() {
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        for (int i = 0; i < 4; i++) {
            scanf("%d", &ca[i]);
        }
        if (ca[0] >= 3 && ca[1] >= 3 && ca[2] >= 3 && ca[3] >= 3) {
            printf("Yes\n");
            continue;
        }
        printf(dfs() ? "Yes\n" : "No\n");
    }
}