#include <bits/stdc++.h>
using namespace std;

int res[30010];

int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    map<pair<int,int>,int> mp;
    for(int i=0;i<m;i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        mp.emplace(make_pair(r,-l),k);
    }

    auto it=mp.begin();
    for(int i=0;i<m;i++)
    {
        pair<int,int> pp=it->first;
        int num=it->second;
        it++;
        int have=0;
        for(int j=-pp.second;j<=pp.first;j++)
        {
            if(res[j])
                have++;
        }
        if(have>=num)
            continue;
        else
        {
            for(int j=pp.first;j>=-pp.second && have<num;j--)
            {
                if(!res[j])
                {
                    res[j]=1;
                    ans++;
                    have++;
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}