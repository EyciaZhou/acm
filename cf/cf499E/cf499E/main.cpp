//
//  main.cpp
//  cf499E
//
//  Created by eycia on 14/12/25.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int pe[105];

#define __maxNodes 600005

vector<int> G[__maxNodes];
typedef vector<int>::iterator iterator_t;

int num_left;

int matching[__maxNodes];
int check[__maxNodes];

bool dfs(int u) {
    for (iterator_t i = G[u].begin(); i != G[u].end(); i++) {
        int v = *i;
        if (!check[v]) {
            check[v] = true;
            if (matching[v] < 0 || dfs(matching[v])) {
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false;
}

int xyl_dfs() {
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u = 0; u < num_left; u++) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u)) {
                ans++;
            }
        }
    }
    return ans;
}

int m_l[105][32000];
int m_r[105][32000];

int main(int argc, const char * argv[]) {
    int n, m;
    int ss, tt;
    cin >> n >> m;
    
    int mem = 0;
    for (int i = 1; i <= n; i++) {
        cin >> pe[i];
        int te = pe[i];
        
        for (int p = 2; p < 32000; p++) {
            int n1 = 0;
            while (te % p == 0) {
                n1++;
                te /= p;
            }
            m_l[i][p] = mem;
            m_r[i][p] = mem+n1-1;
            mem += n1;
        }
        m_l[i][0] = mem;
        m_r[i][0] = te;
        //cout << mem << " " << te << endl;
        mem++;
    }
    for (int i = 0; i < m; i++) {
        cin >> ss >> tt;
        for (int p = 2; p < 32000; p++) {
            if (pe[ss] % p == 0 && pe[tt] % p == 0) {
                for (int ii = m_l[ss][p]; ii <= m_r[ss][p]; ii++) {
                    for (int jj = m_l[tt][p]; jj <= m_r[tt][p]; jj++) {
                        G[ii].push_back(jj+300000);
                        G[jj].push_back(ii+300000);
                        G[ii+300000].push_back(jj);
                        G[jj+300000].push_back(ii);
                    }
                }
            }
        }
        if (m_r[ss][0] != 1 && pe[tt] % m_r[ss][0] == 0) {
            G[m_l[ss][0]].push_back(m_l[tt][0]+300000);
            G[m_l[tt][0]].push_back(m_l[ss][0]+300000);
            G[m_l[ss][0]+300000].push_back(m_l[tt][0]);
            G[m_l[tt][0]+300000].push_back(m_l[ss][0]);
        }
    }
    num_left = mem;
    cout << xyl_dfs() / 2 << endl;
}