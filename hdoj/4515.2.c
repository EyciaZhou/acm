#include <iostream>

using namespace std;
int isrun(int x)
{
    if((x%4==0&&x%100!=0)||(x%400==0))
        return 366;
    else
        return 365;
}
int main()
{
    int n,d,i,year,m,d1,d2;
    int r[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int p[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    cin>>n;
    while(n--)
    {
        cin>>d;
        d1=d+83;
        d2=d+283;
        year=2013;
        while(d1>isrun(year))
        {
            d1=d1-isrun(year);
            year++;
        }
        if(isrun(year)==366)
        {
            i=1;
            while(d1>r[i])
            {
                d1=d1-r[i];
                i++;
            }
            m=i;
        }
        else
        {
            i=1;
            while(d1>p[i])
            {
                d1=d1-p[i];
                i++;
            }
            m=i;
        }
        cout<<year<<"/";
        if(m<10)
            cout<<"0";
        cout<<m<<"/";
        if(d1<10)
            cout<<"0";
        cout<<d1<<" ";
        year=2013;
        while(d2>isrun(year))
        {
            d2=d2-isrun(year);
            year--;
        }
        d2=isrun(year)-d2+1;
        if(isrun(year)==366)
        {
            i=1;
            while(d2>r[i])
            {
                d2=d2-r[i];
                i++;
            }
            m=i;
        }
        else
        {
            i=1;
            while(d2>p[i])
            {
                d2=d2-p[i];
                i++;
            }
            m=i;
        }
        cout<<year<<"/";
        if(m<10)
            cout<<"0";
        cout<<m<<"/";
        if(d2<10)
            cout<<"0";
        cout<<d2<<endl;
    }
    return 0;
}
