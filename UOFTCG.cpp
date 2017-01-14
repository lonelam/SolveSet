#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000+ 100;
struct node
{
    node * nex;
    int where;
} * first[maxn], a[maxn * 2];
int test, n, m, l, c[maxn], dis[maxn], f[maxn];

inline void makelist(int x, int y)
{
    a[++l].where = y;
    a[l].nex = first[x];
    first[x] = &a[l];
}

int main()
{
    scanf("%d", &test);
    for (;test--;)
    {
        memset(first, 0, sizeof(first));
        l = 0;
        scanf("%d%d", &n,&m);
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x,&y);
            makelist(x,y);
            makelist(y,x);
        }
        memset(dis, 0, sizeof(dis));
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!dis[i])
            {
                c[1] = i;
                dis[i] = 1;
                int k = 1, ll = 1;
                for (; ll <= k; ll++)
                {
                    int m = c[ll];
                    for (node * x = first[m]; x; x = x->nex)
                    {
                        if (!dis[x->where])
                        {
                            dis[x->where] = dis[m] + 1;
                            c[++k] = x->where;
                        }
                    }
                }
                    for (int j = k; j; --j)
                    {
                        int m = c[j], tot = 0;
                        for (node * x = first[m]; x; x = x->nex)
                        {
                            if (dis[x->where] == dis[m] + 1)
                            {
                                tot += f[x->where];
                            }
                        }
                        ans += max(0, tot - 1);
                        f[m] = (tot >= 2) ? 0 : 1;
                    }

                if (f[i])
                {
                    ++ans;
                }
            }

        }
        printf("%d\n", ans + n - 1);
    }
}
