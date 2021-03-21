#include <bits/stdc++.h>
using namespace std;

int k[210],vis[210],cnt[210];

int main()
{
    int N,A,B;
    while(scanf("%d",&N) && N!=0)
    {
        scanf("%d%d",&A,&B);
        memset(k,0,210*sizeof(int));
        memset(vis,0,210*sizeof(int));
        memset(cnt,0,210*sizeof(int));

        for(int i=1;i<=N;i++)
            scanf("%d",&k[i]);
            
        queue<int> q;
        q.push(A);
        vis[A]=1;
        cnt[A]=0;
        while (!q.empty())
        {
            int r=q.front();
            if(r==B)
            {
                printf("%d\n",cnt[r]);
                break;
            }
                    
            q.pop();
            int up=r+k[r];
            int down=r-k[r];
            if(up<=N && vis[up]==0)
            {
                q.push(up);
                vis[up]=1;
                cnt[up]=cnt[r]+1;
            }
            if(down>=1 && vis[down]==0)
            {
                q.push(down);
                vis[down]=1;
                cnt[down]=cnt[r]+1;
            }
        }
        if(q.empty())
            printf("-1\n");
    }

    return 0;
}