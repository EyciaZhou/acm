//
//  main.cpp
//  cf509d
//
//  Created by eycia on 15/2/12.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int mat[105][105];
int sub[105][105];
vector<int> su[105];
int ad[105];

int main(int argc, const char * argv[]) {
    int n, m;
    int mod = -1, ma = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            ma = max(ma, mat[i][j]);
        }
    }
    
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            su[j].push_back(mat[i][j] - mat[i][j-1]);
        }
        
        sort(su[j].begin(), su[j].end());
        su[j].erase(unique(su[j].begin(), su[j].end()), su[j].end());
        
        if (su[j].size() > 2) {
            cout << "NO" << endl;
            return 0;
        }
        
        if (su[j].size() == 2 && !(su[j][0] < 0 && su[j][1] > 0)) {
            cout << "NO" << endl;
            return 0;
        }
        
        if (su[j].size() == 1) {
            ad[j] = su[j][0];
        }
        
        if (su[j].size() == 2) {
            ad[j] = su[j][1];
            if (mod < 0) {
                mod = su[j][1] - su[j][0];
            }
            
            if (mod != su[j][1] - su[j][0]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    
    if (mod < 0) {
        mod = ma + 1;
    }
    
    if (mod <= ma) {
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    cout << mod << endl;
    for (int i = 0; i < n; i++) {
        cout << mat[i][0] << " ";
    }
    cout << endl;
    
    int tot = 0;
    for (int i = 0; i < m; i++) {
        tot += ad[i];
        while (tot < 0) {
            tot += mod;
        }
        cout << tot << " ";
    }
    cout << endl;
}
