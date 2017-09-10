#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <iostream>
typedef __int64 LL;
const int INF = 1 << 30;
using namespace std;
/*
考虑如果是的一个有向图，变成连通图，
将强联通分量缩成一个点，
然后，如果某一个联通分量和其他的联通分量没有边，那么要加两条边，如果只有一条边
那么只要加1条边
*/
const int N = 100 + 10;
int dfn[N], low[N], sccno[N], dfs_clock, cnt;
stack<int> st;
vector<int> g[N];

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++dfs_clock;
    st.push(u);
    for (int i = 0; i<g[u].size(); ++i)
    {
        int v = g[u][i];
        if (dfn[v] == 0)
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (sccno[v] == 0)//因为有向图存在横插边，不能用横插边来更新low[u]
        {
            low[u] = min(low[u], low[v]);
        }
    }
    //同样，因为强连通分量可以分布在根结点的两个分支上，所以在递归返回的时候调用
    if (low[u] == dfn[u])
    {
        cnt++;
        for (;;)
        {
            int x = st.top();
            st.pop();
            sccno[x] = cnt;
            if (x == u)
                break;
        }
    }
}
bool in[N], out[N];
int main()
{

    int n;
    while (scanf("%d", &n) != EOF)
    {
        dfs_clock = cnt = 0;
        while (!st.empty()) st.pop();
        for (int i = 1;i <= n;++i)
        {
            sccno[i] = 0;
            g[i].clear();
            low[i] = dfn[i] = 0;
            in[i] = out[i] = false;
        }
        for (int i = 1;i <= n;++i)
        {
            int u = i, v;
            while (scanf("%d", &v), v)
                g[u].push_back(v);
        }
        for (int i = 1;i <= n;++i)
        {
            if (dfn[i] == 0)
                tarjan(i, -1);
        }
        for (int i = 1;i <= n;++i)
        {
            for (int j = 0;j < g[i].size();++j)
            {
                int v = g[i][j];
                if (sccno[i] == sccno[v]) continue;
                out[sccno[i]] = true;
                in[sccno[v]] = true;
            }
        }
        if (cnt == 1)
        {
            printf("0\n");
            continue;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1;i <= cnt;++i)
        {
            if (!in[i]) cnt1++;
            if (!out[i]) cnt2++;
        }
        printf("%d\n", cnt1);
        printf("%d\n", max(cnt1, cnt2));
    }
    return 0;
}
