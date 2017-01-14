#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 505;
const int maxm = 5005;
struct item
{
    int P,Q,V;
    bool operator<(const item & rhs)
    {
        return Q > rhs.Q;
    }
} is[maxn];
int dp[maxn][maxm];

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            cin >> is[i].P >> is[i].Q >> is[i].V;
        }
        sort(is+1, is + n+1);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
            //    cout << j << endl;
                dp[i][j] = dp[i - 1][j];
                if (j + is[i].P >= is[i].Q && j + is[i].P <= m) dp[i][j] = max(dp[i][j], dp[i - 1][j + is[i].P] + is[i].V);
                ans = max(dp[i][j],ans);
            }
        }
        cout << ans << endl;
    }
}
