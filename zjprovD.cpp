#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 202;
int Aocc[maxn * 2];
int Bocc[maxn * 2];
int disc[maxn * 2];
int A[maxn][2];
int B[maxn][2];
int main()
{
    int T, n, m, x, y;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            scanf("%d%d%d%d",&n, &m, &x, &y);
            int tot = 0;
            for (int i = 0; i < x; i++)
            {
                scanf("%d%d", A[i], A[i] + 1);
                disc[tot++] = A[i][0];
                disc[tot++]= A[i][1] + 1;
            }
            for (int i = 0; i < y; i++)
            {
                scanf("%d%d", B[i], B[i] + 1);
                disc[tot++] = B[i][0];
                disc[tot++] = B[i][1] + 1;
            }
            sort(disc, disc + tot);
            tot = unique(disc, disc + tot) - disc;
            memset(Aocc, 0, sizeof(Aocc));
            memset(Bocc, 0, sizeof(Bocc));
            for (int i = 0; i < x; i++)
            {
                int L = lower_bound(disc, disc + tot, A[i][0]) - disc;
                int R = lower_bound(disc, disc + tot, A[i][1]) - disc;
                while(L < R)
                {
                    Aocc[L++] = 1;
                }
            }
            for (int i = 0; i < y; i++)
            {
                int L = lower_bound(disc, disc + tot, B[i][0]) - disc;
                int R= lower_bound(disc, disc + tot, B[i][1]) - disc;
                while(L < R)
                {
                    Bocc[L++] = 1;
                }
            }
            int l = 0, r = 0, ans = 0;
            for (int i = 0; i < tot; i++)
            {
                if (Aocc[i] && Bocc[i])
                {
                    r = i + 1;
                }
                else
                {
                    //r = i;
                    int len = disc[r] - disc[l];
                    if (len >= m)
                    {
                        ans += len - m + 1;
                    }
                    l = r = i + 1;
                }
            }
            printf("%d\n", ans);
        }
    }
}
