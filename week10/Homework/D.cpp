#include <bits/stdc++.h>
using namespace std;

#define lb(i) ((i)&(-(i)))

int s[1000010];
int n;
int ans[1000010];

int ask(int x) {
    int res=0;
    for(int i=x;i>=1;i-=lb(i)) {
        res+=s[i];
    }
    return res;
}

void upd(int x,int v) {
    for(int i=x;i<=1000010;i+=lb(i)) {
        s[i]+=v;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int a,b;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        v.emplace_back(a+1,b+1);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        ans[ask(v[i].second)]++;
        upd(v[i].second,1);
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<"\n";

    return 0;
}
