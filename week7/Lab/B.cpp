#include <bits/stdc++.h>

using namespace std;

int s[1000010],t[1000010];
int prize,num;
int n;


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        s[l]+=1;
        s[r+1]-=1;
    }
    for(int i=1;i<=n;i++)
    {
        t[i]=s[i]+t[i-1];
        if(t[i]>=num)
        {
            num=t[i];
            prize=i;
        }
    }
    cout<<prize<<" "<<num;

    return 0;
}