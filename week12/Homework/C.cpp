#include <bits/stdc++.h>
using namespace std;

long long f[1000010];
int w[1000010],c[1000010],k[1000010];
int cnt;
int ww[1000010],cc[1000010];

int main() {
    int n,v;
    cin>>n>>v;
    for(int i=1;i<=n;i++) {
        cin>>w[i]>>c[i]>>k[i];
    }

    for(int i=1;i<=n;i++) {
        int t=k[i];
        for(int kk=1;kk<=t;kk<<=1) {
            cnt++;
            cc[cnt]=kk*c[i];
            ww[cnt]=kk*w[i];
            t-=kk;
        }
        if(t>0) {
            cnt++;
            cc[cnt]=t*c[i];
            ww[cnt]=t*w[i];
        }
    }

    for(int i=1;i<=cnt;i++)
        for(int j=v;j>=0;j--) if(j>=ww[i])
            f[j]=max(f[j],f[j-ww[i]]+cc[i]);
    cout<<f[v];
    return 0;
}