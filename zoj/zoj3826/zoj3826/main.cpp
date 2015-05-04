//
//  main.cpp
//  zoj3826
//
//  Created by eycia on 14/11/23.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

//string strr;

struct node {
    int st, en;
    map<string, node *> *va;
} nodes[10005];
map<string, node *> maps[10005];

typedef node *pnode;
int memn = 0, memm = 0;

char strr[2000000];

int dd(int st, pnode root) {
    //cout << st << endl;
    int fi = st;
    while (true) {
        //cout << "bb " << fi << " " << string(strr, fi, 3) << endl;
        if (strr[fi] == '}') {
            //cout << "cc" << endl;
            break;
        }/*
        if (fi > en) {
            break;
        }*/
        int a1 = fi;
        while (strr[a1] != '"') a1++;
        int a2 = a1 + 1;
        while (strr[a2] != '"') a2++;
        int a3 = a2 + 1;
        while (strr[a3] != ':') a3++;
        int a4 = a3 + 1;
        int a5;
        
        if (strr[a4] == '{') {
            /*
            int tt = -1;
            a5 = a4 + 1;
            while (tt != 0) {
                if (strr[a5] == '{') tt--;
                if (strr[a5] == '}') tt++;
                if (tt == 0) {
                    break;
                }
                a5++;
            }*/
            memn++;
            pnode temp = &nodes[memn];
            temp->st = a4;
            //temp->en = a5;
            memm++;
            maps[memm].clear();
            temp->va = &maps[memm];
            (*root->va)[string(strr+a1, strr+a2+1)] = temp;
            //root->va->insert(make_pair(string(strr+a1, strr+a2+1), temp));
            int ee = dd(a4 + 1, temp);
            //dd(a4 + 1, a5 - 1, temp);
            temp->en = ee;
            a5 = ee;
        } else {
            a5 = a4 + 1;
            while (strr[a5] != '"') a5++;
            memn++;
            pnode temp = &nodes[memn];
            temp->st = a4;
            temp->en = a5;
            temp->va = NULL;
            //string(strr, a1, a2 - a1 + 1);
            //string(strr+a1, strr+a2+1);
            (*root->va)[string(strr+a1, strr+a2+1)] = temp;
            //root->va->insert(make_pair(string(strr+a1, strr+a2+1), temp));
        }
        fi = a5 + 1;
    }
    return fi;
}

int main() {
    //freopen("/Volumes/code/code/acm/zoj/zoj3826/zoj3826/i","r",stdin);
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        memn = 0, memm = 0;
        getchar();
        gets(strr);
        int ls = strlen(strr);
        //cin >> strr;
        //strr = string(ch);
        memn++;
        pnode root = &nodes[memn];
        root->st = 0;
        root->en = ls;
        memm++;
        maps[memm].clear();
        root->va = &maps[memm];
        dd(1, root);
        
        int t;
        strr[ls] = ' ';
        strr[ls+1] = '\0';
        string temp;
        scanf("%d", &t);
        while (t--) {
            pnode tn = root;
            
            cin >> temp;
            int a1 = 0, a2 = 1;
            
            while (true) {
                while (temp[a2] != '"') a2++;
                map<string, pnode>::iterator it = tn->va->find(string(temp, a1, a2 - a1 + 1));
                if (it == tn->va->end()) {
                    printf("Error!\n");
                    //cout << "Error!" << endl;
                    break;
                } else {
                    tn = it->second;
                    if (a2 == temp.length() - 1) {
                        char te = strr[tn->en + 1];
                        strr[tn->en + 1] = '\0';
                        printf("%s\n", strr + tn->st);
                        strr[tn->en + 1] = te;
                        //cout << string(strr, tn->st, tn->en - tn->st + 1) << endl;
                        break;
                    }
                }
                a1 = a2 + 2;
                a2 = a1 + 1;
            }
        }
    }
    return 0;
}
