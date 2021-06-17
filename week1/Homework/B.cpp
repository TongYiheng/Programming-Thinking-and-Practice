#include <bits/stdc++.h>
using namespace std;
 
int num[1000];
 
int main()
{
    int n,min;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
 
    min=fabs(num[0]-num[1]);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(fabs(num[i]-num[j])<fabs(min))
                min=fabs(num[i]-num[j]);
        }
    }
    printf("%d\n",min);
    return 0;
}