#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define MAXN 300
#define OT printf
#define CLR(x, a) memset(a, x, sizeof(a));
#define REP(i, n) for(i = 1; i <= n; i++)
#define DWN(i, e, s) for(i = e; i >= s; i--)

int RD(int &x)
{
        x = 0;
        char ch = getchar();
        while(ch < '0' || ch > '9') { ch = getchar(); if(ch == EOF) return 0; }
        while(ch >= '0' && ch <= '9') { x *= 10; x += ch - '0'; ch = getchar(); }
        return 1;
}

int RD(int &x0, int &x1) { return RD(x0) + RD(x1); }

int n, m, i, tot;
int s[MAXN], dp[MAXN][MAXN][6];
char c[MAXN];
int dfs(int l, int r, int k)
{
    int &ret = dp[l][r][k];
    if(l > r) return ret = 0;
    if(~ret) return ret;
    if(l == r) return ret = max(0, m - (s[r] + k));

    ret = dfs(l, r - 1, 0) + max(0, m - (s[r] + k));
    int p;
    DWN(p, r - 1, l) if(c[p] == c[r]) ret = min(ret, dfs(l, p, min(m, s[r] + k)) + dfs(p + 1, r - 1, 0));
    return ret;
}

int solve()
{
//    freopen("ZUMA.in", "r", stdin);

    //RD(n);
    m = 3;
    //REP(i, n) RD(c[i]);
    scanf("%s", c +1);
    n = strlen(c + 1);
    CLR(0, s);
    tot = 0;
    REP(i, n)
    {
        if(c[tot] != c[i]) c[++tot] = c[i];
        s[tot]++;
    }
    n = tot;
    CLR(-1, dp);
    OT("%d\n", dfs(1, n, 0));

    return 0;
}
int kase = 1;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        printf("Case #%d: ", kase++);
        solve();
    }
}
