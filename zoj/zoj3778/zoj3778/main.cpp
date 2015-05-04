//
//  main.cpp
//  13.C
//
//  Created by eycia on 26/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//
/*
 #include <iostream>
 #include <queue>
 using namespace std;
 
 priority_queue<int> p;
 vector<int> tm;
 
 int main(int argc, const char * argv[]) {
 int t;
 cin >> t;
 while (t--) {
 int n, m, tmp;
 while (!p.empty()) {
 p.pop();
 }
 cin >> n >> m;
 for (int i = 0; i < n; i++) {
 cin >> tmp;
 p.push(tmp);
 }
 int tot = 0;
 while (!p.empty()) {
 for (int i = 0; i < m && !p.empty(); i++) {
 tm.push_back(p.top()-1);
 p.pop();
 }
 for (int i = 0; i < tm.size(); i++) {
 if (tm[i] > 0) {
 p.push(tm[i]);
 }
 }
 tm.clear();
 tot++;
 }
 cout << tot << endl;
 }
 }
 */

#include <iostream>
#include <cmath>
using namespace std;


int main(int argc, const char * argv[]) {
    int t, tmp;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int mx = -1;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (tmp > mx) {
                mx = tmp;
            }
            tot += tmp;
        }
        cout << max(mx, int(ceil(tot*1.0/m))) << endl;
    }
    return 0;
}