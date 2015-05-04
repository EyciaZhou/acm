//
//  main.cpp
//  hdu1789
//
//  Created by eycia on 14-9-9.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node{
    int deadline;
    int score;

    bool operator<(const node& a) const
    {
        if (score == a.score) {
            return deadline < a.deadline;
        }
        return score < a.score;
    }
} *pnode;

bool cmp(const node &a, const node &b) {
    return b.deadline < a.deadline;
}

struct cmp2 {
    bool operator()(const pnode &na, const pnode &nb)
    {
        if (na->score == nb->score) {
            return na->deadline < nb->deadline;
        }
        return na->score < nb->score;
    }
};

int main(int argc, const char * argv[]) {
    node rr[1005];
    int ff;
    cin >> ff;
    while (ff--) {
        int t;
        cin >> t;
        int max = 0;
        for (int i = 0; i < t; i++) {
            cin >> rr[i].deadline;
            if (rr[i].deadline > max) {
                max = rr[i].deadline;
            }
        }
        for (int i = 0; i < t; i++) {
            cin >> rr[i].score;
        }
        sort(rr, rr+t, cmp);
        priority_queue<pnode, vector<pnode>, cmp2> q;
        int p = 0;
        for (int i = max; i >= 1; i--) {
            while (p < t && rr[p].deadline == i) {
                q.push(&rr[p]);
                p++;
            }
            if (!q.empty()) {
                q.pop();
            }
        }
        int cost = 0;
        while (!q.empty()) {
            cost += q.top()->score;
            q.pop();
        }
        cout << cost << endl;
    }
    return 0;
}
