#include<stdio.h> 
#include<string.h> 
#include<algorithm> 
   
using namespace std ; 
const int MAX=110; 
const int INF=100000000; 
char s[MAX]; 
int c[6]; 
struct BigNum 
{ 
    int dig[6]; 
    int len; 
    void clr() 
    { 
        len=1; 
        memset(dig,0,sizeof(dig)); 
    } 
}; 
   
bool dig(char x){return x>='0'&&x<='9';} 
BigNum f; 
BigNum Div(BigNum a,int b) 
{ 
    int i; 
    int t; 
    BigNum ret; 
    ret.clr(); 
    for(i=a.len-1;i>=1;i--) 
    { 
        t=a.dig[i]; 
        ret.dig[i-1]+=t; 
        a.dig[i]=0; 
        a.dig[i-1]-=b*t; 
    } 
    ret.len=-1; 
    if(a.dig[0]!=0)return ret; 
   
    for(i=5;i>=0&&ret.dig[i]==0;i--); 
   
    ret.len=i+1; 
    return ret; 
} 
int calc() 
{ 
    int i; 
    if(f.dig[0]==0) 
    { 
        for(i=0;i+1<f.len;i++) 
        { 
            f.dig[i]=f.dig[i+1]; 
        } 
        f.len--; 
        return 0; 
    } 
    for(i=-1000;i<=1000;i++) 
    { 
        if(i==0&&f.dig[0]!=0)continue; 
        else if(i!=0&&f.dig[0]%i!=0)continue; 
   
        BigNum tmp=Div(f,i); 
        if(tmp.len==-1)continue; 
        f=tmp; 
        return i; 
    } 
    return INF; 
} 
int main () 
{ 
    int T,CS=1; 
    int len; 
    int tmp,p; 
    int i; 
    scanf("%d",&T); 
    while (T--) 
    { 
        scanf("%s",s); 
        memset(c,0,sizeof(c)); 
        len=strlen(s); 
        int left,right; 
        for(i=0;i<len;i++) 
        { 
            if(s[i]=='x') 
            { 
                //计算有边 
                if(s[i+1]=='^') 
                { 
                    right=i+2; 
                    p=s[right]-'0';//最多是5，取1为就行了 
                } 
                else
                { 
                    right=i; 
                    p=1; 
                } 
   
                int ten=1; 
   
                left=i-1; 
                tmp=0; 
                while(left>=0&&dig(s[left])) 
                { 
                    tmp+=(s[left]-'0')*ten; 
                    ten*=10; 
                    left--; 
                } 
   
                if(tmp==0)tmp++; 
   
                if(left>=0&&s[left]=='-') 
                { 
                    tmp=-tmp; 
                    left--; 
                } 
                   
                c[p]+=tmp; 
   
                for(left++;left<=right;left++) 
                { 
                    s[left]=1; 
                } 
            } 
        } 
        //puts("zz"); 
        for(i=0;i<len;i++)//求剩下的常数 
        { 
            if(s[i]=='-'||dig(s[i])) 
            { 
                int sign=1; 
                tmp=0; 
                if(s[i]=='-') 
                { 
                    sign=-1; 
                    i++; 
                } 
                while(i<len&&dig(s[i])) 
                { 
                    tmp=tmp*10+s[i]-'0'; 
                    i++; 
                } 
                i--; 
                c[0]+=tmp*sign; 
            } 
        } 
        int maxc=5; 
        while(maxc>=0&&c[maxc]==0) 
        { 
            maxc--; 
        } 
        printf("Case #%d: ",CS++); 
        if(maxc<=0) 
        { 
            puts("-1"); 
            continue; 
        } 
        else if(c[maxc]!=1) 
        { 
            puts("-1"); 
            continue; 
        } 
        //puts("");for(i=0;i<=maxc;i++)printf("x[%d]=%d\n",i,c[i]); 
        int ans[6]; 
           
        f.clr(); 
        memcpy(f.dig,c,sizeof(c)); 
        f.len=maxc+1; 
        for(i=0;i<maxc;i++) 
        { 
            ans[i]=calc(); 
            if(ans[i]==INF)break; 
        } 
        if(i<maxc) 
        { 
            puts("-1"); 
        } 
        else
        { 
            sort(ans,ans+maxc); 
            for(i=0;i<maxc;i++) 
            { 
                if(ans[i]==0)putchar('x'); 
                else if(ans[i]<0)printf("(x%d)",ans[i]); 
                else printf("(x+%d)",ans[i]); 
            } 
            puts(""); 
        } 
    } 
    return 0 ; 
}
