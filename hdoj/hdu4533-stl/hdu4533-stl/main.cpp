//
//  main.cpp
//  hdu4533-stl
//
//  Created by eycia on 14-10-14.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct node {
    long long x1, y1;
    long long x2, y2;
    
    inline bool operator<(const node& a) const
    {
        return min(a.x1, a.y1) < min(x1, y1);
    }
    
    inline long long mi() {
        return max(x1, y1);
    }
    
    inline long long ma() {
        return max(x2, y2);
    }
    
    node(long long x1, long long y1, long long x2, long long y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
    node(): x1(0), y1(0), x2(0), y2(0) {}
};

priority_queue<node> heap;

int main(int argc, const char * argv[]) {
    int ff;
    scanf("%d", &ff);
    //cin >> ff;
    while (ff--) {
        int n, query, ti;
        long long tot = 0;
        scanf("%d", &n);
        //cin >> n;
        while (!heap.empty()) {
            heap.pop();
        }
        while (n--) {
            node temp;
            scanf("%lld %lld %lld %lld", &temp.x1, &temp.y1, &temp.x2, &temp.y2);
            //cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
            heap.push(temp);
        }
        scanf("%d", &query);
        //cin >> query;
        while (query--) {
            scanf("%d", &ti);
            //cin >> ti;
            while (true) {
                if (heap.empty()) {
                    break;
                }
                node t = heap.top();
                //cout << "on : " << ti << " (" << t.x1 << "," << t.y1 << "," << t.x2 << "," << t.y2 << ")" << endl;
                if (t.mi() < ti) {
                    heap.pop();
                    if (t.ma() <= ti) {
                        tot += (t.y2 - t.y1) * (t.x2 - t.x1);
                    } else if (t.x2 <= ti) {
                        tot += (ti - t.y1) * (t.x2 - t.x1);
                        //cout << "on : " << ti << " (" << t.x1 << "," << t.y1 << "," << t.x2 << "," << t.y2 << ") -> (" << t.x1 << "," << ti << "," << t.x2 << "," << t.y2 << ")" << endl;
                        node temp(t.x1, ti, t.x2, t.y2);
                        heap.push(temp);
                    } else if (t.y2 <= ti) {
                        tot += (ti - t.x1) * (t.y2 - t.y1);
                        //cout << "on : " << ti << " (" << t.x1 << "," << t.y1 << "," << t.x2 << "," << t.y2 << ") -> (" << ti << "," << t.y1 << "," << t.x2 << "," << t.y2 << ")" << endl;
                        node temp(ti, t.y1, t.x2, t.y2);
                        heap.push(temp);
                    } else {
                        tot += (ti - t.x1) * (ti - t.y1);
                        //cout << "on : " << ti << " (" << t.x1 << "," << t.y1 << "," << t.x2 << "," << t.y2 << ") -> (" << t.x1 << "," << ti << "," << ti << "," << t.y2 << ") and (" << ti << "," << t.y1 << "," << t.x2 << "," << t.y2 << ")" << endl;
                        node t1(t.x1, ti, ti, t.y2);
                        heap.push(t1);
                        node t2(ti, t.y1, t.x2, t.y2);
                        heap.push(t2);
                    }
                } else {
                    break;
                }
            }
            printf("%lld\n", tot);
            //cout << tot << endl;
        }
    }
}
