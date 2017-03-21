#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;

vector<int> G[maxn];
int count_subtree[maxn][5];
int total_subtree[maxn];

ll ans;
int n,k;

int subtract(int a, int b)
{
    return ((a - b) % k + k) % k;
}

void dfs(int a, int par, int depth)
{
    count_subtree[a][depth % k] = total_subtree[a] = 1;
    for (int b : G[a])
    {
        if (b != par)
        {
            dfs(b, a, depth + 1);
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; ++j)
                {
                    int remainder = subtract(i + j, 2 * depth);
                    int needs = subtract(k, remainder);
                    ans += (ll) needs * count_subtree[a][i] * count_subtree[b][j];
                }
            }
            for (int i = 0; i < k; ++i)
            {
                count_subtree[a][i] += count_subtree[b][i];
            }
            total_subtree[a] += total_subtree[b];
        }
    }
    ans += (ll) total_subtree[a] * (n - total_subtree[a]);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; ++ i)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1, 0);
    assert(ans % k == 0);
    printf("%lld\n", ans / k);
}
