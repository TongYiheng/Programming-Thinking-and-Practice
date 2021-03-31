#include <bits/stdc++.h>
using namespace std;

int n,m;
int weight[100010];

bool solve(int x)
{
    int cnt=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(weight[i]>x)
            return false;
        if(sum+weight[i]<=x)
        {
            sum+=weight[i];
        }
        else
        {
            sum=weight[i];
            cnt++;
        }
    }
    cnt++;
    if(cnt<=m)
        return true;
    else
        return false;
}

int main()
{
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>weight[i];
        sum+=weight[i];
    }
    
    int ans=0;
    int left=0,right=sum;
    
    while(left<right)
    {
        int middle=(left+right)/2;
        if(solve(middle))
        {
            ans=middle;
            right=middle;
        }
        else
            left=middle+1;
    }

    cout<<ans<<"\n";
    return 0;
}