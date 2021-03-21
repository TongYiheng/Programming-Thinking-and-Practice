#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,cnt=0,temp;
    cin>>n;
    vector<int> x(n);
    while(n--)
    {
        cin>>temp;
        x.push_back(temp);
    }

    for(auto it=x.begin();it!=x.end();it++)
    {
        for(auto ib=it+1;ib!=x.end();ib++)
        {
            if((*ib)-(*it)==1 || (*ib)-(*it)==-1)
                cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}