#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<list>
using namespace std;
typedef long long lld;
const int MAX=10;
const int INF=1000000000;
const double EPS=1.0e-8;
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dblcmp(double x)
{
    if(fabs(x)<EPS)return 0;
    return x<0?-1:1;
}
int a[MAX];
lld dp[2][11][1<<8][1<<8];
char s[MAX];
bool ok1[1<<8][1<<8];
bool ok2[1<<8][1<<8];
bool judge(int a,int b,int d)
{
    int i;
    int x,y;
    for(i=0;i+d-1<8;i++)
    {
        x=1<<i;
        y=1<<i<<d;
        if((x&a)&&(y&b))return false;
        if((x&b)&&(y&a))return false;
    }
    return true;
}
int cnt[1<<8];
int count(int n)
{
    int ret=0;
    while(n)
    {
        ret+=n&1;
        n>>=1;
    }
    return ret;
}
int main(){
    int ii, jj;
    int n=6;
    int i,j;
    int k;
    int T;
    int CS=1;
    for(i=0;i<(1<<8);i++)
    {
        for(j=0;j<(1<<8);j++)
        {
            ok1[i][j]=judge(i,j,1);
            ok2[i][j]=judge(i,j,2);
        }
    }
    for(i=0;i<(1<<8);i++)
    {
        cnt[i]=count(i);
    //    printf("cnt[%d]=%d\n",i,cnt[i]);
    }
    //printf("%d\n",1<<8);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<8;i++)
        {
            scanf("%s",s);
            a[i]=0;
            for(j=0;j<8;j++)
            {
                a[i]*=2;
                if(s[j]=='*')a[i]++;
            }
        //    printf("a[%d]=%d\n",i,a[i]);
        }
    
        memset(dp,0,sizeof(dp));
        int xx=0;
        for(i=0;i<(1<<8);i++)
        {
            if(i&a[0])continue;
            if(cnt[i]>n)continue;
            dp[0][cnt[i]][0][i]++;
            xx++;
            //printf("i=%d\n",i);
        }
    //    printf("xx=%d\n",xx);
        int tag=0;
        for(i=1;i<8;i++)
        {
            tag=i&1;
            for(xx=0;xx<=n;xx++)
            {
                for(j=0;j<(1<<8);j++)
                {
                    for(k=0;k<(1<<8);k++)
                    {
                        dp[tag][xx][j][k]=0;
                    }
                }
            }
            for(j=0;j<(1<<8);j++)
            {
                if(i-2>=0&&(j&a[i-2]))continue;
    
                for(k=0;k<(1<<8);k++)
                {
                    if(k&a[i-1])continue;
    
                    if(cnt[j]+cnt[k]>n)continue;
                    if(!ok2[j][k])continue;
                    int tt;
                        
                    for(tt=cnt[j]+cnt[k];tt<=n;tt++)
                    {
                        if(dp[1-tag][tt][j][k]==0)continue;
    
                        for(int z=0;z<(1<<8);z++)
                        {
                            if(cnt[z]+tt>n)continue;
                            if(z&a[i])continue;
                            if(!ok2[z][k]||!ok1[z][j])continue;
                            dp[tag][tt+cnt[z]][k][z]+=dp[1-tag][tt][j][k];
                        }
                    }
                }
            }
            lld ans=0;
            for(ii=0;ii<(1<<8);ii++)
            {
                for(jj=0;jj<(1<<8);jj++)
                {
                //if(dp[tag][n][i][j]>0)printf("%d %d\n",i,j);
                    ans+=dp[tag][n][ii][jj];
                }
            }   
             printf("%lld\n",ans);
    
        }
   
       
       
    }
    return 0;
}
