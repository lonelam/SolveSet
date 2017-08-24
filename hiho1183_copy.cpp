#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e4 + 7;
// head

int n, m, order = 0;
int low[MAXN], dfn[MAXN];
int par[MAXN], son[MAXN];
VI G[MAXN];
VI cutpoint;
vector<PII> cutedge;

void tarjan(int u) {
    dfn[u] = low[u] = ++order;
    bool flag = false;
    rep(i, 0, G[u].size()) {
        int v = G[u][i];
        if (!dfn[v]) {
            son[u]++;
            par[v] = u;
            tarjan(v);
            if (low[v] >= dfn[u]) flag = true;
            if (low[v] > dfn[u]) cutedge.pb(mp(min(v, u), max(v, u)));
            low[u] = min(low[u], low[v]);
        }
        else if (v != par[u]) low[u] = min(low[u], dfn[v]);
    }
    if ((par[u] == 0 && son[u] > 1) || (par[u] && flag)) cutpoint.pb(u);
}

int main()
{
    cin >> n >> m;
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    tarjan(1);
    sort(cutedge.begin(), cutedge.end());
    sort(cutpoint.begin(), cutpoint.end());
    if (cutpoint.size() == 0) cout << "Null" << endl;
    else {
        cout << cutpoint[0];
        rep(i, 1, cutpoint.size()) printf(" %d", cutpoint[i]);
        cout << endl;
    }
    rep(i, 0, cutedge.size())
        printf("%d %d\n", cutedge[i].first, cutedge[i].second);
    return 0;
}
