#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N = 101000;
const int INF=0x3f3f3f3f;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
typedef int LL;
//map <int, LL> m;

LL MOD;

int sushu[126] = {
    2 ,
    3 ,
    5 ,
    7 ,
    11 ,
    13 ,
    17 ,
    19 ,
    23 ,
    29 ,
    31 ,
    37 ,
    41 ,
    43 ,
    47 ,
    53 ,
    59 ,
    61 ,
    67 ,
    71 ,
    73 ,
    79 ,
    83 ,
    89 ,
    97 ,
    101 ,
    103 ,
    107 ,
    109 ,
    113 ,
    127 ,
    131 ,
    137 ,
    139 ,
    149 ,
    151 ,
    157 ,
    163 ,
    167 ,
    173 ,
    179 ,
    181 ,
    191 ,
    193 ,
    197 ,
    199 ,
    211 ,
    223 ,
    227 ,
    229 ,
    233 ,
    239 ,
    241 ,
    251 ,
    257 ,
    263 ,
    269 ,
    271 ,
    277 ,
    281 ,
    283 ,
    293 ,
    307 ,
    311 ,
    313 ,
    317 ,
    331 ,
    337 ,
    347 ,
    349 ,
    353 ,
    359 ,
    367 ,
    373 ,
    379 ,
    383 ,
    389 ,
    397 ,
    401 ,
    409 ,
    419 ,
    421 ,
    431 ,
    433 ,
    439 ,
    443 ,
    449 ,
    457 ,
    461 ,
    463 ,
    467 ,
    479 ,
    487 ,
    491 ,
    499 ,
    503 ,
    509 ,
    521 ,
    523 ,
    541 ,
    547 ,
    557 ,
    563 ,
    569 ,
    571 ,
    577 ,
    587 ,
    593 ,
    599 ,
    601 ,
    607 ,
    613 ,
    617 ,
    619 ,
    631 ,
    641 ,
    643 ,
    647 ,
    653 ,
    659 ,
    661 ,
    673 ,
    677 ,
    683 ,
    691 ,
    701
};

int m[200][1000010];
int kk[1000000];

int mmm[200];
int ma[1000010];

inline void fun(int n, int k)
{
    for (int i = 0; i < 126; i++)
    {
        while (n % sushu[i] == 0)
        {
            n /= sushu[i];
            mmm[i] += k;
        }
    }
    if (n > 1)
    {
        ma[n] += k;
    }
}

//大数快速幂取模
inline LL quick_pow(LL a, LL b)
{
    LL ret = 1;
    while (b)
    {
        if (b & 1)
        {
            ret *= a;
            ret %= MOD;
        }
        b >>= 1;
        a *= a;
        a %= MOD;
    }
    return ret;
}

void init() {
    memset(m, 0, sizeof(m));
    memset(kk, 0, sizeof(kk));
    for (int j = 1; j <= 1000005; j++) {
        kk[j] = j;
    }
    for (int i = 0; i < 126; i++) {
        int k = sushu[i];
        int *t = m[i];
        for (int j = 1; j <= 1000005; j++) {
            while (kk[j] % k == 0) {
                t[j]++;
                kk[j] /= k;
            }
        }
    }
}

//求组合数
LL C(LL a, LL b)
{
    if (a < b || a < 0 || b < 0)
        return 0;
    LL ret = 1;
    b = min(a - b, b);
    
    memset(mmm, 0, sizeof(mmm));
    memset(ma, 0, sizeof(ma));
    //cout << "aa" << a-b+1 << " " << a << endl;
    for (int i = 0; i < 126; i++) {
        for (int j = a - b + 1; j <= a; j++) {
            mmm[i] += m[i][j];
        }
        //cout << mmm[i] << endl;
    }
    for (int j = a - b + 1; j <= a; j++) {
        if (kk[j] > 1) {
            ma[kk[j]] ++;
        }
    }
    //cout << "end1" << endl;
    for (int i = 0; i < 126; i++) {
        for (int j = 1; j <= b; j++) {
            mmm[i] -= m[i][j];
            
        }
        //cout << mmm[i] << endl;
    }
    for (int j = 1; j <= b; j++) {
        if (kk[j] > 1) {
            ma[kk[j]] --;
        }
    }
    
    //cout << "end2" << endl;
    
    ///以下计算出了具体的数
    for (int i = 0; i < 126; i++) {
        if (mmm[i] != 0) {
            //cout << sushu[i] << " . " << mmm[i] << endl;
            ret *= quick_pow(sushu[i], mmm[i]);
            ret %= MOD;
            //cout << "bb" << ret << endl;
        }
    }
    for (int i = 0; i < 1000000; i++) {
        
        if (ma[i] > 0) {
            //cout << i << " , " << ma[i] << endl;
            for (int j = 0; j < ma[i]; j++) {
                ret = ret * i % MOD;
            }
        }
    }
    
    //cout << "end4" << endl;
    int r1 = ret;
    ret = 1;
    int nn = a / 2;
    fun(nn+1, 1);
    fun(nn, -1);
    
    ///以下计算出了具体的数
    for (int i = 0; i < 126; i++) {
        if (m[i] != 0) {
            ret *= quick_pow(sushu[i], mmm[i]);
            ret %= MOD;
            //cout << "bb" << ret << endl;
        }
    }
    for (int i = 0; i < 1000000; i++) {
        if (ma[i] > 0) {
            for (int j = 0; j < ma[i]; j++) {
                ret = ret * i % MOD;
            }
        }
    }
    
    //cout << "end5" << endl;
    
    ret = ret - r1;
    
    while (ret < 0) {
        ret += MOD;
    }
    while (ret >= MOD) {
        ret -= MOD;
    }

    return ret;
}


int main() {
    int a;
    init();
    while (scanf("%d%d", &a, &MOD) != EOF) {
        a -= 2;
        printf("%d\n", C(2*a, a-1));
    }
}