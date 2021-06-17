#include <bits/stdc++.h>
using namespace std;

int a[5010],b[5010];
int f[5010][5010];

int main() {
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    f[1][0]=f[0][1]=f[0][0]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i]==b[j]) {
                f[i][j]=f[i-1][j-1]+1;
            }
            else {
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    cout<<f[n][m]<<"\n";
    return 0;
}