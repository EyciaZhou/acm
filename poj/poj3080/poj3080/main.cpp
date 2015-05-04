//
//  main.cpp
//  poj3080
//
//  Created by eycia on 14/12/5.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct tnode {
    int n[4];
    int ti;
    
    //ac auto
    int v;
    int fa;
    int f;
    int de;
};

tnode trie[4000];

int re[256];
char rre[4];

char s[100];

void dof() {
    queue<int > qu;
    for (int i = 0; i < 4; i++) {
        if (trie[0].n[i] != -1) {
            qu.push(trie[0].n[i]);
        }
    }
    while (!qu.empty()) {
        int p = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++) {
            if (trie[p].n[i] != -1) {
                qu.push(trie[p].n[i]);
            }
        }
        int k = trie[p].fa;
        k = trie[k].f;
        while (trie[ k ].n[ trie[p].v ] != -1) {
            k = trie[k].f;
            if (k == -1) {
                break;
            }
        }
        if (k == -1) {
            trie[p].f = 0;
        } else {
            trie[p].f = trie[ k ].n[ trie[p].v ];
        }
    }
}

int next(int n, int ne, int k) {
    int k2 = n;
    while (trie[k2].n[ne] == -1) {
        k2 = trie[k2].f;
        if (k2 == -1) {
            break;
        }
    }
    if (k2 == -1) {
        return 0;
    } else {
        k2 = trie[k2].n[ne];
        int k3 = k2;
        while (k2 != -1) {
            trie[k2].ti |= k;
            k2 = trie[k2].f;
        }
        return k3;
    }
}

int ma;
int p;
int n;

void gen_ans(int now) {
    if (trie[now].ti == (1 << (n - 1)) - 1 && trie[now].de > ma) {
        ma = trie[now].de;
        p = now;
    }
    for (int i = 0; i < 4; i++) {
        if (trie[now].n[i] != -1) {
            gen_ans(trie[now].n[i]);
        }
    }
}

int main(int argc, const char * argv[]) {
    int ff;
    re['A'] = 0;
    re['T'] = 1;
    re['G'] = 2;
    re['C'] = 3;
    rre[0] = 'A';
    rre[1] = 'T';
    rre[2] = 'G';
    rre[3] = 'C';
    scanf("%d", &ff);
    while (ff--) {
        int mem = 0;
        memset(trie[0].n, -1, sizeof(trie[0].n));
        trie[0].ti = 0;
        trie[0].f = -1;
        trie[0].fa = -1;
        trie[0].de = 0;
        scanf("%d", &n);
        scanf("%s", s);
        for (int i = 0; i < strlen(s); i++) {
            int k = 0;
            int dep = 0;
            for (int j = i; j < strlen(s); j++) {
                dep++;
                if (trie[k].n[re[s[j]]] == -1) {
                    trie[k].n[re[s[j]]] = ++mem;
                    memset(trie[mem].n, -1, sizeof(trie[mem].n));
                    trie[mem].ti = 0;
                    trie[mem].v = re[s[j]];
                    trie[mem].fa = k;
                    trie[mem].de = dep;
                }
                k = trie[k].n[re[s[j]]];
            }
        }
        dof();
        for (int i = 0; i < n - 1; i++) {
            int k = (1 << i);
            scanf("%s", s);
            for (int j = 0; j < strlen(s); j++) {
                int f = 0;
                for (int p = j; p < strlen(s); p++) {
                    f = next(f, re[s[p]], k);
                }
            }
        }
        ma = -1;
        p = -1;
        gen_ans(0);
        if (ma < 3) {
            printf("no significant commonalities\n");
        } else {
            int k = 0;
            while (p != 0) {
                s[ma - k - 1] = rre[trie[p].v];
                p = trie[p].fa;
                k++;
            }
            s[ma] = '\0';
            printf("%s\n", s);
        }
    }
}
