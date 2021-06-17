#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010

long long cnt[1000010],dp[MAXN];

int main() {
    int n,a;
    int m=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a;
        cnt[a]++;
        m=max(m,a);
    }
    dp[0]=0;
    for(int i=1;i<=m;i++) {
        if(i-2<0)
            dp[i]=max(dp[i-1],cnt[i]*i);
        else
            dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
        //cout<<"dp["<<i<<"]="<<dp[i]<<"\n";
    }
    cout<<dp[m]<<"\n";

    return 0;
}