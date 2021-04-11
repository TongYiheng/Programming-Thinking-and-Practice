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

    int last=0;

    for(int i=0;i<n;i++)
    {
        if(isvowel(str[i]))
        {
            if(last)
            {
                last=1;
                continue;
            }
            else
            {
                cout<<str[i];
                last=1;
            }
        }
        else
        {
            cout<<str[i];
            last=0;
        }
    }
    return 0;
}