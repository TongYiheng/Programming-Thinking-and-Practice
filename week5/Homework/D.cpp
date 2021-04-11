#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll h[100010];
pair<ll,ll> p[100010];
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&h[i]);
    h[0]=-1;
    h[n+1]=-1;

    stack<ll> s;
    s.push(0);
    for(ll i=1;i<=n;i++)
    {
        while(s.size()>0 && h[s.top()]>=h[i])
            s.pop();
        p[i].first=s.top();
        s.push(i);
    }

    stack<ll> t;
    t.push(n+1);
    for(ll i=n;i>=1;i--)
    {
        while(t.size()>0 && h[t.top()]>=h[i])
            t.pop();
        p[i].second=t.top();
        t.push(i);
    }

    long long ans=0;
    for(ll i=1;i<=n;i++)
    {
        ans=max(ans,(p[i].second-p[i].first-1)*h[i]);
    }
    cout<<ans<<"\n";
    return 0;
}