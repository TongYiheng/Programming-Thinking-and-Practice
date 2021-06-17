#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010
typedef long long ll;
int n;
int deep[MAXN],ans;
ll num[MAXN],cnt;
int head[MAXN],to[MAXN],nxt[MAXN],tot;

void add(int x,int y) {
    tot++;
    to[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dfs(int x,int fa) {
    bool isLeaf=true;
    for(int i=head[x];i;i=nxt[i]) {
        int y=to[i];
        if(y!=fa) {
            isLeaf=false;
            dfs(y,x);
            if(ans<deep[x]+deep[y]+1) {
                ans=deep[x]+deep[y]+1;
                cnt=num[x]*num[y];
            }
            else if(ans==deep[x]+deep[y]+1) {
                cnt+=num[x]*num[y];
            }
            if(deep[y]+1>deep[x]) {
                deep[x]=deep[y]+1;
                num[x]=num[y];
            }
            else if(deep[y]+1==deep[x]) {
                num[x]+=num[y];
            }
        }
    }
    if(isLeaf) {
        deep[x]=0;
        num[x]=1;
    }
}

int main() {
    cin>>n;
    for(int i=1;i<=n-1;i++) {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    dfs(1,0);
    cout<<ans<<" "<<cnt<<"\n";
    return 0;
}