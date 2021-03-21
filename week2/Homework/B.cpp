#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,temp;
    cin>>n;
    map<int,int> x;
    while(n--)
    {
        cin>>temp;
        x[temp]++;
        cout<<x[temp]<<" ";
    }



    return 0;
}