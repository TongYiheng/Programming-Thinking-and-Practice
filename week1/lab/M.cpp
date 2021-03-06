#include <bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if(i%2==0)
        {
            if(str.at(i)>='a' && str.at(i)<='z')    continue;
            else    {printf("No\n");    return 0;}
        }
        else
        {
            if(str.at(i)>='A' && str.at(i)<='Z')    continue;
            else    {printf("No\n");    return 0;}
        }
    }
    printf("Yes\n");

    return 0;
}