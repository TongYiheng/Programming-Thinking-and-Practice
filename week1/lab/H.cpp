#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string a;
    while(getline(cin,a))
    {
        istringstream is(a);
        int sum=0;
        int x;
        while(is>>x)
            sum+=x;
        cout<<sum<<endl;
    }
    return 0;
}