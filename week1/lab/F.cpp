#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m,x,sum=0;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            sum+=x;
        }
        printf("%d\n",sum);
    }

    return 0;
}