#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    while(n>=50)
    {
        cnt+=7;
        n-=50;
    }
    while(n>=30)
    {
        cnt+=4;
        n-=30;
    }
    while(n>=10)
    {
        cnt++;
        n-=10;
    }
 
    printf("%d\n",cnt);
    return 0;
}