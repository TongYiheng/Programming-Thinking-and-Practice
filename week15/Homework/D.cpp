#include <bits/stdc++.h>
using namespace std;
const long long p=998244353;
int H[110][110];
const int N=110;
struct matrix {
    long long x[N][N];
    matrix operator* (const matrix& t) const {
        matrix ret;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                ret.x[i][j]=0;
                for(int k=0;k<N;k++) {
                    ret.x[i][j]=max(ret.x[i][j],x[i][k]+t.x[k][j]);
                }
            }
        }
        return ret;
    }
    matrix() { memset(x,0,sizeof x);}
    matrix(const matrix& t) { memcpy(x,t.x,sizeof x);}
};

matrix quick_pow(matrix a,int x) {
    matrix ret;
    for(int i=0;i<N;i++) {
    	  for(int j=0;j<N;j++) {
            ret.x[i][j]=-1e18;
        }
    }
    for(int i=0;i<N;i++) {
        ret.x[i][i]=0;
    }
    while(x) {
        if(x&1) ret=ret*a;
        a=a*a;
        x>>=1;
    }
    return ret;
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            cin>>H[i][j];

    matrix ma,mm;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            ma.x[i][j]=H[j][i];

    matrix ans=quick_pow(ma,n-1)*mm;
    long long res=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            res=max(res,ans.x[i][j]);
    cout<<res<<"\n";
    return 0;
}