#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010

long long a[3][MAXN];
long long dp[MAXN][3];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<3;i++) {
        for(int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            dp[i][j]=INT_MAX;
        }
    }
    dp[1][0]=0;
    dp[1][1]=0;
    dp[1][2]=0;


    for(int i=2;i<=n;i++) {
        for(int k=0;k<3;k++) {
            dp[i][k]=min(dp[i-1][0] + abs(a[k][i]-a[0][i-1]),
                         min(dp[i-1][1] + abs(a[k][i]-a[1][i-1]),
                             dp[i-1][2] + abs(a[k][i]-a[2][i-1])));
        }
    }

    cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<"\n";

    return 0;
}