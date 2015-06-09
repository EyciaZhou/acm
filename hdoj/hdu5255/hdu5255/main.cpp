#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

#define eps 1e-8
#define ll long long

long long tp=1;
long long fix(long long a){
    while(tp<=a) tp*=10;
    tp/=10;
    return a%(tp)-(a%10)+(a/tp)+(a%10)*tp;
}

map<double, ll> mp;

int main() {
    ll tot = 0;
    for (ll i = 10; i < 1e7; i++) {
        //cout << i << endl;
        double fx = fix(i);
        double rate = fx/i;
        double r2 = ((ll)(rate * 1000000))/(1000000.0);
        if (fabs(rate-r2) < eps && rate < 10 && rate != 1) {
            //cout << (ll)fx << " " << i << endl;
            if (mp.count(r2) == 0) {
                mp[r2] = tot++;
                cout << fx << " " << i << " " << tot << " " << rate << endl;
            }
            //cout << i << " " << tot++ << endl;
        }
    }
    for (map<double, ll>::iterator it = mp.begin(); it != mp.end(); it++) {
        //printf("%.6lf\n", it->first);
    }
    cout << endl;
}
