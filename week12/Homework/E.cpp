#include <bits/stdc++.h>
using namespace std;

long long v,ans;
long long w[50],c[50],pre[1000010];
int n,mid;
int mark[50];
vector<pair<long long,long long>> g1,g2;

void f1(int x) {
    if(x==mid+1) {
        long long ww=0,cc=0;
        for(int i=1;i<=mid;i++) {
            if(mark[i]) {
                ww+=w[i];
                cc+=c[i];
            }
        }
        g1.emplace_back(ww,cc);
        return ;
    }
    mark[x]=0;
    f1(x+1);
    mark[x]=1;
    f1(x+1);
}

void f2(int x) {
    if(x==n+1) {
        long long ww=0,cc=0;
        for(int i=mid+1;i<=n;i++) {
            if(mark[i]) {
                ww+=w[i];
                cc+=c[i];
            }
        }
        g2.emplace_back(ww,cc);
        return ;
    }
    mark[x]=0;
    f2(x+1);
    mark[x]=1;
    f2(x+1);
}

int main() {
    cin>>n>>v;
    mid=n/2;
    for(int i=1;i<=n;i++) {
        cin>>w[i]>>c[i];
    }

    f1(1);
    f2(mid+1);
    sort(g2.begin(),g2.end());

    pre[0]=g2[0].second;

    for(int i=1;i<g2.size();i++) {
        pre[i]=max(pre[i-1],g2[i].second);
    }

    for(auto v1:g1) {
        int l=0,r=g2.size()-1;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(v1.first+g2[mid].first<=v){
                ans=max(ans,v1.second+pre[mid]);
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        
    }
    cout<<ans<<"\n";
    return 0;
}