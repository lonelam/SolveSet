#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
ll dp[10][11];
ll DP(int cur, int flr)
{
    if (dp[cur][flr] != -1)
    {
        return dp[cur][flr];
    }
    if (cur == 0)
    {
        return dp[cur][flr] = 10 - flr;
    }
    ll sum = 0;
    for (int i = flr; i < 10; i++)
    {
        sum += DP(cur - 1, i);
    }
    return dp[cur][flr] = sum;
}

ll dfs(int cur, int flr, int X)
{
    int origx = X;
    if (cur == -1)
    {
        return 0;
    }
    for (int i = 0; i < cur; i++)
        X /= 10;
    X %= 10;
    ll sum = 0;
    for (int i = flr; i < X; i++)
    {
        sum += DP(cur, i);
    }
    sum += dfs(cur - 1, max(X, flr) , origx);
    return sum;
}

int main()
{
    int T;
    memset(dp, -1, sizeof(dp));
    while(cin >> T)
    {
        int x;
        while(T--)
        {
            cin >> x;
            cout << dfs(9, 0, x) << endl;
        }
    }
}
