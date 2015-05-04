#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define N 410
int main(int argc, char** argv) {
    int room[N],a[N],b[N],t,ans,n,i,j,tmp;
    scanf("%d",&t);
    while(t--){
        memset(room,0,sizeof(room));
        scanf("%d",&n);
        ans=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            if(a[i]>b[i])
                swap(a[i],b[i]); 
            if(a[i]&1)
                a[i]++;
            if(b[i]&1)
                b[i]++;
                
            for(j=a[i];j<=b[i];j+=2){
                room[j]++;
                if(room[j]>ans)
                    ans=room[j];
            }
        }
        printf("%d\n",ans*10);   
    }
    return 0;
}
