#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;
int dp[maxn * 2][maxn * 2];
int a[maxn * 2];
int dfs(int L, int R)
{
    if (L + 1 == R)
    {
        return 0;
    }
    if (dp[L][R] != -1)
    {
        return dp[L][R];
    }
    int ret = 0;
    for (int i = L + 1; i + 1<= R; i++)
    {
        ret = max(ret, dfs(L, i) + dfs(i, R) + a[i] * a[L] * a[R]);
    }
    //if (L + 2 == R) cout << ret << endl;
    return dp[L][R] = ret;
}

int main()
{
    int n;
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        memcpy(a + n, a, sizeof(int) * n);
        a[n * 2] = a[0];
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i< n; i++)
        {
            ans = max(dfs(i, i + n), ans);
        }
        cout << ans << endl;
    }
}
