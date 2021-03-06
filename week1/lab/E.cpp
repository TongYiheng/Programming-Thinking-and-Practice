#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        int x,sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum+=x;
        }
        printf("%d\n",sum);
    }

    return 0;
}