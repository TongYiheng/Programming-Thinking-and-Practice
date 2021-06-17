#include <bits/stdc++.h>
#define MAXN 50010
#define MAXM 100010
#define MAXK 110
using namespace std;

int N,M,K;
long long dp[MAXN][MAXK];
int imp[MAXN],ct[MAXN];
int head[MAXN],to[MAXM],w[MAXM],nxt[MAXM],tot;

void add(int a,int b,int c) {
    tot++;
    to[tot]=b;
    w[tot]=c;
    nxt[tot]=head[a];
    head[a]=tot;
}

void dfs(int u,int fa) {
    for(int i=1;i<=K;i++)
        dp[u][i]=1e18;
    if(imp[u]) {
        ct[u]=1;
        dp[u][1]=0;
    }
    for(int i=head[u];i;i=nxt[i])
    {
        int y=to[i];
        long long z=w[i];
        if(y!=fa) {
            dfs(y,u);
            ct[u]+=ct[y];
            for(int j=min(K,ct[u]);j>=0;j--)
                /*for(int k=min(min(ct[y],K),j);k>=0;k--)
                    dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[y][k]+z*(K-k)*k);*/
                for(int l=0;l<=j && l<=min(K,ct[y]);l++)
                    dp[u][j]=min(dp[u][j],dp[u][j-l]+dp[y][l]+z*(K-l)*l);
        }
    }
}


int main() {
    cin>>N>>M>>K;
    for(int i=1;i<=M;i++) {
        int x;
        cin>>x;
        imp[x]=1;
    }
    for(int i=1;i<=N-1;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0);
    cout<<dp[1][K]<<"\n";
    return 0;
}