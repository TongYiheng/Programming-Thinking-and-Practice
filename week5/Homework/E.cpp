#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll pr[100010][25],num[100010][25];
ll pm[100],pt[100];

const ll x=1e9+7;

ll quickpow(ll a,ll b,ll p)
{
    ll ans=1;
    for(a%=p;b;a=a*a%p,b>>=1)
        if(b&1)
            ans=ans*a%p;
    return ans;
}

bool prime(ll n)
{
    if (n==1) return false;
    if (n==2) return true;
    for(ll i=2;i*i<=n;i++)
        if (n%i==0) return false;
    return true;
}

int main()
{
    ll n,m,ans=1;
    cin>>n>>m;

    int cnt=0;
    for(int i=2;i<=100;i++)
        if(prime(i))
            pm[cnt++]=i;

    for(int i=0;i<m;i++)
    {
        ll l,r,c,b;
        cin>>l>>r>>c>>b;
        for(int k=0;k<cnt;k++)
        {//for each prime
            while(!(c%pm[k]))
            {// can
                pr[l][k]+=b;
                pr[r+1][k]-=b;
                c/=pm[k];
            }
            if(c==1)
                break;
        }
    }

    for(int i=1;i<=n;i++)
        for(int k=0;k<cnt;k++)
            num[i][k]=pr[i][k]+num[i-1][k];

    for(int k=0;k<cnt;k++)
        pt[k]=num[1][k];
    for(int k=0;k<cnt;k++)
        for(int i=2;i<=n;i++)
            pt[k]=min(pt[k],num[i][k]);

    for(int k=0;k<cnt;k++)
        ans=ans*quickpow(pm[k],pt[k],x)%x;
    cout<<ans<<"\n";
    return 0;
}