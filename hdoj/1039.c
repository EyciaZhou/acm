#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char l[256];
    int i;
    bool v['a' + 26] = {false};
    v['a'] = true;
    v['e'] = true;
    v['i'] = true;
    v['o'] = true;
    v['u'] = true;
    while (1) {
        scanf("%s", &l);
        bool f = false;
        int le = strlen(l);
        if (strcmp(l, "end") == 0) {
            break;
        }
        int tot = 0;
        for (i = 0; i < le; i++) {
            if (v[l[i]]) {
                tot++;
            }    
        }
        if (tot < 1) {
            printf("<%s> is not acceptable.\n", l);
            continue;
        }
        for (i = 0; i < (le - 1); i++) {
            if (l[i] == l[i+1] && l[i] != 'e' && l[i] != 'o') {
                printf("<%s> is not acceptable.\n", l);
                f = true;
            }
        }
        if (f) {
            continue;
        }
        for (i = 0; i < (le - 2); i++) {
            if ((v[l[i]] && v[l[i+1]] && v[l[i+2]]) || (!v[l[i]] && !v[l[i+1]] && !v[l[i+2]])) {
                printf("<%s> is not acceptable.\n", l);
                f = true;
            }
        }
        if (f) {
            continue;
        }
        printf("<%s> is acceptable.\n", l);
    }
}