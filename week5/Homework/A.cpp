#include <bits/stdc++.h>
using namespace std;

string str;
int cnt[500010][26];
int prefix[500010][26];
int t[26];

bool solve(int l,int r)
{
    for(int j=0;j<26;j++)
        t[j]=prefix[r][j]-prefix[l-1][j];
    for(int j=0;j<26;j++)
    {
        if(!t[j])
            return false;
    }
    return true;
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n,m,l,r;
    scanf("%d",&n);
    cin>>str;
    scanf("%d",&m);

    for(int i=1;i<=n;i++)
        cnt[i][str[i-1]-'A']++;
    for(int i=1;i<=n;i++)
        for(int j=0;j<26;j++)
            prefix[i][j]=prefix[i-1][j]+cnt[i][j];

    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        if(solve(l,r))
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }

    return 0;
}