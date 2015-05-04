#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAX=505;
int dcre[MAX],c;
int a[MAX],b[MAX];
int dp[MAX]={0};
   
//计算两个序列的最长公共上升子序列
//算法复杂度n*m
//学习资料http://www.clarkok.com/blog/?p=353这篇文章讲得挺不错的，一看就懂了。
   
int calc(int n1,int n2)
{
    if(n1==0||n2==0)return 0;
       
    int ans=0;  
    int i,j,tmp;
    for(i=n1;i>0;i--)a[i]=a[i-1];
    for(i=n2;i>0;i--)b[i]=b[i-1];
   
    memset(dp,0,sizeof(int)*(n2+2));
    a[0]=b[0]=0;
    for(i=1;i<=n1;i++)  
    {  
        int m=0;  
        for(j=1;j<=n2;j++)  
        {  
            if(a[i]==b[j])
            {
                if(dp[m]+1>dp[j])
                {
                    dp[j]=dp[m]+1;
                }
            }
            else if(a[i]>b[j])
            {
                if(dp[j]>dp[m])
                {
                    m=j;
                }
            }
        }  
    }  
    for(i=1;i<=n2;i++)
    {
        if(dp[i]>ans)ans=dp[i];
    }
    return ans;
}
int copy(int a[],int lim,int s,int z[])
{
    int i,j=0;
    for(i=0;i<=s;i++)
    {
        if(z[i]<lim)
        {
            a[j++]=z[i];
        }
    }
    return j;
}
int copy1(int a[],int lim,int s,int n,int z[])
{
    int i,j=0;
    for(i=n-1;i>=s;i--)
    {
        if(z[i]<lim)
        {
            a[j++]=z[i];
        }
    }
    return j;
}
int main()
{
    int n;
    int i,j;
    int z[222];
    int T=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&z[i]);
        }
        int ans=1;
        int la,lb;
        for(i=0;i<n;i++)
        {
            la=copy(a,10000,i,z);
            lb=copy1(b,10000,i+1,n,z);
            int tmp=calc(la,lb)*2;
            if(tmp>ans)ans=tmp;
   
            la=copy(a,z[i],i-1,z);
            lb=copy1(b,z[i],i+1,n,z);
   
            tmp=calc(la,lb)*2+1;
   
            if(tmp>ans)ans=tmp;
        }
   
        printf("%d\n",ans);
    }
    return 0;
}
