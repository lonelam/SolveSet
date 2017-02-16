#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
int dp[maxn];
int bi[maxn];
int wi[maxn];
int fa[maxn];
int rnk[maxn];
int gnum;
int groupno[maxn];
vector<int> groups[maxn];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        rnk[i] = 1;
        fa[i] = i;
    }
}
int fnd(int x)
{
    //cout << x << endl;
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = fnd(fa[x]);
}
void unite(int a, int b)
{
    int ffa = fnd(a);
    int ffb = fnd(b);
    if(rnk[ffa] == rnk[ffb])
    {
        rnk[ffa]++;
        fa[ffb] = ffa;
        return;
    }
    if (rnk[ffa] > rnk[ffb])
    {
        fa[ffb] = ffa;
        return;
    }
    fa[ffa] = ffb;
}
int main()
{
    int n,m,w;
    while(cin >> n >> m >> w)
    {
        init(n);
    //    cout <<"dewg";
        for (int i = 1; i <= n; i++)
        {
            cin >> wi[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> bi[i];
        }
        int xx,yy;
        //cout <<"debug";
        for (int i = 0; i < m; i++)
        {
            cin >> xx >> yy;
        //    cout << x << y;
            unite(xx,yy);
        }
        gnum = 0;
    //    cout << "debug"<<endl;
        memset(groupno,-1,sizeof(groupno));

        for (int i = 1; i <= n; i++)
        {
            int idfa = fnd(i);
            if (groupno[idfa] == -1)
            {
                groups[gnum].clear();
                groupno[idfa] = gnum++;
            }
            groups[groupno[idfa]].push_back(i);
        }
    //    cout <<"dbg"<<endl;
        memset(dp,0,sizeof(dp));
        for (int i = 0; i < gnum; i++)
        {
        //    cout << i << endl;
            for (int j = w; j>=0; j--)
            {
                int wsum = 0;
                int bsum = 0;
                for (int k = 0; k < groups[i].size(); k++)
                {
                    if (j >= wi[groups[i][k]]) dp[j] = max(dp[j], dp[j - wi[groups[i][k]]] + bi[groups[i][k]]);
                    wsum += wi[groups[i][k]];
                    bsum += bi[groups[i][k]];
                }
                if (j >= wsum) dp[j] = max(dp[j], dp[j - wsum] + bsum);
            }
        }
        cout << dp[w] << endl;
    }
}
