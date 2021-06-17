#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
int n,a,b,k;
int dp[2][5010],s[2][5010];

int main() {
    cin>>n>>a>>b>>k;
    dp[0][a]=1;
    for(int i=a;i<=n;i++) {
        s[0][i]=1;
    }

    for(int i=1;i<=k;i++) {
        for(int j=1;j<=n;j++) {
            if(j>b) {
                int l=ceil((j+b+1)*0.5);
                dp[i%2][j]=((s[(i+1)%2][n]-s[(i+1)%2][l-1]-dp[(i+1)%2][j])%P+P)%P;
            }
            else if(j<b) {
                int r=floor((j+b-1)*0.5);
                dp[i%2][j]=((s[(i+1)%2][r]-dp[(i+1)%2][j])%P+P)%P;
            }
            s[i%2][j]=(s[i%2][j-1]+dp[i%2][j])%P;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        ans=(ans+dp[k%2][i])%P;
    }
    cout<<ans%P<<"\n";
    return 0;
}