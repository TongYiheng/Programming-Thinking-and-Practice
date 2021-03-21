#include <bits/stdc++.h>
using namespace std;

int a[21];
int n,k,cnt=0;

bool prime(int n)
{
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

void dfs(int sum,int kk,int x)
{
    if(kk==k && prime(sum))
    {
        cnt++;
        return ;
    }
    if(x>n)
        return ;

    dfs(sum,kk,x+1);
    dfs(sum+a[x],kk+1,x+1);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    dfs(0,0,1);
    printf("%d\n",cnt);

    return 0;
}