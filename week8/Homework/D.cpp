#include <bits/stdc++.h>
using namespace std;

#define N 1000010

int n,m;
int c[N],dfn[N],vis[N],dcnt,scnt;
vector<int> G1[N],G2[N],G3[N];

void dfs1(int x)
{
    vis[x]=1;
    for(auto y:G1[x])
        if(!vis[y])
            dfs1(y);
    dfn[++dcnt]=x;
}

void dfs2(int x)
{
    c[x]=scnt;
    for(auto y:G2[x])
        if(!c[y])
            dfs2(y);
}

void kosaraju()
{
    dcnt=scnt=0;
    memset(c,0,sizeof c);
    memset(vis,0,sizeof vis);
    //first dfs
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs1(i);
    //second dfs
    for(int i=n;i>=1;i--)
        if(!c[dfn[i]])
        {
            ++scnt;
            dfs2(dfn[i]);
        }
}



int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        //scanf("%d%d",&a,&b);
        cin>>a>>b;
        G1[a].push_back(b);
        G2[b].push_back(a);
    }

    kosaraju();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G1[i].size();j++)
        {
            if(c[i]==c[G1[i][j]])
                continue;
            else
                //G3[c[i]].push_back(c[G1[i][j]]);
                G3[c[G1[i][j]]].push_back(c[i]);
        }
    }
    int ans=0;
    for(int i=1;i<=scnt;i++)
    {
        if(G3[i].size()==0)
            ans++;
    }
    cout<<ans<<"\n";
    return 0;
}