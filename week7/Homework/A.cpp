#include <bits/stdc++.h>
using namespace std;

int a[10000],b[10000];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    b[1]=(a[1]+a[2])/2;
    for(int i=2;i<=n-1;i++)
        b[i]=(a[i-1]+a[i]+a[i+1])/3;
    b[n]=(a[n-1]+a[n])/2;
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
    return 0;
}