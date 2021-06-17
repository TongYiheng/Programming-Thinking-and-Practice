#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;

int main()
{
    int n,k;
    int ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        while(it->second>=2)
        {
            ans+=1;
            it->second-=2;
        }
    }
    cout<<ans<<"\n";


    return 0;
}