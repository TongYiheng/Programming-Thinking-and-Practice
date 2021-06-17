#include <bits/stdc++.h>
using namespace std;

int n;
int s[110];
int f1[220][220],f2[220][220],sum[220][220];

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
    }

    for(int i=1;i<=n;i++) {
        sum[i][i]=s[i];
        for(int j=i+1;j<=n+i-1;j++) {
            if(j>n) sum[i][j]=sum[i][j-1]+s[j-n];
            else sum[i][j]=sum[i][j-1]+s[j];
        }
    }
    for(int i=n+1;i<=2*n-1;i++) {
        sum[i][i]=s[i-n];
        for(int j=i+1;j<=2*n-1;j++) {
            sum[i][j]=sum[i][j-1]+s[j-n];
        }
    }

    for(int i=1;i<=2*n-1;i++)
        f1[i][i]=f2[i][i]=0;
    for(int len=2;len<=n;len++) {
        for(int i=1;i<=2*n-len;i++) {
            int l=i,r=i+len-1;
            f1[l][r]=1e9;
            f2[l][r]=0;
            for(int k=l;k<r;k++) {
                f1[l][r]=min(f1[l][r],f1[l][k]+f1[k+1][r]);
                f2[l][r]=max(f2[l][r],f2[l][k]+f2[k+1][r]);
            }
            f1[l][r]+=sum[l][r];
            f2[l][r]+=sum[l][r];
        }
    }

    int ans1=INT_MAX,ans2=INT_MIN;
    for(int i=1;i<=n;i++) {
        ans1=min(ans1,f1[i][i+n-1]);
        ans2=max(ans2,f2[i][i+n-1]);
    }

    cout<<ans1<<"\n";
    cout<<ans2<<"\n";

    return 0;
}