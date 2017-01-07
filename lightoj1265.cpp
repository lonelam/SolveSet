#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 50;
ld dp[maxn][maxn];
int main()
{
    int T;
    dp[0][0] = 1;

    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            if (i == 0 && j == 0) continue;
            ld tot = i + j + 1;
            ld poss1 = 0;
            ld poss2 = 0;
            if (i > 1)
            {
                poss2 += (ld)i * (i - 1) * dp[i - 2][j];
                poss1 += (ld)i *(i - 1) * dp[i - 2][j];
            }
            if (j > 0)
            {
                poss2 += 2 * i * j * dp[i][j - 1];
                poss1 +=  2 * (i * j + j) * dp[i][j - 1];
            }
            poss1 /= (tot * (tot - 1) - j * (j - 1));
            poss2 /= (tot * (tot - 1) - j * ( j - 1) - 2 * j);
            dp[i][j] = max(poss1, poss2);
        }
    }
    cout.precision(10);
    cout.setf(cout.fixed);
    int kase = 1;
    while(cin >> T)
    {
        int t, d;
        while(T--)
        {
            cin >> t >> d;
            cout <<"Case "<<kase++<<": "<< dp[t][d] << endl;
        }
    }
}
