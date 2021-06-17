#include <bits/stdc++.h>
using namespace std;

#define lb(i) ((i)&(-(i)))

long long s[1000010];
int n,q;

long long ask(int x) {
    long long res=0;
    for(int i=x;i>=1;i-=lb(i)) {
        res+=s[i];
    }
    return res;
}

void upd(int x,long long v) {
    for(int i=x;i<=n;i+=lb(i)) {
        s[i]+=v;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    int a;
    for(int i=1;i<=n;i++) {
        cin>>a;
        upd(i,a);
    }
    for(int i=1;i<=q;i++) {
        int num,x,y;
        cin>>num>>x>>y;
        if(num==1) {
            upd(x,y);
        }
        else {
            cout<<ask(y)-ask(x-1)<<"\n";
        }
    }

    return 0;
}
