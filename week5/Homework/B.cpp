#include <bits/stdc++.h>
using namespace std;

string str;
int cnt[500010][26];
int prefix[500010][26];
int t[26];

bool check(int l,int r)
{
    if(r-l+1<26)
        return false;

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
    int n;
    scanf("%d",&n);
    cin>>str;

    for(int i=1;i<=n;i++)
        cnt[i][str[i-1]-'A']++;
    for(int i=1;i<=n;i++)
        for(int j=0;j<26;j++)
            prefix[i][j]=prefix[i-1][j]+cnt[i][j];

    int l=1,r=1,ans=1e9;
    while(l<=n && r<=n)
    {
        if(check(l,r))
        {
            ans=min(ans,r-l+1);
            
            if(l==r)
            {
                l++;
                r++;
            }
            else
                l++;
        }
        else
            r++;
    }
    printf("%d\n",ans);
    return 0;
}