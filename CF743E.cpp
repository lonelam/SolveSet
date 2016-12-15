#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
bool vis[10];
int a[1000 + 10];
int n;
int ans;
int dp1[8][1010][1010];
bool dfs(int rem, int x, int p, int ccc, int cl = -1)
{
    bool xok = false;
    if (cl != -1)
    {
        if (dp1[cl][p][x] != -1)
        {
            p = dp1[cl][p][x];
        }
        else
        {
            return false;
        }
        if (rem == 0)
        {
            ans = max(ans, ccc);
            xok = true;
        }
    }

    for (int i = 1; i <= 8; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
       //     cout << "push\t"<< i <<endl;
            xok = dfs(rem - 1, x, p, ccc + x, i) || xok;

            vis[i] = false;
        }
    }
    if (cl == -1)
        return xok;
    if (dp1[cl][p][1] != -1)
    {
        p = dp1[cl][p][1];
    }
    else return xok;
    if (rem == 0)
    {
        ans = max(ans, ccc + x + 1);
        return true;
    }
    for (int i = 1; i <= 8; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            xok = dfs(rem - 1, x, p, ccc + x + 1, i) || xok;
            vis[i] = false;
        }
    }
    return xok;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        memset(dp1, -1, sizeof(dp1));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int k = 1; k <= 8; k++)
            {
                dp1[k][i][0] = i;
                int j = i + 1;
                int cnt = 1;
                while (dp1[k][i + 1][cnt] != -1)
                {
                    dp1[k][i][cnt] = dp1[k][i + 1][cnt];
                    if (k == a[i])
                    {
                        dp1[k][i][cnt + 1] = dp1[k][i + 1][cnt];
                    }
                    cnt++;
                }
            }
            dp1[a[i]][i][1] = i + 1;
        }
        ans = 0;
        memset(vis, 0, sizeof(vis));
        int l = 0, r = n / 8 + 2;
        while(l + 1 < r)
        {
            const int mid = l + (r - l)/ 2;
            if (dfs(8, mid, 0, 0))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        dfs(8, l, 0, 0);
     //   if (l != 0) dfs(8, l - 1, 0, 0);
        cout << ans <<endl;
    }
	return 0;
}
