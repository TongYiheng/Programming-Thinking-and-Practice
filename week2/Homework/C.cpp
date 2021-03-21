#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,m,a,b;
    cin>>n>>m;

    vector<vector<int>> x(n+1,vector<int>());
    while(m--)
    {
        cin>>a>>b;
        x[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        sort(x[i].begin(),x[i].end());

    for(int i=1;i<=n;i++)
    {
        for(auto k:x[i])
            cout<<k<<" ";
        cout<<endl;
    }


    return 0;
}