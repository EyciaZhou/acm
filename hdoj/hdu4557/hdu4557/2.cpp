//Treap平衡树解法
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
#define N 10010
int sum=0;
/**********************************************/
#define nil 0
struct Node{
    int k,w,l,r;
	string s;
    void init(string str,int v){
        k=v;l=r=nil;w=rand();
		s=str;
    }
}T[N];
class Treap{
public:
    int root,w;
    Treap(){root=w=nil;T[0].init("",0);T[0].w=0x3fffffff;}
    void cut(int x,int &l,int &r,int k){//x 拆分为l,r
        if(x==nil){l=r=nil;return;}
        if(T[x].k<=k){
            l=x;
            cut(T[x].r,T[l].r,r,k);
        }else{
            r=x;
            cut(T[x].l,l,T[r].l,k);
        }
    }
    void merge(int &x,int l,int r){//l r合并到x
        if(l==nil||r==nil){x=(l==nil?r:l);return;}
        if(T[l].w<T[r].w){
            merge(T[l].r,T[l].r,r);
            x=l;
        }else{
            merge(T[r].l,l,T[r].l);
            x=r;
        }
    }
    void insert(string s,int k){//插入k
        int x=++w,l,r;
        T[x].init(s,k);
        cut(root,l,r,k);
        merge(l,l,x);
        merge(root,l,r);
    }
    void find(int k){//找到最k的前驱并删除
        int x,l,r,f=nil;
		bool b=false;
		cut(root,l,r,k-1);
		if(r!=nil){
			sum--;
			b=true;
			x=r;
			while(T[x].l!=nil)f=x,x=T[x].l;
			cout<<T[x].s<<endl;
			if(f==nil)merge(r,T[x].l,T[x].r);
			else merge(T[f].l,T[x].l,T[x].r);//删除x
		}else  printf("WAIT...\n");
		merge(root,l,r);
    }
    void dfs(int x){
        if(x==nil)return;
        dfs(T[x].l);
        cout<<T[x].k<<" ";
        dfs(T[x].r);
    }
};
/***********************************************/
int main(){
    int i,j,k,T,n,t=1;
    char ch[50];
    scanf("%d",&T);
    while(T--){
		Treap treap;
        scanf("%d",&n);
        printf("Case #%d:\n",t++);
        sum=0;
        while(n--){
            
            scanf("%s",ch);
            switch(ch[0]){
            case 'A':
                scanf("%s%d",ch,&k);
				treap.insert(ch,k);
                printf("%d\n",++sum);
                break;
            case 'F':
                scanf("%d",&k);
				treap.find(k);
                break;
            }
        }
    }
return 0;
}
