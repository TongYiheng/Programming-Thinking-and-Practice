#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010

int f[MAXN],sf[MAXN];

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        f[i]=-1;
    int x;
    for(int i=1;i<=m;i++) {
        cin>>x;
        f[x]=0;
    }
    f[0]=1;
    sf[0]=1;
    for(int i=1;i<=n;i++) {
        if(f[i]==-1)
        {
            if(i-k-1<0)
                f[i]=(sf[i-1])%998244353;
            else
                f[i]=(sf[i-1]-sf[i-k-1]+998244353)%998244353;
        }

        //cout<<"f["<<i<<"]="<<f[i]<<"   ";
        sf[i]=(sf[i-1]+f[i])%998244353;
        //cout<<"sf["<<i<<"]="<<sf[i]<<"  "<<"\n";
    }
    cout<<f[n]%998244353<<"\n";

    return 0;
}