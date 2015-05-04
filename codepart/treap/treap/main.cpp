//
//  main.cpp
//  treap
//
//  Created by eycia on 14/11/24.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>

struct node {
    int l, r;
    int p;
    int v;
    int ln;
};

struct treap {
    node ns[50005];
    int m;
    int root;
    
    inline void r_ro(int &r) {
        int t = r;
        r = ns[r].l;
        ns[t].l = ns[r].r;
        ns[r].r = t;
        ns[t].ln = ns[t].ln - ns[r].ln - 1;
    }
    
    inline void l_ro(int &r) {
        int t = r;
        r = ns[r].r;
        ns[t].r = ns[r].l;
        ns[r].l = t;
        ns[r].ln = ns[r].ln + ns[t].ln + 1;
    }
    
    void insert(int &r, int key) {
        if (r == -1) {
            m++;
            ns[m].l = ns[m].r = -1;
            ns[m].p = rand();
            ns[m].v = key;
            ns[m].ln = 0;
            r = m;
        } else if (key < ns[r].v) {
            insert(ns[r].l, key);
            ns[r].ln++;
            if (ns[ns[r].l].p > ns[r].p) {
                r_ro(r);
            }
        } else {
            insert(ns[r].r, key);
            if (ns[ns[r].r].p > ns[r].p) {
                l_ro(r);
            }
        }
    }
    
    void remove(int &r, int key) {
        if (r == -1) {
            return;
        }
        if (ns[r].v == key) {
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
        } else {
            if (key < ns[r].v) {
                remove(ns[r].l, key);
            } else {
                remove(ns[r].r, key);
            }
        }
    }
    
    treap() {
        memset(ns, 0, sizeof(ns));
        m = -1;
        root = -1;
    }
};

int main(int argc, const char * argv[]) {
    
}
