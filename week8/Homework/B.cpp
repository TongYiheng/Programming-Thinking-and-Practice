#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w,next;
}Edges[1000010];

int n,m;
int head[1000010],tot;
int in_deg[1000010],vis[1000010];

void init()
{
    tot=0;
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

bool toposort()
{
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++)
        if(in_deg[i]==0)
        {
            q.push(i);
            vis[i]=1;
        }

    vector<int> ans;
    while(!q.empty())
    {
        int x=q.top();
        q.pop();
        ans.push_back(x);

        for(int i=head[x];i!=-1;i=Edges[i].next)
        {
            if(--in_deg[Edges[i].v]==0)
            {
                q.push(Edges[i].v);
                vis[Edges[i].v]=1;
            }
        }
    }
    if(ans.size()==n)
    {
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        return true;
    }
    else
        return false;
}


int main()
{
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        addEdge(a,b,1);
        in_deg[b]++;
    }

    toposort();

    return 0;
}