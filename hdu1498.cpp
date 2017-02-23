#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int uN, vN;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int grid[maxn][maxn];
int linker[maxn];
bool used[maxn];
bool dfs(int u, int cl)
{
    for (int v = 0; v < vN; v++)
    {
        if (grid[u][v] == cl && !used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v], cl))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary(int cl)
{
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 0; u < uN; u++)
    {
        memset(used, 0, sizeof(used));
        if (dfs(u, cl)) res++;
    }
    return res;
}

int main()
{
    int k;
    while(scanf("%d%d", &uN, &k)!=EOF && uN )
    {
        set<int> cls;
        vN = uN;
        for (int i = 0; i < uN; i++)
        {
            for (int j = 0; j < vN; j++)
            {
                scanf("%d", grid[i] + j);
                cls.insert(grid[i][j]);
            }
        }
        vector<int> ans;
        for (int x : cls)
        {
            int res = hungary(x);
            if (res > k) ans.push_back(x);

        }
        if (ans.empty()) printf("-1\n");
        else
        {
            for (int i = 0; i < ans.size() - 1; i++)
            {
                printf("%d ", ans[i]);
            }
            printf("%d\n", ans[ans.size() - 1]);
        }

    }
}
