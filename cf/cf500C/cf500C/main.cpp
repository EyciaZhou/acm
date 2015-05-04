//
//  main.cpp
//  cf500C
//
//  Created by eycia on 15/1/3.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int vv[505];

stack<int> ss;
stack<int> tm;

bool vi[1005];
int a[1005];

int main(int argc, const char * argv[]) {
    int n, m;
    int v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> vv[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        if (!vi[a[i]]) {
            tm.push(a[i]);
            vi[a[i]] = true;
        }
    }
    while (!tm.empty()) {
        ss.push(tm.top());
        tm.pop();
    }
    
    int tot = 0;
    for (int i = 0; i < m; i++) {
        v = a[i];
        while (ss.top() != v) {
            tm.push(ss.top());
            tot += vv[ss.top()];
            ss.pop();
        }
        ss.pop();
        while (!tm.empty()) {
            ss.push(tm.top());
            tm.pop();
        }
        ss.push(v);
    }
    cout << tot << endl;
}
