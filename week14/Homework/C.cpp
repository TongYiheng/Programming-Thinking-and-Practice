#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[1000010];
long long sum[1000010];

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long ans=0;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    deque<int> q;
    q.push_back(0);
    for(int i=1;i<=n;i++) {
        while(!q.empty() && sum[q.back()]>sum[i])
            q.pop_back();
        q.push_back(i);
        while(!q.empty() && i-m>q.front())
            q.pop_front();
        ans=max(ans,sum[i]-sum[q.front()]);
    }
    cout<<ans<<"\n";
    return 0;
}