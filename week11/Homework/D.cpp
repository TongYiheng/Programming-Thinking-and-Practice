#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010

int a[MAXN],dp[MAXN],t[MAXN];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    dp[1]=1;
    for(int i=1;i<=n;i++) {
        int tmp=0;
        for(int x=a[i]-1;x>=1;x-=(x&(-x)))
            tmp=max(tmp,t[x]);
        dp[i]=tmp+1;
        for(int x=a[i];x<=MAXN;x+=(x&(-x)))
            t[x]=max(t[x],dp[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<"\n";
    return 0;
}