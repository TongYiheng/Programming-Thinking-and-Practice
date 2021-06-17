#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w,next;
}Edges[1000010];

int n,m;
int head[1000010],tot;
int dis[1000010];

void init()
{
    tot=1;
    for(int i=1;i<=n;i++)
        head[i]=-1;
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

bool bellman_ford(int s)
{
    for(int i=1;i<=n;i++)
        dis[i]=1e9;
    dis[s]=0;
    for(int k=1;k<n;k++)
        for(int i=1;i<=tot-1;i++)
            if(dis[Edges[i].v]>dis[Edges[i].u]+Edges[i].w)
                dis[Edges[i].v]=dis[Edges[i].u]+Edges[i].w;
    for(int i=1;i<=tot-1;i++)
        if(dis[Edges[i].v]>dis[Edges[i].u]+Edges[i].w)
            return false;
    return true;
}

int main()
{
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++)
    {
        int k,a,b,c;
        scanf("%d%d%d%d",&k,&a,&b,&c);
        if(k==1)
        {
            addEdge(a-1,b,c);
        }
        else if(k==2)
        {
            addEdge(b,a-1,-c);
        }
        else if(k==3)
        {
            addEdge(a-1,b,c-1);
        }
        else if(k==4)
        {
            addEdge(b,a-1,-c-1);
        }
        else
        {
            addEdge(a-1,b,c);
            addEdge(b,a-1,-c);
        }
    }
    for(int i=0;i<n;i++)
    {
        addEdge(i,i+1,1);
        addEdge(i+1,i,0);
    }
    if(bellman_ford(0))
        cout<<dis[n]<<"\n";
    else
        cout<<"impossible"<<"\n";

    return 0;
}