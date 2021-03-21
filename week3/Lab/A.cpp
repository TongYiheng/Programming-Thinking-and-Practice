#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    string str;
    cin>>str;
    int R=0,G=0,B=0;

    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='R')
            R++;
        else if(str[i]=='G')
            G++;
        else
            B++;
    }

    printf("%d\n",min(min(R,G),B));
    return 0;
}