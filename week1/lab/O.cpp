#include <bits/stdc++.h>
using namespace std;

int pos[100];

int main()
{
    int n,a,b;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&pos[i]);
    
    a=pos[0];
    b=pos[0];

    for(int i=1;i<n;i++)
    {
        if(pos[i]<a)    a=pos[i];
        if(pos[i]>b)    b=pos[i];
    }
    
    int res=0;
    for(int j=0;j<n;j++)
        res+=(pos[j]-a)*(pos[j]-a);

    for(int i=a+1;i<=b;i++)
    {
        int cur=0;
        for(int j=0;j<n;j++)
        {
            cur+=(pos[j]-i)*(pos[j]-i);
        }
        if(cur<res)
            res=cur;
    }
    printf("%d\n",res);

    return 0;
}