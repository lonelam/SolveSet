#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int v[maxn], l[maxn], r[maxn];
int disc[maxn];
int pre[maxn];
int n, dn;
int cnt[maxn];
int inpos[maxn];
int dfs_clock;
set<int> q, Q;
void afs(int x)
{
    if (l[x] != -1)
    {
        afs(l[x]);
        while(!q.empty() && )
    }
}
int main()
{
    //memset(pre, -1, sizeof(pre));
    scanf("%d", &n);
    dfs_clock = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", v + i, l + i, r + i);
        if (l[i] != -1) pre[l[i]] = i;
        if (r[i] != -1) pre[r[i]] = i;
        disc[i - 1] = v[i];
    }
    sort(disc, disc + n);
    dn = unique(disc, disc + n) - disc;
    int root = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!pre[i]) root = i;
        v[i] = lower_bound(disc, disc + dn, v[i]) - disc;
        cnt[v[i]]++;
    }
    dfs(root);
}
