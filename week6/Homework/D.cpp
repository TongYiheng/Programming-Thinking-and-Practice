#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w,next;
}Edges[200010];

int head[100010],tot,maxDis;
int vis[100010];
int v1,v2,t;
int dis1[100010],dis2[100010];

void clear(int n)
{
    maxDis=0;
    for(int j=1;j<=n;j++)
        vis[j]=0;
}
void init(int n)
{
    tot=1;
    for(int i=1;i<=n;i++)
        head[i]=-1;
}

void addEdge(int u,int v,int w)
{
    Edges[tot].u=u;
    Edges[tot].v=v;
    Edges[tot].w=w;
    Edges[tot].next=head[u];
    head[u]=tot;
    tot++;
}

void bfs(int u)
{
    queue<int> q;
    vis[u]=1;
    q.push(u);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(int i=head[x];i!=-1;i=Edges[i].next)
        {
            if(!vis[Edges[i].v])
            {
                vis[Edges[i].v]=vis[x]+1;
                t=Edges[i].v;
                maxDis=max(maxDis,vis[Edges[i].v]);
                q.push(Edges[i].v);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    init(n);

    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        addEdge(a,b,1);
        addEdge(b,a,1);
    }

    bfs(1);clear(n);v1=t;
    bfs(v1);v2=t;
    for(int i=1;i<=n;i++)
        dis1[i]=vis[i];
    clear(n);
    bfs(v2);
    for(int i=1;i<=n;i++)
        cout<<max(dis1[i],vis[i])-1<<" ";
    
    return 0;
}