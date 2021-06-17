#include <bits/stdc++.h>
using namespace std;

int vis[2000];
int ans[2000];
pair<int,pair<int,int>> st[4000]; //(time,A?B,pos)
pair<int,int> t[2000];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>st[i].first;
        st[i].second.first=0;       //A 
        st[i].second.second=i;
        t[i].first=st[i].first;
    }
    for(int i=n+1;i<=2*n;i++)
    {
        cin>>st[i].first;
        st[i].second.first=1;       //B
        st[i].second.second=i-n;
        t[i-n].second=st[i].first;
    }

    sort(st+1,st+2*n+1);
    int left=1,right=n;
    for(int i=1;i<=2*n;i++)
    {
        if(st[i].second.first==0 && vis[st[i].second.second]==0)
        {
            ans[left]=st[i].second.second;
            left++;
            vis[st[i].second.second]=1;
        }
        else if(st[i].second.first==1 && vis[st[i].second.second]==0)
        {
            ans[right]=st[i].second.second;
            right--;
            vis[st[i].second.second]=1;
        }
        else
        {
            continue;
        }
    }

    int tA=t[ans[1]].first;
    int tB=t[ans[1]].second+tA;
    for(int i=2;i<=n;i++)
    {
        tA+=t[ans[i]].first;
        if(tA<tB)
        {
            tB+=t[ans[i]].second;
        }
        else
        {
            tB=tA+t[ans[i]].second;
        }
    }
    cout<<tB<<"\n";

    return 0;
}