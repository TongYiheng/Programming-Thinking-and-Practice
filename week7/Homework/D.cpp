#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w,next;
}Edges[1000100],Edges2[1000100];

int n,m;
int head[1000100],tot;
int dis[1000100],vis[1000100];
int head2[1000100],tot2;
int dis2[1000100],vis2[1000100];

void init()
{
    tot=1;
    for(int i=1;i<=n;i++)
    {
        head[i]=-1;
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

void dijkstra(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e9;
        vis[i]=0;
    }
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x])  continue;
        vis[x]=1;
        for(int i=head[x];i!=-1;i=Edges[i].next)
        {
            if(dis[Edges[i].v]>dis[x]+Edges[i].w)
            {
                dis[Edges[i].v]=dis[x]+Edges[i].w;
                q.push(make_pair(dis[Edges[i].v],Edges[i].v));
            }
        }
    }
}


void init2()
{
    tot2=1;
    for(int i=1;i<=n;i++)
    {
        head2[i]=-1;
    }
}

void addEdge2(int u,int v,int ww)
{
    Edges2[tot2].u=u;
    Edges2[tot2].v=v;
    Edges2[tot2].w=ww;
    Edges2[tot2].next=head2[u];
    head2[u]=tot2;
    tot2++;
}

void dijkstra2(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=1;i<=n;i++)
    {
        dis2[i]=1e9;
        vis2[i]=0;
    }
    dis2[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis2[x])  continue;
        vis2[x]=1;
        for(int i=head2[x];i!=-1;i=Edges2[i].next)
        {
            if(dis2[Edges2[i].v]>dis2[x]+Edges2[i].w)
            {
                dis2[Edges2[i].v]=dis2[x]+Edges2[i].w;
                q.push(make_pair(dis2[Edges2[i].v],Edges2[i].v));
            }
        }
    }
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int ans=0;
        cin>>n>>m;
        init();
        init2();
        for(int i=1;i<=m;i++)
        {
            int s,e,c;
            cin>>s>>e>>c;
            addEdge(s,e,c);
            addEdge2(e,s,c);
        }
        dijkstra(1);
        dijkstra2(1);
        for(int i=2;i<=n;i++)
        {
            ans+=dis[i]+dis2[i];
        }
        cout<<ans<<"\n";
    }

    return 0;
}