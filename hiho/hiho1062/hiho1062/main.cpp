//
//  main.cpp
//  hiho1062
//
//  Created by eycia on 5/5/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

map<string, int> ns;
map<int, string> rns;

int fa[1005];
bool v[1005];

int p = 1;

int hah(string v) {
    if (ns.find(v) == ns.end()) {
        p++;
        rns[p] = v;
        ns[v] = p;
    }
    return ns[v];
}

int main(int argc, const char * argv[]) {
    int n, q;
    string stl, str;
    cin >> n;
    memset(fa, 0, sizeof(fa));
    for (int i = 0; i < n; i++) {
        cin >> stl >> str;
        int l = hah(stl), r = hah(str);
        fa[r] = l;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        memset(v, false, sizeof(v));
        cin >> stl >> str;
        int l = hah(stl), r = hah(str);
        while (l != 0) {
            v[l] = true;
            l = fa[l];
        }
        while (r != 0 && v[r] != true) {
            r = fa[r];
        }
        if (r != 0)
            cout << rns[r] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
