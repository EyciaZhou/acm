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
#include <iostream>
using namespace std;

char s[1000005];

typedef struct node {
    int n[26];
    int f; //fall
    int d; //date
    int fa; //fa
    int b; //iis
} NODE;

int n;

NODE trie[600000];


int list[600000];

void dof() {
    int i, j;
    int h = -1, t = 0;
    for (i = 0; i <= n; i++) {
        if (trie[0].n[i] >= 0) {
            trie[trie[0].n[i]].f = 0;
            for (j = 0; j <= n; j++) {
                if (trie[trie[0].n[i]].n[j] >= 0) {
                    h = (h + 1) % 600000;
                    list[h] = trie[trie[0].n[i]].n[j];
                }
            }
        }
    }
    while ((h + 1) % 600000 != t) {
        
        int p = list[t];
        //cout << p << endl;
        t = (t + 1) % 600000;
        for (i = 0; i <= n; i++) {
            if (trie[p].n[i] >= 0) {
                h = (h + 1) % 600000;
                list[h] = trie[p].n[i];
            }
        }
        int n = trie[p].d;
        int q = trie[trie[p].fa].f;
        while (true) {
            if (trie[q].n[n] >= 0) {
                trie[p].f = trie[q].n[n];
                //if (trie[trie[q].n[n]].b > 0) {
                    //trie[p].b += trie[trie[q].n[n]].b;
                //trie[trie[q].n[n]].b += trie[p].b;
                //}
                break;
            }else{
                if (q == 0) {
                    trie[p].f = 0;
                    break;
                }
            }
            q = trie[q].f;
        }
    }
}

int getnext(int f, int n) {
    while (true) {
        if (trie[f].n[n] >= 0) {
            return trie[f].n[n];
        }
        if (f == 0) {
            return 0;
        }
        f = trie[f].f;
    }
}

void flf(int f, int k) {
    while (true) {
        if (f == 0) {
            return ;
        }
        trie[f].b -= k;
        //cout << trie[f].b << endl;
        f = trie[f].f;
    }
}

void up(int f) {
    cout << "aa" << f << endl;
    int k = 0;
    while (true) {
        if (f == 0) {
            return ;
        }
        k += trie[f].b;
        trie[f].b = k;
        //cout << trie[f].b << endl;
        f = trie[f].f;
    }
}

char key[100];

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    n = 25;
    while (ff--) {
        int mem = 0;
        memset(trie[0].n, -1, sizeof(trie[0].n));
        trie[0].f = -1;
        trie[0].fa = -1;
        trie[0].d = -1;
        trie[0].b = false;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", key);
            int sl = strlen(key);
            int now = 0;
            for (int j = 0; j < sl; j++) {
                if (trie[now].n[key[j]-'a'] < 0) {
                    mem++;
                    memset(trie[mem].n, -1, sizeof(trie[mem].n));
                    
                    trie[mem].f = -1;
                    trie[mem].fa = now;
                    trie[mem].d = key[j] - 'a';
                    trie[mem].b = 0;
                    
                    trie[now].n[key[j]-'a'] = mem;
                }
                now = trie[now].n[key[j]-'a'];
            }
            trie[now].b++;
        }
        dof();
        for (int i = 1; i <= mem; i++) {
            if (trie[i].n[trie[i].d] < 0) {
                up(i);
            }
        }
        
        scanf("%s", s);
        int sl = strlen(s);
        int now = 0, ans = 0, re = 0;
        for (int i = 0; i < sl; i++) {
            re = getnext(now, s[i] - 'a');
            ans += trie[re].b;
            //trie[re].b = 0;
            if (trie[re].b > 0) {
                //flf(re, trie[re].b);
                cout << endl;
            }
            now = re;
        }
        printf("%d\n", ans);
    }
}
/*
 
 2
 2
 sher
 he
 she
 2
 sher
 he
 sher
 
 1
 6
 she
 he
 he
 say
 shr
 her
 yasherhe
 
 1
 6
 she
 he
 he
 say
 shr
 her
 yasherhs

 
 10
 2
 abcdef
 bcd
 abcdef
 1
 h
 hhhhh
 5
 bhea
 her
 he
 h
 ha
 bhera
 5
 bhea
 her
 he
 h
 ha
 bhera
 */