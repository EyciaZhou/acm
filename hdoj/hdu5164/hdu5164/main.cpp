//
//  main.cpp
//  hdu5164
//
//  Created by eycia on 14/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
#include <queue>
using namespace std;

#define root 1
double als[100005];

struct tnode {
    map<double, int> n;
    //int n[4];
    int ti;
    
    //ac auto
    int is;
    double v;
    //int fa;
    int f;
    //int de;
};

#define mdi map<double, int>

tnode trie[1000005];

void dof() {
    queue<int > qu;
    for (map<double, int>::iterator it = trie[1].n.begin(); it != trie[1].n.end(); it++) {
        //cout << "it->second" << it->second << " " << it->first << endl;
        if (it->second != 0) {
            //cout << it->second << "  aa  " << endl;
            qu.push(it->second);
        }
    }/*
    for (int i = 0; i < 4; i++) {
        if (trie[0].n[i] != -1) {
            qu.push(trie[0].n[i]);
        }
    }*/
    while (!qu.empty()) {
        int p = qu.front();
        qu.pop();
        //cout << p << endl;
        for (map<double, int>::iterator it = trie[p].n.begin(); it != trie[p].n.end(); it++) {
            
            qu.push(it->second);
        }/*
        for (int i = 0; i < 4; i++) {
            if (trie[p].n[i] != -1) {
                qu.push(trie[p].n[i]);
            }
        }*/
        int k = trie[p].fa;
        k = trie[k].f;
        //cout << k << endl;
        while (trie[ k ].n[ trie[p].v ] != 0) {
            k = trie[k].f;
            if (k == 0) {
                break;
            }
        }
        if (k == 0) {
            trie[p].f = root;
        } else {
            trie[p].f = trie[ k ].n[ trie[p].v ];
        }
    }
}

int next(int n, double ne/*, int k*/) {
    //cout << n << " " << ne << endl;
    int k2 = n;
    while (trie[k2].n[ne] == 0) {
        //cout << k2 << endl;
        k2 = trie[k2].f;
        if (k2 == 0) {
            break;
        }
    }
    if (k2 == 0) {
        return root;
    } else {
        k2 = trie[k2].n[ne];
        int k3 = k2;
        while (k2 != 0) {
            trie[k2].ti++;
            k2 = trie[k2].f;
        }
        return k3;
    }
}

int main(int argc, const char * argv[]) {
    int ff, n, m;
    double lst, tmp;
    scanf("%d", &ff);
    while (ff--) {
        int mem = 1;
        scanf("%d %d", &n, &m);
        scanf("%lf", &lst);
        for (int i = 0; i < n-1; i++) {
            scanf("%lf", &tmp);
            als[i] = tmp / lst;
            lst = tmp;
        }
        trie[root].f = 0;
        trie[root].fa = 0;
        trie[root].n.clear();
        trie[root].is = 0;
        for (int i = 0; i < m; i++) {
            int k;
            scanf("%d", &k);
            scanf("%lf", &lst);
            int now = root;
            for (int j = 0; j < k-1; j++) {
                scanf("%lf", &tmp);
                double ll = tmp / lst;
                //cout << trie[now].n[ll] << endl;
                if (trie[now].n[ll] == 0) {
                    //tr[now][ll] = mem++;
                    trie[now].n[ll] = ++mem;
                    //cout << mem << endl;
                    trie[mem].n.clear();
                    //memset(trie[mem].n, -1, sizeof(trie[mem].n));
                    //trie[mem].ti = 0;
                    trie[mem].v = ll;
                    trie[mem].fa = now;
                    trie[mem].ti = 0;
                    trie[mem].is = 0;
                }
                now = trie[now].n[ll];
            }
            trie[now].is++;
        }
        //cout << "aa" << endl;
        dof();
        //cout << "bb" << endl;
        int now = root;
        for (int i = 0; i < n-1; i++) {
            now = next(now, als[i]);
            //cout << als[i] << " " << now << " " << trie[now].is << " " << trie[now].ti << endl;
        }
        int tot = 0;
        for (int i = 1; i <= mem; i++) {
            tot += trie[i].is * trie[i].ti;
        }
        cout << tot << endl;
        //cout << endl;
    }
}
