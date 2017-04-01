#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

class CheeseSlicing
{
public:
    CheeseSlicing() {}
    static int dp[101][101][101];
    int totalArea(int A, int B, int C, int S)
    {
        memset(dp, 0, sizeof(dp));
        if (A > B) swap(A, B);
        if (A > C) swap(A, C);
        if (B > C) swap(B, C);
        for (int i = S; i <= A; i++)
        {
            for (int j = i; j <= B; j++)
            {
                for (int k = j; k <= C; k++)
                {
                    if (i >= S)
                    {
                        dp[i][j][k] = j * k;
                    }
                    for (int cut = S; cut < i - S; cut++)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[cut][j][k] + dp[i - cut][j][k]);
                    }
                    for (int cut = S; cut < j - S; cut++)
                    {
                        int a = min(i, cut);
                        int b = max(i, cut);
                        int c = min(i, j - cut);
                        int d = max(i, j - cut);
                        dp[i][j][k] = max(dp[i][j][k], dp[a][b][k] + dp[c][d][k]);
                    }
                    for (int cut = S; cut < k - S; cut++)
                    {
                        int a = min(i, cut);
                        int c = max(cut, j);
                        int b = i + cut + j - a - c;
                        int d = min(i, k - cut);
                        int f = max(j, k - cut);
                        int e = i + j + k - cut - d - f;
                        dp[i][j][k] = max(dp[a][b][c] + dp[d][e][f], dp[i][j][k]);
                    }
                }
            }
        }
        return dp[A][B][C];
    }
};
