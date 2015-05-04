//
//  main.cpp
//  bc16.3
//
//  Created by eycia on 14/11/1.
//  Copyright (c) 2014年 eycia. All rights reserved.
//

#include <cstdio>
#include <cstring>

const int INF = 0x3f3f3f3f;

int a[35][110];
int n;
int mm;

typedef int LL ;

void Gauss()
{
    int x;
    LL ans = 0;
    
    for(int i = 0; i < 31; i++)
    {
        x = -1;
        for(int j = 0; j < n; j++)
        {
            if(a[i][j])
            {
                x = j;  //找到一个可控制的变元
                break;
            }
        }
        //若没找到，但最后一列为0，该行结果是1
        if(x == -1 && a[i][n] == 0)
        {
            ans += (1 << (30-i));
        }
        //若找到了一个控制变元
        else if(x != -1)
        {
            ans += (1 << (30-i));
            //从该行一下异或该变元
            for(int j = i+1; j < 31; j++)
                if(a[j][x])
                {
                    for(int k = 0; k <= n; k++)
                        a[j][k] ^= a[i][k];
                }
        }
    }
    if (ans == (1 << 32) - 1) {
        
    }
}

int main()
{
    int ff;
    scanf("%d", &ff);
    while (ff--) {
        LL x;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
    
        for(int i = 0; i < n; i++) {
            scanf("%d",&x);
            for(int j = 0; j < 31; j++)
            {
                if(!(x & (1<<(30-j))))
                    a[j][i] = 1;
            }
        }
    
        for(int i = 0; i < 31; i++)
            a[i][n] = 1;
    
        Gauss();
    }
    return 0;
}