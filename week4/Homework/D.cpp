#include <bits/stdc++.h>
using namespace std;

int n,m;
int v[100010];
double pre[100010],pr[100010];

bool solve(double x)
{
    double a=0;
    for(int i=1;i<=n;i++)
    {
        pr[i]=pre[i]-i*x;
        if(i<m)
            continue;
        if(pr[i-m]<a)
            a=pr[i-m];
        if(pr[i]-a>=0)
            return true;
    }
    return false;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    
    pre[1]=v[1];
    for(int i=2;i<=n;i++)
        pre[i]=pre[i-1]+v[i];

    int maxV=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]>maxV)
            maxV=v[i];
    }
    double left=0,right=maxV;
    while((right-left)>0.0001)
    {
        double mid=(left+right)/2;
        if(solve(mid))
            left=mid;
        else
            right=mid;
    }
    int ans=(int)(right*1000);
    cout<<ans<<"\n";

    return 0;
}