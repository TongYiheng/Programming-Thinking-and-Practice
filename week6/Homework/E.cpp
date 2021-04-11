#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w;
    bool operator<(const edge& e) const {return w<e.w;}
}Edges[400010];

int n,m,p;
int par[400010];

void init()
{
    for(int i=1;i<=2*(n+m);i++)
        par[i]=i;
}
int find(int x)
{
    return par[x]==x ? x:par[x]=find(par[x]);
}
bool unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return false;
    par[x]=y;
    return true;
}

long long kruskal()
{
    sort(Edges+1,Edges+2*(m+n)+1);
    int cnt=0;
    long long ans=0;
    for(int i=1;i<=2*(m+n);i++)
    {
        if(unite(Edges[i].u,Edges[i].v))
        {
            ans+=Edges[i].w;
            if(++cnt==n)
                break;
        }
    }
    return cnt==n ? ans:-1;
}

int main()
{
    cin>>n>>m>>p;
    init();

    for(int i=1;i<=2*m;i+=2)
    {
        cin>>Edges[i].u>>Edges[i].v>>Edges[i].w;
        Edges[i+1].u=Edges[i].u;
        Edges[i+1].v=Edges[i].v;
        Edges[i+1].w=Edges[i].w;
    }
    for(int i=2*m+1;i<=2*(m+n);i+=2)
    {
        Edges[i].u=n+1;
        Edges[i].v=i-m;
        Edges[i].w=p;
        Edges[i+1].u=n+1;
        Edges[i+1].v=i-m;
        Edges[i+1].w=p;
    }
    cout<<kruskal()<<"\n";

    return 0;
}