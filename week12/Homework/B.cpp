#include <bits/stdc++.h>
using namespace std;

int f[5010];
int w[5010],c[5010];

int main() {
    int n,v;
    cin>>n>>v;
    for(int i=1;i<=n;i++) {
        cin>>w[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=v;j++) if(j>=w[i])
            f[j]=max(f[j],f[j-w[i]]+c[i]);
    cout<<f[v];
    return 0;
}