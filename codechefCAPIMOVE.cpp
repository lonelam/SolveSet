#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 1000;
int mall[maxn];
int mex[maxn];
int P[maxn];
int ans[maxn];
vector<int> G[maxn];
void add(int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
int dfs1(int u = 1, int p = -1)
{
//    mall[u] = P[u];
    mex[u] = 0;
    for (int i = 0; i < G[u].size(); i++)
    {
        if (G[u][i] != p)
        {
            int tmp = dfs1(G[u][i], u);
    //        cout << u <<" "<< G[u][i] << " "<< tmp << endl;
            if (P[mex[u]] < P[tmp])
            {
                mex[u] = tmp;
            }
        }
    //        mex[u] = max(mex[u], dfs1(G[u][i], u));
    }
    if (P[u] > P[mex[u]])
    {
        mall[u] = u;
    }
    else
    {
        mall[u] = mex[u];
    }
//    mall[u] = max(P[u], mex[u]);
    return mall[u];
}

void dfs2(int u = 1, int p = -1, int mee = 0)
{
    int em = 0, am = 0, eem = 0;
//    cout << u <<"  mee= "<< mee << endl;
    for (int i = 0; i < G[u].size(); i ++)
    {
        if (G[u][i] != p)
        {
            if (P[mex[am]] < P[mex[G[u][i]]])
            {
            //    em = am;
                am = G[u][i];
            }
            if (P[mall[em]] < P[mall[G[u][i]]])
            {
                eem = em;
                em = G[u][i];
            }
            else if (P[mall[eem]] < P[mall[G[u][i]]])
            {
                eem = G[u][i];
            }
        }
    }
//am/em是用来求ans的
    ans[u] = mee;
    if (P[ans[u]] < P[mex[am]])
    {
        ans[u] = mex[am];
    }
    //nexmee应该考虑进所有子结点自身
    for (int i = 0; i < G[u].size(); i++)
    {
        if (G[u][i] != p)
        {
            if (G[u][i] != em)
            {
                int nexmee = mall[em];

                if (p != -1 && P[nexmee] < P[p])
                {
                    nexmee = p;
                }
                if (P[nexmee] < P[mee])
                {
                    nexmee = mee;
                }
                dfs2(G[u][i], u, nexmee);
            }
            else
            {
                int nexmee = mall[eem];

                if (p != -1 && P[nexmee] < P[p])
                {
                    nexmee = p;
                }
                if (P[nexmee] < P[mee])
                {
                    nexmee = mee;
                }
                dfs2(G[u][i], u, nexmee);
            }
        }
    }
}

int main()
{
    int T;
    int n;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            memset(P, 0, sizeof(P));
            memset(mall, 0, sizeof(mall));
            memset(mex, 0, sizeof(mex));
            memset(ans, 0, sizeof(ans));
        //    P[0] = 0;
        //ans,m     mex[0] = 0;
            scanf("%d",&n);
            for (int i = 0; i <= n; i++)
            {
                G[i].clear();
            }
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", P + i);
        //        cout << P[i] <<"  ";
            }
        //    cout << endl;
            int u, v;
            for (int i = 1; i < n; i++)
            {
                scanf("%d%d",&u,&v);
                add(u,v);
            }
            dfs1();
            dfs2();
//            for (int i = 0; i <= n; i++)
//            {
//                cout << mex[i] <<" ";
//            }
//            cout << endl;
            for (int i = 1; i < n; i++)
            {
                printf("%d ", ans[i]);
            }
            printf("%d\n", ans[n]);
        }
    }
}
