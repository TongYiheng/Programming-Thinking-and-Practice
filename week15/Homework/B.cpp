#include <bits/stdc++.h>
using namespace std;
const long long p=1e9+7;
long long f[15][15];
long long n,k;
const int N=15;
struct matrix {
    long long x[N][N];
    matrix operator* (const matrix& t) const {
        matrix ret;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                ret.x[i][j]=0;
                for(int k=0;k<N;k++) {
                    ret.x[i][j]+=(x[i][k]*t.x[k][j])%p;
                    ret.x[i][j]%=p;
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
    for(int i=0;i<15;i++) {
        ret.x[i][i]=1;
    }
    while(x) {
        if(x&1) ret=ret*a;
        a=a*a;
        x>>=1;
    }
    return ret;
}

int main() {
    int T;
    cin>>T;
    f[0][0]=f[1][0]=f[1][1]=1;
    for(int i=1;i<=10;i++) {
        f[i][0]=f[i][i]=1;
    }

    for(int i=2;i<=10;i++) {
        for(int j=1;j<=i-1;j++) {
            f[i][j]=(f[i-1][j]+f[i-1][j-1])%p;
        }
    }

    while(T--) {
        cin>>n>>k;
        if(n==1) {
            cout<<1<<"\n";
            continue;
        }
        matrix m,mm;
        m.x[0][0]=1;
        for(int j=1;j<=k+1;j++)
            m.x[0][j]=f[k][j-1];
        for(int i=1;i<=k+1;i++) {
            for(int j=i;j<=k+1;j++)
                m.x[i][j]=f[k-i+1][j-i];
        }

        for(int i=0;i<=k+1;i++)
            mm.x[i][0]=1;

        matrix tmp=quick_pow(m,n-1);
        matrix ans=tmp*mm;
        cout<<ans.x[0][0]<<"\n";
    }
    return 0;
}