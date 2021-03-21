#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,num=0;
    scanf("%d%d",&n,&k);
    queue<int> q;
    for(int i=1;i<=n;i++)
        q.push(i);
    
    while(q.size()>1)
    {
        num++;
        if(num%k==0 || num%10==k)
        {
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    printf("%d\n",q.front());

    return 0;
}