#include <bits/stdc++.h>
using namespace std;

int num[1000010];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);

    deque<int> q;
    for(int i=1;i<=n;i++)
    {
        while(q.size()>0 && i-q.front()>=k)
            q.pop_front();
        while(q.size()>0 && num[q.back()]>num[i])
            q.pop_back();
        q.push_back(i);
        if(i>=k)
            cout<<num[q.front()]<<" ";
    }
    cout<<"\n";

    deque<int> qq;
    for(int i=1;i<=n;i++)
    {
        while(qq.size()>0 && i-qq.front()>=k)
            qq.pop_front();
        while(qq.size()>0 && num[qq.back()]<num[i])
            qq.pop_back();
        qq.push_back(i);
        if(i>=k)
            cout<<num[qq.front()]<<" ";
    }
    cout<<"\n";

    return 0;
}