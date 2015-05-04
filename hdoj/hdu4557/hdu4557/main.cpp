//
//  main.cpp
//  hdu4557
//
//  Created by eycia on 14/11/29.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>

struct node {
    int l, r;
    int p;
    int v;
    int cp;
    //int ln;
};

char names[1005][16];

struct treap {
    node ns[1005];
    int m;
    int root;
    
    inline void r_ro(int &r) {
        int t = r;
        r = ns[r].l;
        ns[t].l = ns[r].r;
        ns[r].r = t;
      //  ns[t].ln = ns[t].ln - ns[r].ln - 1;
    }
    
    inline void l_ro(int &r) {
        int t = r;
        r = ns[r].r;
        ns[t].r = ns[r].l;
        ns[r].l = t;
       // ns[r].ln = ns[r].ln + ns[t].ln + 1;
    }
    
    void insert(int &r, int key, int cp) {
        if (r == -1) {
            m++;
            ns[m].l = ns[m].r = -1;
            ns[m].p = rand();
            ns[m].v = key;
            ns[m].cp = cp;
          //  ns[m].ln = 0;
            r = m;
        } else if (key < ns[r].v) {
            insert(ns[r].l, key, cp);
         //   ns[r].ln++;
            if (ns[ns[r].l].p > ns[r].p) {
                r_ro(r);
            }
        } else {
            insert(ns[r].r, key, cp);
            if (ns[ns[r].r].p > ns[r].p) {
                l_ro(r);
            }
        }
    }
    
    bool remove(int &r, int key) {
        if (r == -1) {
            return false;
        }
        if (key <= ns[r].v) {
            bool bl = remove(ns[r].l, key);
            if (!bl && key == ns[r].v) {
                if (ns[r].l == -1) {
                    r = ns[r].r;
                } else if (ns[r].r == -1) {
                    r = ns[r].l;
                } else if (ns[r].l == -1 && ns[r].r == -1) {
                    r = -1;
                } else {
                    if (ns[ns[r].l].p > ns[ns[r].r].p) {
                        r_ro(r);
                        remove(ns[r].r, key);
                    } else {
                        l_ro(r);
                        remove(ns[r].l, key);
                    }
                }
            }
            return true;
        } else {
            return remove(ns[r].r, key);
        }
    }
    
    int find(int r, int key) {
        //printf("%d %d %d\n", r, ns[r].v, key);
        if (r == -1) {
            return -1;
        }
        if (key <= ns[r].v) {
            int te = find(ns[r].l, key);
            if (te == -1) {
                return r;
            } else {
                return te;
            }
        } else {
            return find(ns[r].r, key);
        }
    }
    
    void init() {
        memset(ns, 0, sizeof(ns));
        m = -1;
        root = -1;
    }
};

treap tp;

int main(int argc, const char * argv[]) {
    int ff, t, k;
    char op[10];
    scanf("%d", &ff);
    for (int tt = 1; tt <= ff; tt++) {
        printf("Case #%d:\n", tt);
        int n;
        int tot = 0;
        tp.init();
        int cpc = -1;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", op);
            if (op[0] == 'A') {
                scanf("%s %d", names[++cpc], &t);
                tp.insert(tp.root, t, cpc);
                //printf("%s %s %d", op, names[cpc], t);
                tot++;
                printf("%d\n", tot);
            } else {
                scanf("%d", &t);
                k = tp.find(tp.root, t);
                //printf("root: %d\n", tp.root);
                //printf("%s %d", op, t);
                if (k == -1) {
                    puts("WAIT...");
                } else {
                    puts(names[tp.ns[k].cp]);
                    if (!tp.remove(tp.root, tp.ns[k].v)) {
                        //puts("HELP");
                    }
                    tot--;
                }
            }
        }
    }
}
