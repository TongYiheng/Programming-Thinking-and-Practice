#include <bits/stdc++.h>
using namespace std;

long long f[1000010];
vector<pair<int,int>> q[1000010];
int ts;

int main() {
    int n,v;
    cin>>n>>v;
    int w,c,k;
    for(int i=1;i<=n;i++) {
        cin>>w>>c>>k;
        q[k].emplace_back(w,c);
        ts=max(ts,k);
    }

    for(int kk=1;kk<=ts;kk++)
        for(int j=v;j>=0;j--)
        for(auto s:q[kk])
             if(j>=s.first)
                f[j]=max(f[j],f[j-s.first]+s.second);
    cout<<f[v];
    return 0;
}