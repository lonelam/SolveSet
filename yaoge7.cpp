// ybmj
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 1e5 + 5;
int val[maxn];
int par[maxn];
int find(int x) {
    if (par[x] == x) return x;
    int temp = find(par[x]);
    val[x] += val[par[x]];
    return par[x] = temp;
}
bool unite(int l, int r, int w) {
    int fl = find(l);
    int fr = find(r);
    if (fl == fr) {
        if (val[r] - val[l] == w)
            return true;
        else
            return false;
    } else {
        par[fr] = fl;
        val[fr] = val[l] + w - val[r];
    }
    return true;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        bool flag = true;
        for (int i = 0; i <= n; i++) par[i] = i, val[i] = 0;
        for (int i = 0; i < m; i++) {
            int l, r, w;
            cin >> l >> r >> w;
            l--;
            if (flag == false) continue;
            flag = unite(l, r, w);
        }
        if (flag)
            cout << "Unknown!" << '\n';
        else
            cout << "Error!" << '\n';
    }
}
