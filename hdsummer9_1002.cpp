//  BZOJ 2588 树上路径第 k 大
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#define mid (((l) + (r)) / 2)
using namespace std;

inline int ReadInt() {
    static int n, ch;
    n = 0, ch = getchar();
    if (ch == -1) return -1;
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
    return n;
}
typedef long long ll;

const int maxn = 100000 + 3;
struct SegNode *pit, *null;
vector<int> G[maxn], Ws;
struct SegNode {
    SegNode *ls, *rs;
    ll s;
    inline void maintain() {
        s = ls->s + rs->s;
    }
    SegNode(): ls(null), rs(null), s(0) {}
}pool[maxn * 18], *root[maxn];

void init() {
    pit = pool;
    null = new SegNode();
    null->ls = null, null->rs = null;
   // Ws.clear();
}

SegNode* modify(const SegNode *o, int l, int r, int v) {
    if (l >= r) return null;
    SegNode *ne = pit++;
    *ne = *o;
    if (r - l == 1)
        ne->s += Ws[v];
    else {
        if (v < mid) ne->ls = modify(ne->ls, l, mid, v);
        else ne->rs = modify(ne->rs, mid, r, v);
        ne->maintain();
     //   cout << ne->s << endl;
    }
    return ne;
}

int n, m, w[maxn], ancestor[maxn][18], depth[maxn];

void compress() {
    for (int i = 0; i < n; i++)
    {
        G[i].clear();
    }
    Ws.clear();
    for (int i = 0; i < n; ++i)
        Ws.push_back(w[i]);
    sort(Ws.begin(), Ws.end());
    Ws.erase(unique(Ws.begin(), Ws.end()), Ws.end());
    for (int i = 0; i < n; ++i)
        w[i] = lower_bound(Ws.begin(), Ws.end(), w[i]) - Ws.begin();
}

void process() {
    for (int w = 1; (1 << w) < n; ++w)
        for (int i = 0; i < n; ++i) if (depth[i] - (1 << w) >= 0)
            ancestor[i][w] = ancestor[ancestor[i][w - 1]][w - 1];
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int lim = log2(depth[a]);
    for (int i = lim; i >= 0; --i)
        if (depth[a] - (1 << i) >= depth[b])
            a = ancestor[a][i];
    if (a == b) return a;
    for (int i = lim; i >= 0; --i)
        if (depth[a] - (1 << i) >= 0 && ancestor[a][i] != ancestor[b][i]) {
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    return ancestor[a][0];
}

ll query(const SegNode *a, const SegNode *b, const SegNode *c, const SegNode *d, int l, int r, int ql, int qr) {
   // if (r - l == 1) return Ws[l];
    if (ql <= l && r <= qr)
    {
       // cout << a->ls->s + b->ls->s - c->ls->s - d->ls->s <<endl;
       // return a->ls->s + b->ls->s - c->ls->s - d->ls->s;
        return a->s + b->s - c->s - d->s;

    }
    ll s = 0;
    if (ql < mid) s += query(a->ls, b->ls, c->ls, d->ls, l, mid, ql, qr);
    if (mid < qr) s += query(a->rs, b->rs, c->rs, d->rs, mid, r, ql, qr);
    return s;
}

void dfs(const SegNode *o, int u, int fa) {
    ancestor[u][0] = fa, depth[u] = fa == -1 ? 0 : depth[fa] + 1;
    root[u] = modify(o, 0, Ws.size(), w[u]);
    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if (v != fa) dfs(root[u], v, u);
    }
}

int solve() {
    init();
    if ((n=ReadInt())== -1) return -1;
    //n = ReadInt();
    m = ReadInt();
    for (int i = 0; i < n; ++i)
        w[i] = ReadInt();
    compress();
    for (int i = 0; i < n - 1; ++i) {
        int f = ReadInt() - 1, t = ReadInt() - 1;
        G[f].push_back(t);
        G[t].push_back(f);
    }
    dfs(null, 0, -1);
    process();
    int lastAns = 0;
    while (m--) {
        int u = ReadInt() - 1, v = ReadInt() - 1, ql = ReadInt(), qr = ReadInt();// k = ReadInt();
        int lca = LCA(u, v);
        ql = lower_bound(Ws.begin(), Ws.end(),ql) - Ws.begin();
        qr = upper_bound(Ws.begin(), Ws.end(), qr) - Ws.begin();
       // cout << ql << " "<< qr <<endl;
        printf("%lld", query(root[u], root[v], root[lca], lca == 0 ? null : root[ancestor[lca][0]], 0, Ws.size(), ql, qr));
        if (m) putchar(' ');
    }
    putchar('\n');
    return 0;
}
int main()
{
    while(solve() != -1);
    return 0;
}
