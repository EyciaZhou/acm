/*
 start : 2014-12-16 23:19:15 Tuesday
 aced : 2014-12-17 16:06:18 Wednesday
 */

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

//#define __DEBUG__

#ifdef __DEBUG__
#define DEBUG(format,...) printf("File: "__FILE__", Line: %05d: "format"\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG(format,...)
#endif

struct node {
    long long s, l;
    long long a;
};

inline bool cmp1(const node &a, const node &b) {
    return a.s < b.s;
}

inline bool cmp2(const node &a, const node &b) {
    return a.l < b.l;
}

struct Comparator {
    inline bool operator()(const node& s1, const node& s2) const {
        return s1.l < s2.l;
    }
    inline bool operator()(const node& s1, const long long& s2) const {
        return s1.l < s2;
    }
    inline bool operator()(const long long& s1, const node& s2) const {
        return s1 < s2.l;
    }
};

node aa[100005];
long long ls[100005];

vector<node> t[262200];
int l2, l1;

#define lc(a) a << 1
#define rc(a) (a << 1) | 1

long long cc1, cc2;

long long tj(int it) {
    if (t[it].size() == 0) {
        return 0;
    }
    vector<node>::iterator a = upper_bound(t[it].begin(), t[it].end(), cc2, Comparator()) - 1;
    vector<node>::iterator b = lower_bound(t[it].begin(), t[it].end(), cc1, Comparator());
    if (a < b) {
        return 0;
    }
    if (a < t[it].begin()) {
        return 0;
    }
    if (b == t[it].begin()) {
        return a->a;
    }
    return a->a - (b-1)->a;
}

void guibin(int it) {
    int i = 0, j = 0;
    int ll = lc(it), rr = rc(it);
    while (i < t[ll].size() && j < t[rr].size()) {
        if (t[ll][i].l < t[rr][j].l) {
            t[it].push_back(t[ll][i++]);
        } else {
            t[it].push_back(t[rr][j++]);
        }
    }
    while (i < t[ll].size()) t[it].push_back(t[ll][i++]);
    while (j < t[rr].size()) t[it].push_back(t[rr][j++]);
}

long long query(int t, int ql, int qr, int cl, int cr) {
    if (ql > qr) {
        return 0;
    }
    if (ql == cl && qr == cr) {
        return tj(t);
    }
    int mi = (cl + cr) / 2;
    if (ql >= mi + 1) {
        return query(rc(t), ql, qr, mi+1, cr);
    }
    if (qr <= mi) {
        return query(lc(t), ql, qr, cl, mi);
    }
    return query(lc(t), ql, mi, cl, mi) + query(rc(t), mi+1, qr, mi+1, cr);
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        DEBUG("%d\n", 1 << int(log(n) / log(2) + 0.99999));
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld %lld", &aa[i].a, &aa[i].s, &aa[i].l);
            ls[i] = aa[i].s;
        }
        sort(ls, ls+n);
        sort(aa, aa+n, cmp1);
        
        int lls = 1;
        for (int i = 1; i < n; i++) {
            if (ls[i] != ls[i-1]) {
                ls[lls++] = ls[i];
            }
        }
        l1 = lls;
        l2 = 1 << int(log(lls) / log(2) + 0.99999);
        int p = 0;
        for (int i = l2 + l1; i < l2 + l2; i++) {
            t[i].clear();
        }
        for (int i = l2; i < l2 + l1; i++) {
            t[i].clear();
            while (aa[p].s == ls[i-l2]) {
                t[i].push_back(aa[p]);
                p++;
            }
            sort(t[i].begin(), t[i].end(), cmp2);
        }
        for (int i = l2 - 1; i >= 1; i--) {
            t[i].clear();
            guibin(i);
        }
        
        for (int i = 1; i < l2 + l1; i++) {
            long long tot = 0;
            for (int j = 0; j < t[i].size(); j++) {
                t[i][j].a = tot = tot + t[i][j].a;
            }
        }
        
        scanf("%d", &m);
        long long qls, qhs, qll, qhl, te;
        long long re = 0;
        for (int i = 0; i < m; i++) {
            scanf("%lld %lld %lld %lld", &qls, &qhs, &qll, &qhl);
            
            qls += re;
            qhs -= re;
            qll += re;
            qhl -= re;
            
            if (qls > qhs) {
                te = qls;
                qls = qhs;
                qhs = te;
            }
            
            if (qll > qhl) {
                te = qll;
                qll = qhl;
                qhl = te;
            }
            
            cc1 = qll;
            cc2 = qhl;
            
            re = query(1, lower_bound(ls, ls+lls, qls) - ls, upper_bound(ls, ls+lls, qhs) - 1 - ls, 0, l2 - 1);
            printf("%lld\n", re);
        }
    }
}