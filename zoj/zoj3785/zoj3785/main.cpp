//
//  main.cpp
//  13.J
//
//  Created by eycia on 26/4/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
using namespace std;
/*
 int exp(int base, int up, int mod) {
 base = base % mod;
 int res = 1;
 int tmp = base;
 while (up) {
 if (up & 1) {
 res = res * tmp % mod;
 }
 tmp = tmp * tmp % mod;
 up >>= 1;
 }
 return res;
 }
 
 int main(int argc, const char * argv[]) {
 int tot = 0;
 for (int i = 1; i < 1000005; i++) {
 tot = (tot + exp(i, i, 7)) % 7;
 if (i % 1 == 0) {
 cout << tot << ",";
 }
 }
 }
 
 int bh[10][10] = {
 {0},
 {1},
 {1, 2, 4},
 {1, 3, 2, 6, 4, 5},
 {1, 4, 2},
 {1, 5, 4, 6, 2, 3},
 {1, 6}
 };
 
 int xh[10] = {
 1, 1, 3, 6, 3, 6, 2
 };
 */

int biao[] = {
    0,1,5,4,1,4,5,5,6,0,4,6,0,6,6,0,2,0,1,6,0,0,1,5,6,3,0,6,6,0,1,4,6,5,6,6,0,2,4,5,0,6,6,0,4,3,0,3,4,4,5,6,3,5,6,5,5,6,1,6,0,5,6,6,0,4,5,2,6,5,5,6,0,3,5,4,5,5,6,1,3,4,6,5,5,6,3,2,6,2,3,3,4,5,2,4,5,4,4,5,0,5,6,4,5,5,6,3,4,1,5,4,4,5,6,2,4,3,4,4,5,0,2,3,5,4,4,5,2,1,5,1,2,2,3,4,1,3,4,3,3,4,6,4,5,3,4,4,5,2,3,0,4,3,3,4,5,1,3,2,3,3,4,6,1,2,4,3,3,4,1,0,4,0,1,1,2,3,0,2,3,2,2,3,5,3,4,2,3,3,4,1,2,6,3,2,2,3,4,0,2,1,2,2,3,5,0,1,3,2,2,3,0,6,3,6,0,0,1,2,6,1,2,1,1,2,4,2,3,1,2,2,3,0,1,5,2,1,1,2,3,6,1,0,1,1,2,4,6,0,2,1,1,2,6,5,2,5,6,6,0,1,5,0,1,0,0,1,3,1,2,0,1,1,2,6,0,4,1,0,0,1,2,5,0,6,0,0,1,3,5,6,1,0,0,
};

string day[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

int main(int argc, const char * argv[]) {
    int t;
    long long k;
    cin >> t;
    while (t--) {
        cin >> k;
        long long tot = biao[k%294];
        cout << day[(biao[k%294] + 6) % 7] << endl;
    }
}