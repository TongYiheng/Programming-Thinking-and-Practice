#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long ans=0;
    int r,y,g,n;
    cin>>r>>y>>g;
    cin>>n;
    
    int k,t;
    for(int i=1;i<=n;i++) {
        cin>>k>>t;
        if(k==0) {
            ans+=t;
        }
        else if(k==1) {
            ans+=t;
        }
        else if(k==2) {
            ans+=t+r;
        }
        else if(k==3) {
            continue;
        }
    }
    cout<<ans<<"\n";

    return 0;
}