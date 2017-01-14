#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
const ll moder = 1e9 + 7;
ll dp[maxn][maxn];
ll BIT[maxn][maxn];
ll a[maxn];
ll numset[maxn];
int n;
void add(int x, int j, int adder)
{
    while(x <= n+1)
    {
        BIT[x][j] = (BIT[x][j] + adder) % moder;
        x += x &(-x);
//        printf("add%d\n", x);
    }
}
ll query(int x, int j)
{
    ll ans = 0;
    while(x)
    {
        ans = (ans + BIT[x][j]) % moder;
        x -= x & (-x);
    //    printf("debug");
    }
    return ans;
}

int m;
int main()
{
    int T;
    int kase = 1;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            scanf("%d%d", &n, &m);
            memset(dp, 0, sizeof(dp));
            for (int i  = 1; i <= n; i++)
            {
                scanf("%lld", a + i);
                numset[i] = a[i];
                dp[i][1] = 1;
            }
            sort(numset + 1, numset + n + 1);
            memset(BIT, 0, sizeof(BIT));

    //        for (int i = 1; i <= n; i++)
            for (int i = 1; i <= n; i++)
            {
                int pos = lower_bound(numset + 1, numset + n + 1,a[i])  - numset;
                add(pos, 1, 1);
                for (int j = m; j >=2 ; j--)
                {
        //            cout << "a["<<i<<"]= "<< pos << " ";
                    dp[i][j] = query(pos - 1, j - 1);
                    add(pos, j, dp[i][j]);
                }
            //    cout << endl;
            }

            printf("Case #%d: %lld\n", kase++, query(n,m));
        }
    }
}
