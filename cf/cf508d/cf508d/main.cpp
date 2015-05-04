//
//  main.cpp
//  cf508d
//
//  Created by eycia on 15/1/28.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, string> fa;

string getf(string &v) {
    if (v == fa[v]) {
        return v;
    }
    string te = getf(fa[v]);
    fa[v] = te;
    return te;
}

map<string, pair<int, int> > mm;
map<string, vector<string> > mp;

vector<string> ans;

void dfs(string &now) {
    while (mp[now].size() > 0) {
        string next = *(mp[now].end()-1);
        mp[now].erase(mp[now].end()-1);
        dfs(next);
    }
    ans.push_back(now);
}

inline int abs(int a) {
    if (a >= 0) {
        return a;
    }
    return -a;
}

int main(int argc, const char * argv[]) {
    int n;
    char st[5];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st;
        
        string l = string(st, st+2), r = string(st+1, st+3);
        
        mm[l].first++;
        mm[r].second++;
        
        mp[l].push_back(r);
        
        if (fa.find(l) == fa.end()) {
            fa[l] = l;
        }
        if (fa.find(r) == fa.end()) {
            fa[r] = r;
        }
        
        fa[getf(l)] = getf(r);
    }
    
    int ltk = 0;
    
    for (map<string, string>::iterator it = fa.begin(); it != fa.end(); it++) {
        if (it->first == it->second) {
            ltk++;
        }
    }
    
    if (ltk > 1) {
        cout << "NO" << endl;
        return 0;
    }
    
    int tot = 0, tota = 0;
    string be, en;
    for (map<string, pair<int, int> >::iterator it = mm.begin(); it != mm.end(); it++) {
        if (it->second.first != it->second.second) {
            tota++;
            if (abs(it->second.first - it->second.second) == 1) {
                tot++;
                if (it->second.first > it->second.second) {
                    be = it->first;
                } else {
                    en = it->first;
                }
            }
        }
    }
    if (tota != tot || (tot != 0 && tot != 2)) {
        cout << "NO" << endl;
        return 0;
    }
    
    if (tot == 0) {
        be = mm.begin()->first;
    }
    
    if (tot == 2) {
        mp[en].push_back(be);
    }
    
    dfs(be);
    
    if (tot == 2)
        ans.erase(ans.begin());
    
    if (ans.size() != n+1) {
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    
    int p = 0;
    
    if (tot == 2) {
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == be && ans[(i+1) % ans.size()] == en) {
                p = i+1;
            }
        }
        
    }
    
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[(p+i) % ans.size()][0];
    }
    
    cout << ans[(p) % ans.size()][1];
}
