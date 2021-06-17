#include <bits/stdc++.h>
using namespace std;

int t[200010], s[200010];
set<int> sp[8];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    for (int i = 1; i <= n; i++) 
    {
        int kk, v = 0;
        scanf("%d", &kk);
        for (int j = 1; j <= kk; j++) 
        {
            int x;
            scanf("%d", &x);
            v |= (1 << (x - 1));
        }
        for (int j = 1; j < 8; j++)
            if ((v & j) == j)
                sp[j].emplace(t[i]);
    }

    for (int i = 1; i <= m; i++)
        scanf("%d", &s[i]);

    for (int i = 1; i <= m; i++) 
    {
        int kk, v = 0;
        scanf("%d", &kk);
        for (int j = 1; j <= kk; j++) 
        {
            int x;
            scanf("%d", &x);
            v |= (1 << (x - 1));
        }
        if (sp[v].empty())
            printf("Angry\n");
        else {
            int tt = *sp[v].rbegin();
            printf("%d\n", s[i] - tt);
            for (int j = 1; j < 8; j++) 
            {
                sp[j].erase(tt);
            }
        }
    }

    return 0;
}