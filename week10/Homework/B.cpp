#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main()
{
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x;
        v.emplace_back(x);
    }
    sort(v.begin(),v.end());
    if(n%2==1) {
        printf("%d %d %d",v[n-1],v[n/2],v[0]);
    }
    else {
        float middle=(v[n/2]+v[n/2-1])/2.0;
        if(abs(v[n/2]+v[n/2-1])%2==1) {
            printf("%d %.1f %d",v[n-1],middle,v[0]);
        }
        else
            printf("%d %d %d",v[n-1],(v[n/2]+v[n/2-1])/2,v[0]);
    }

    return 0;
}