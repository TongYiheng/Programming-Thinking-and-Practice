#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    
    while(~scanf("%d",&m))
    {
        int x,sum=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            sum+=x;
        }
        printf("%d\n",sum);
    }

    return 0;
}