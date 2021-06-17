#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w,t,next;
}Edges[100010];

int n,m,t;
int head[10010],tot;
int dis[10010],vis[10010];

void init()
{
    tot=1;
    for(int i=1;i<=n;i++)
    {
        head[i]=-1;
    }
}

void addEdge(int u,int v,int ww,int tt)
{
    Edges[tot].u=u;
    Edges[tot].v=v;
    Edges[tot].w=ww;
    Edges[tot].t=tt;
    Edges[tot].next=head[u];
    head[u]=tot;
    tot++;
}

bool check(int mid)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e9;
        vis[i]=0;
    }
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x])  continue;
        vis[x]=1;
        for(int i=head[x];i!=-1;i=Edges[i].next)
        {
            if(dis[Edges[i].v]>dis[x]+Edges[i].t && Edges[i].w>=mid)
            {
                dis[Edges[i].v]=dis[x]+Edges[i].t;
                q.push(make_pair(dis[Edges[i].v],Edges[i].v));
            }
        }
    }
    if(dis[n]<=t)
        return true;
    else
        return false;
}


int main()
{
    int X;
    cin>>X;
    while(X--)
    {
        int l=1e9,r=0;
        cin>>n>>m>>t;
        init();
        for(int i=1;i<=m;i++)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            addEdge(a,b,c,d);
            addEdge(b,a,c,d);
            l=min(l,c);
            r=max(r,c);
        }

        int ans=l;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}