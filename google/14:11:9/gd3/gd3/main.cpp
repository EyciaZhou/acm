//
//  main.cpp
//  gd3
//
//  Created by eycia on 14/11/9.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

string st[10005];
string en[10005];
int nex[10005];
int len[10005];
map<string, string> mm;
map<string, int> m2;

int find(int node) {
    //cout << st[node] << endl;
    if (mm.find(st[node]) == mm.end()) {
        len[node] = 1;
        return 1;
    }
    
    int n2 = m2[mm[st[node]]];
    nex[node] = n2;
    
    if (len[n2] == 0) {
        find(n2);
    }
    len[node] = len[n2] + 1;
    return len[node];
}

int main(int argc, const char * argv[]) {
    int ff;
    cin >> ff;
    for (int tt = 1; tt <= ff; tt++) {
        mm.clear();
        m2.clear();
        memset(nex, 0, sizeof(nex));
        memset(len, 0, sizeof(len));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> st[i] >> en[i];
            mm[st[i]] = en[i];
            m2[st[i]] = i;
        }
        int max = -1;
        int mai = -1;
        for (int i = 1; i <= n; i++) {
            int l = find(i);
            //cout << i << " " << l << endl;
            if (l > max) {
                max = l;
                mai = i;
            }
        }
        int stt = mai;
        cout << "Case #" << tt << ":";
        for (int i = 1; i <= n; i++) {
            cout << " " << st[stt] << "-" << en[stt];
            stt = nex[stt];
        }
        cout << endl;
    }
}
