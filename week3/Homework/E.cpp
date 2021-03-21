#include <bits/stdc++.h>

using namespace std;

char a[10][10];
int cnt = 0, n, k, kk;
int vis[10];

void dfs(int x)
{
    if (kk == k)
    {
        cnt++;
        return;
    }
    if (x >= n)
        return;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && a[i][x] == '#')
        {
            vis[i] = 1;
            kk++;
            dfs(x + 1);
            vis[i] = 0;
            kk--;
        }
    }
    dfs(x + 1);

}

int main() {
    while (scanf("%d%d", &n, &k) && n != -1 && k != -1)
    {
        cnt = 0;
        kk = 0;
        memset(a, '\0', 100 * sizeof(char));
        memset(vis, 0, 10 * sizeof(int));

        getchar();
        for (int i = 0; i < n; i++)
                scanf("%s", a[i]);
        dfs(0);
        printf("%d\n", cnt);
    }

    return 0;
}