#include <iostream>  
#include <stdio.h>
using namespace std;  
  
const int maxn = 500005;  
  
struct point{  
    int val;  
    point *prev;  
}M[maxn * 2];

int tot;

struct node{  
    point *a, *b;  
}c[maxn];

int t, m, n;  
  
int main()  
{  
    char op[12];  
    tot = 1;  
    n = 1;  
    int x, y;  
    scanf("%d%d", &t, &m);  
  
    while (t--)  
    {  
        scanf("%s", op);  
        scanf("%d", &x);  
        if (op[0] == 'l')  
        {  
            scanf("%d", &y);  
            point *u = &M[tot++];  
            u->val = y;  
            u->prev = c[x].a;  
            c[x].a = u;
            c[x].b = NULL;  
        }  
        else if (op[0] == 'r' && op[1] == 'o')  
        {  
            if (c[x].a)  
            {  
                point *u = &M[tot++];  
                u->val = c[x].a->val;  
                u->prev = c[x].b;  
                c[x].b = u;  
                c[x].a = c[x].a->prev;
            }  
        }  
        else if (op[0] == 'r' && op[1] == 'e')  
        {  
            if (c[x].b)  
            {  
                point *u = &M[tot++];  
                u->val = c[x].b->val;  
                u->prev = c[x].a;  
                c[x].a = u; 
                c[x].b = c[x].b->prev; 
            }  
        }  
        else if (op[0] == 'c' && op[1] == 'l')  
        {  
            c[++n] = c[x];  
        }  
        else  
        {  
            if (!c[x].a) printf("basic\n");  
            else printf("%d\n", c[x].a->val);  
        }  
    }  
}  