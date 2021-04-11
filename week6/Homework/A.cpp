#include <bits/stdc++.h>
using namespace std;

bool isvowel(char& x)
{
    return x=='a' || x=='e' || x=='i' || x=='o' || x=='u';
}

int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;

    int last=0,cnt=0,ans=0;

    for(int i=0;i<n;i++)
    {
        if(isvowel(str[i]))
        {
            if(last)
            {
                cnt++;
                last=1;
            }
            else
            {
                cnt=1;
                last=1;
            }
        }
        else
        {
            last=0;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}