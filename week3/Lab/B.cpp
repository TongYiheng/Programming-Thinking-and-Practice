#include <bits/stdc++.h>
using namespace std;

bool f(char a,char b)
{
    if(a>='a' && a<='z' && b>='a' && b<='z')
        return true;
     if(a>='A' && a<='Z' && b>='A' && b<='Z')
        return true;
     if(a>='0' && a<='9' && b>='0' && b<='9')
        return true;
    return false;
}

int main()
{
    string s;
    int ans=0;

    cin>>s;
    if(s.size()<6)
        ans=0;
    else
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if(f(s[i],s[i+1]))
            {
                continue;
            }
            ans++;
        }
    }
    if(ans==0)
        printf("0\n");
    else
        printf("%d\n",ans+1);

    return 0;
}