#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w,next;
}Edges[90000];

int n,m,w;
int head[510],tot;
int dis[510];

void init(int n)
{
    tot=1;
    for(int i=1;i<=n;i++)
    {
        head[i]=-1;
        dis[i]=1e9;
    }
}

void addEdge(int u,int v,int ww)
{
    Edges[tot].u=u;
    Edges[tot].v=v;
    Edges[tot].w=ww;
    Edges[tot].next=head[u];
    head[u]=tot;
    tot++;
}

void solve()
{
    for(int k=1;k<n;k++)
        for(int i=1;i<=2*m+w;i++)
            if(dis[Edges[i].v]>dis[Edges[i].u]+Edges[i].w)
                dis[Edges[i].v]=dis[Edges[i].u]+Edges[i].w;
    for(int i=1;i<=2*m+w;i++)
        if(dis[Edges[i].v]>dis[Edges[i].u]+Edges[i].w)
        {
            cout<<"YES"<<"\n";
            return ;
        }
    cout<<"NO"<<"\n";
}

int main()
{
    int F;
    cin>>F;
    while(F--)
    {
        cin>>n>>m>>w;
        init(n);
        for(int i=1;i<=m;i++)
        {
            int s,e,t;
            cin>>s>>e>>t;
            addEdge(s,e,t);
            addEdge(e,s,t);
        }
        for(int i=1;i<=w;i++)
        {
            int s,e,t;
            cin>>s>>e>>t;
            addEdge(s,e,-t);
        }
        solve();
    }

    return 0;
}