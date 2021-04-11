#include <bits/stdc++.h>
using namespace std;

int parent[100010];

void init(int n)
{
    for(int i=1;i<=n;i++)
        parent[i]=i;
}

int find(int x)
{
    if(parent[x]==x)
        return x;
    return parent[x]=find(parent[x]);
}

bool unit(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return false;
    parent[x]=y;
    return true;
}

int solve(int n)
{
    int ans=0;
    for(int i=1;i<=n;i++)
        if(parent[i]==i)
            ans++;
    return ans-1;
}

int main()
{
    int n,m;
    cin>>n>>m;

    init(n);
    int x=n-1;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(unit(a,b))
            cout<<--x<<"\n";
        else
            cout<<x<<"\n";
    }

    return 0;
}