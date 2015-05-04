#include <cstdio>
#include <string.h>
#include <algorithm>
#include <iostream>

const int Max=100001;
int data[Max],len[Max],stat[Max];
int maxlen;


using namespace std;

void insert(int n)
{
	if(stat[n] > maxlen)
	{
		maxlen=stat[n];
		len[ stat[n] -1 ]=data[n];
	}
	else
	{
		if(data[n] < len[stat[n]-1])
			len[stat[n]-1]=data[n];
	}
}

void select(int n)
{
	if(0 == maxlen || data[n] > len[maxlen-1])
		stat[n]=maxlen+1;
	int c=lower_bound(len,len+maxlen,data[n])-len;
	stat[n]=c+1;
}

int main()
{
	int n,d;
	while(scanf("%d%d",&n,&d) != EOF)
	{
		memset(data,0,sizeof(data));
		for(int i=0;i<n;++i)
			cin>>data[i];
		memset(len,0,sizeof(len));
		memset(stat,0,sizeof(stat));
		maxlen=0;
		for(int i=0;i<n;++i)
		{
			if(i-d-1 >= 0)
				insert(i-d-1);
			select(i);
		}
		int res=0;
		for(int i=0;i<n;++i)
			if(stat[i] > res)
				res=stat[i];
		cout<<res<<endl;
	}
	return 0;
}