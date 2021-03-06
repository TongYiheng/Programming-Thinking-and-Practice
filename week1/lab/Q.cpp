#include <bits/stdc++.h>
using namespace std;

int g1(int x)
{
    if(x==0)    return 0;
    int a[20],w,y=0;
    for(int i=0;x>0;i++)
    {
        a[i]=x%10;
        x=x/10;
        w=i;
    }
    w++;
    for(int i=0;i<w-1;i++)
    {
        for(int j=0;j<w-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }

    for(int i=0;i<w;i++)
    {
        y+=a[i]*pow(10,w-i-1);
    }

    return y;
}

int g2(int x)
{
    if(x==0)    return 0;
    int a[20],w,y=0;
    for(int i=0;x>0;i++)
    {
        a[i]=x%10;
        x=x/10;
        w=i;
    }
    w++;
    for(int i=0;i<w-1;i++)
    {
        for(int j=0;j<w-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }

    for(int i=0;i<w;i++)
    {
        y+=a[i]*pow(10,w-i-1);
    }

    return y;
}


int main()
{
    int N,K,res=0;
    scanf("%d%d",&N,&K);

    for(int i=0;i<K;i++)
    {
        res=g1(N)-g2(N);
        N=res;
    }

    printf("%d\n",res);
    return 0;
}