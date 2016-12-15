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
bool dfs(int rem, int x, int p, int ccc, int cl = -1)
{
    int cnt = 0;
    bool xok = false;
    if (cl != -1)
    {
        for (; p < n && cnt < x; p++)
        {
            if (a[p] == cl)
            {
                cnt++;
            }
        }
        if (cnt != x)
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
            xok = dfs(rem - 1, x, p, ccc + cnt, i) || xok;

            vis[i] = false;
        }
    }
    if (cl == -1)
        return xok;
    for (; p < n && cnt < x + 1; p++)
    {
        if (a[p] == cl)
            cnt++;
    }
    if (cnt != x +1) return xok;
    if (rem == 0)
    {
        ans = max(ans, cnt + ccc);
        return true;
    }
    for (int i = 1; i <= 8; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            xok = dfs(rem - 1, x, p, ccc + cnt, i) || xok;
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
        if (l != 0) dfs(8, l - 1, 0, 0);
        cout << ans <<endl;
    }
	return 0;
}
