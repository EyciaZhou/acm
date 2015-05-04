//
//  main.cpp
//  最大流
//
//  Created by eycia on 14-8-13.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <queue>

const int N = 210;
const int INF = 0x7fffffff;
int num_node;

int map[N][N];
int pre[N];
int flow_in[N];
int start, end;
std::queue<int> q;

int find_one_bfs() {
    int i, t;
    while (!q.empty()) {
        q.pop();
    }
    memset(pre, -1, sizeof(pre));
    
    pre[start] = 0;
    flow_in[start] = INF;
    
    q.push(start);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        
        if (t == end) {
            break;
        }
        
        for (i = 1; i <= num_node; i++) {
            if (pre[i] == -1 &&  map[t][i]) {
                if (flow_in[t] < map[t][i]) {
                    flow_in[i] = flow_in[t];
                } else {
                    flow_in[i] = map[t][i];
                }
                q.push(i);
                pre[i] = t;
            }
        }
    }
    if (pre[end] == -1) {
        return -1;
    } else{
        return flow_in[end];
    }
}

int zdl() {
    int max_flow = 0;
    int cf_p;
    int now, prev;
    
    while ((cf_p = find_one_bfs()) != -1) {
        max_flow += cf_p;
        
        now = end;
        
        while (now != start) {
            prev = pre[now];
            map[prev][now] -= cf_p;
            map[now][prev] += cf_p;
            now = prev;
        }
    }
    return max_flow;
}
                 
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
