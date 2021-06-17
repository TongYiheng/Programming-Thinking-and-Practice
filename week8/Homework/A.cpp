#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int maxlen;

void solve(int l,int r)
{
    int len=0;
    if(l==0 && r==0)
    {
        len=1;
        maxlen=max(maxlen,len);
        return ;
    }
    if(l==0 && r==1)
    {
        if(str[0]==str[1])
        {
            len=2;
            maxlen=max(maxlen,len);
            return ;
        }
    }
    len=0;
    if(l==r)
    {
        len+=1;
        l--;r++;
        while(l>0 && r<n)
        {
            if(str[l]==str[r])
            {
                len+=2;
                l--;r++;
            }
            else
                break;
        }
        maxlen=max(maxlen,len);
    }
    else
    {
        while(l>0 && r<n)
        {
            if(str[l]==str[r])
            {
                len+=2;
                l--;r++;
            }
            else
                break;
        }
        maxlen=max(maxlen,len);
    }
}



int main()
{
    cin>>n>>str;
    for(int i=0;i<n;i++)
        if(str[i]=='e'|| str[i]=='i' || str[i]=='o'|| str[i]=='u')
            str[i]='a';

    for(int i=0;i<n;i++)
    {
        solve(i,i);
        solve(i,i+1);
    }
    cout<<maxlen<<"\n";
    return 0;
}