//
//  main.cpp
//  13.E
//
//  Created by eycia on 26/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//vector<int> g[1005];

bool g[1005][1005];

char mat[505][505];

bool hvx[505];
bool hvo[505];

int ii[1005];
bool sed[1005];
vector<int> ans;

int n;

bool topsort() {
    int sorted = 0;
    
    while (sorted < n*2) {
        bool fd = false;
        for (int i = 0; i < n; i++) {
            if (!sed[i] && ii[i] == 0) {
                for (int j = 0; j < 1005; j++) {
                    if (g[i][j])
                        ii[j]--;
                }
                sed[i] = true;
                fd = true;
                sorted++;
                ans.push_back(i);
                break;
            }
        }
        if (fd) {
            continue;
        }
        for (int i = 500; i < 500+n; i++) {
            if (!sed[i] && ii[i] == 0) {
                for (int j = 0; j < 1005; j++) {
                    if (g[i][j])
                        ii[j]--;
                }
                sed[i] = true;
                fd = true;
                sorted++;
                ans.push_back(i);
                break;
            }
        }
        if (!fd) {
            break;
        }
    }
    if (sorted != 2 *n) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans.clear();
        
        memset(g, false, sizeof(g));
        for (int i = 0; i < 505; i++) {
            hvx[i] = false;
            hvo[i] = false;
        }
        for (int i = 0; i < 1005; i++) {
            ii[i] = 0;
            sed[i] = false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
                if (mat[i][j] == 'X') {
                    hvx[i] = true;
                } else {
                    hvo[j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 'X' && hvo[j]) {
                    if (!g[j][i+500]) {
                        ii[i+500]++;
                    }
                    g[j][i+500] = true;
                }
                if (mat[i][j] == 'O' && hvx[i]) {
                    if (!g[i+500][j]) {
                        ii[j]++;
                    }
                    g[i+500][j] = true;
                }
            }
        }
        if (!topsort()) {
            cout << "No solution" << endl;
        } else {
            vector<int> a2;
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i] >= 500 && hvx[ans[i]-500]) {
                    a2.push_back(ans[i]);
                }
                if (ans[i] < 500 && hvo[ans[i]]) {
                    a2.push_back(ans[i]);
                }
            }
            for (int i = 0; i + 1 < a2.size(); i++) {
                if (a2[i] >= 500) {
                    cout << "R" << a2[i]-500+1 << " ";
                }
                if (a2[i] < 500) {
                    cout << "C" << a2[i]+1 << " ";
                }
            }
            if (a2[a2.size()-1] >= 500) {
                cout << "R" << a2[a2.size()-1]-500+1;
            }
            if (a2[a2.size()-1] < 500) {
                cout << "C" << a2[a2.size()-1]+1;
            }
            cout << endl;
        }
    }
}