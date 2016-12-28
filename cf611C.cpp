/*************************************************************************
	> File Name: cf611C.cpp
	> Author: Lonelam
	> Mail: laizenan@gmail.com
	> Created Time: 2016年12月28日 星期三 18时44分03秒
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
const int maxn = 505;
int rowdom[maxn][maxn], coldom[maxn][maxn];
char grid[maxn][maxn];
int main()
{
    int h, w;
    scanf("%d%d",&h,&w);
    for (int i = 1; i <= h; i++)
    {
        scanf("%s", grid[i] + 1);
    }
    int q;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            rowdom[i][j] = rowdom[i - 1][j];
            coldom[i][j] = coldom[i][j - 1];
            if (grid[i][j] == '.') 
            {
                if (grid[i - 1][j] == '.')
                {
                    rowdom[i][j] += 1;
                }
                if (grid[i][j - 1] == '.')
                {
                    coldom[i][j] += 1;
                }
            }
        }
    }
    scanf("%d", &q);
    while(q--)
    {
        int l,u,r,d;
        scanf("%d%d%d%d",&u,&l,&d,&r);
        int ans = 0;
        for (int i = u; i <= d; i++)
        {
            ans += coldom[i][r] - coldom[i][l];
        }
        for (int i = l; i <= r; i++)
        {
            ans += rowdom[d][i] - rowdom[u][i];
        }
        printf("%d\n", ans);
    }
}
