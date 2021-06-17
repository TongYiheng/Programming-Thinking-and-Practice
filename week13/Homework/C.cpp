#include <bits/stdc++.h>
using namespace std;

int f[4000][4000];

int main() {
    string s;
    cin>>s;
    int n=(int)s.size();
    for(int i=1;i<=n;i++)
        f[i][i]=1;
    for(int len=2;len<=n;len++) {
        for(int i=1;i<=n-len+1;i++) {
            int l=i,r=i+len-1;
            if(s[l-1]==s[r-1]) {
                f[l][r]=f[l+1][r-1]+2;
            }
            else
                f[l][r]=max(f[l+1][r],f[l][r-1]);
        }
    }
    cout<<f[1][n]<<"\n";
    return 0;
}