/*************************************************************************
	> File Name: cf744.cpp
	> Author: Lonelam
	> Mail: laizenan@gmail.com
	> Created Time: 2016年12月28日 星期三 00时35分18秒
 ************************************************************************/

#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<sstream>
#include<utility>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#include<iostream>
const int inf = 0x3f3f3f3f;
const int maxS = 1 << 17;
int dp[maxS][200];
int ri[100];
int bi[100];
string ci[100];
int main()
{
    int n;
    while(cin >> n)
    {
        int ans = 0;
        int cntr = 0;
        int cntb = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> ci[i] >> ri[i] >> bi[i] ;
            cntr+= ri[i];
            cntb += bi[i];
        }
        int mS = 1 << n;
        memset(dp, -1 , sizeof(dp));
        dp[0][0] = 0;
        for (int st = 0; st < mS ; st++)
        {
            int cntA = 0;
            int cntB = 0;
            for (int i = 0; i < n; i++)
            {
                if ((st >> i) & 1)
                {
                    if (ci[i][0] == 'R')
                    {
                        cntA++;
                    }
                    else
                    {
                        cntB++;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                if ((st >> i) & 1)
                {
                    if (ci[i][0] == 'R')
                    {
                        cntA--;
                    }
                    else
                        cntB--;
                    int cutA =  min(ri[i], cntA);
                    int cutB =  min(bi[i], cntB);
                    
                    if (ci[i][0] == 'R')
                    {
                        cntA++;
                    }
                    else cntB++;
                    for (int j = cutA; j < 200; j++)
                    {
                        if (dp[st - (1 << i)][j - cutA] == -1)
                        {
                            continue;
                        }
                        dp[st][j] = max(dp[st][j], dp[st - (1 << i)][j - cutA] + cutB);
                    }
                }
            }
        }
        ans = max(cntr, cntb);

        for (int i = 0; i < 200; i++)
        {
            if (dp[mS - 1][i] == -1)
            {
                continue;
            }
            ans = min(ans, max({cntr - i, cntb - dp[mS - 1][i], 0}));
        }
        cout <<n + ans  << endl;
    }
}
