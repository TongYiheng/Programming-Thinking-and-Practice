#include <bits/stdc++.h>
using namespace std;

long long ans;
pair<long,long> h[2010],w[2010];

int main()
{
    long n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i].first>>h[i].second;
    for(int i=1;i<=n;i++)
        cin>>w[i].first>>w[i].second;

    int f1=1,f2=1;

    while(f1<=n && f2<=n)
    {
        if(h[f1].first>=w[f2].second)
        {
            f2++;
        }
        else if(h[f1].first<=w[f2].first && h[f1].second>=w[f2].second)
        {
            ans+=w[f2].second-w[f2].first;
            f2++;
        }
        else if(w[f2].second>h[f1].first && h[f1].second>=w[f2].second && h[f1].first>w[f2].first)
        {
            ans+=w[f2].second-h[f1].first;
            f2++;
        }
        else if(h[f1].second<=w[f2].first)
        {
            f1++;
        }
        else if(h[f1].second>w[f2].first && h[f1].second<=w[f2].second && h[f1].first<w[f2].first)
        {
            ans+=h[f1].second-w[f2].first;
            f1++;
        }
        else if(h[f1].first>=w[f2].first && h[f1].second<=w[f2].second)
        {
            ans+=h[f1].second-h[f1].first;
            f1++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}