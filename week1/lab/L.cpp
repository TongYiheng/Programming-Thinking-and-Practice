#include <bits/stdc++.h>
using namespace std;

int a[100000],b[100000];

int main()
{
    int n,res=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++)
    {
        res+=a[i]*b[i];
    }
    if(res==0)  printf("Yes\n");
    else    printf("No\n");

    return 0;
}