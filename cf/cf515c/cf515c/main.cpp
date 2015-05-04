#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<int, int> nums[2];
map<int, int> tot;

int jc[10] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
/*
 33 22222 1111
 321 321
 1
 2
 3
 4 22
 5
 6 23
 7
 8 222
 9 33
 
 2 3
 444
 432143214321
 */
int main(int argc, const char * argv[]) {
    //init
 /*   for (int i = 2; i <= 9; i++) {
        nums[1][jc[i]] = i;
        tot[jc[i]] = i;
    }
    
    int t = 1;
    int ten = 10;
    for (int ss = 2; ss <= 8; ss++) {
        nums[t ^ 1].clear();
        for (map<int, int>::iterator it = nums[t].begin(); it != nums[t].end(); it++) {
            for (int i = 2; i <= 9; i++) {
                nums[t ^ 1][it->first+jc[i]] = ten * i + it->second;
                tot[it->first+jc[i]] = ten * i + it->second;
            }
        }
        ten = ten * 10;
        t = t ^ 1;
    }*/
    
    int n;
    string st;
    cin >> n;
    cin >> st;
    vector<int> res;
    int nus[10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= st[i] - '0'; j++) {
            nus[j]++;
        }
    }
    
    
    if (nus[7] > 0) {
        for (int i = 0; i < nus[7]; i++) {
            res.push_back(7);
        }
        for (int i = 0; i < 7; i++) {
            nus[i] -= nus[7];
        }
    }
    if (nus[5] > 0) {
        for (int i = 0; i < nus[5]; i++) {
            res.push_back(5);
        }
        for (int i = 0; i < 5; i++) {
            nus[i] -= nus[5];
        }
    }
    nus[3] += nus[9] * 2;
    nus[2] += nus[8] * 3;
    nus[3] += nus[6];
    nus[2] += nus[6];
    nus[2] += nus[4] * 2;
    for (int i = 0; i < nus[3]; i++) {
        res.push_back(3);
    }
    nus[2] -= nus[3];
    for (int i = 0; i < nus[2]; i++) {
        res.push_back(2);
    }
    
    for (int i = 0; i <res.size(); i++) {
        cout << res[i];
    }
    cout << endl;
}
