#include <bits/stdc++.h>
using namespace std;

long long f[12][1<<11];
int H,W;

bool check(int a,int b) {
    int t=a|b;
    int cnt=0;
    bool flag=false;
    for(int i=0;i<W;i++) {
        if((t&1)==0) {
            cnt++;
            flag=true;
        }
        else {
            if(cnt!=0 && cnt%2==1)
                return false;
            cnt=0;
            flag=false;
        }
        t>>=1;
    }
    if(flag && cnt%2==0)
        return true;
    else if(flag && cnt%2==1)
        return false;
    else
        return true;
}

int main() {
    cin>>H>>W;

    for(int j=0;j<(1<<W);j++) {
        if(check(j,0)) {
            f[1][j]=1;
        }
    }

    for(int i=2;i<=H;i++) {
        for(int j=0;j<(1<<W);j++) { //i-1行状态
            for(int k=0;k<(1<<W);k++) { //i行状态
                if((j&k)==0 && check(j,k))
                    f[i][k]+=f[i-1][j];
            }
        }
    }
    cout<<f[H][0]<<"\n";
    return 0;
}