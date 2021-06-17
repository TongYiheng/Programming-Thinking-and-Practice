#include <bits/stdc++.h>
using namespace std;

int f[4000][4000];

int main() {
    string s;
    cin>>s;
    int n=(int)s.size();

    for(int i=1;i<=n;i++) {
        f[i][i]=1;
    }
    for(int len=2;len<=n;len++) {
        for(int i=1;i<=n-len+1;i++) {
            int l=i,r=i+len-1;
            int tmp=1e9;
            for(int k=l;k<r;k++) {
                tmp=min(tmp,f[l][k]+f[k+1][r]);
            }
            if((s[l-1]=='(' && s[r-1]==')') || (s[l-1]=='[' && s[r-1]==']') )
                tmp=min(tmp,f[l+1][r-1]);
            f[l][r]=tmp;
        }
    }
    cout<<f[1][n]<<"\n";
    return 0;
}