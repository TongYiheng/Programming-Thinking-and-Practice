#include <bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long n,k;
const int N=4;
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
    for(int i=0;i<N;i++) {
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

    while(T--) {
        cin>>n;
        if(n==1) {
            cout<<1<<"\n";
            continue;
        }

        matrix m,mm;
        m.x[0][0]=m.x[0][2]=1,m.x[0][1]=0;
        m.x[1][1]=m.x[1][2]=1,m.x[1][0]=0;
        m.x[2][0]=m.x[2][1]=2,m.x[2][2]=1;
        mm.x[0][0]=1,mm.x[1][0]=0,mm.x[2][0]=2;

        matrix tmp=quick_pow(m,n-1);
        matrix ans=tmp*mm;
        cout<<ans.x[0][0]<<"\n";
    }
    return 0;
}