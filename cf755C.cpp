#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int fa[maxn];
int rnk[maxn];
void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        fa[i] = -1;
        rnk[i] = 1;
    }
}
int fnd(int x)
{
    if (fa[x] == -1)
    {
        return x;
    }
    return fa[x] = fnd(fa[x]);
}
void Union(int x, int y)
{
    int fx = fnd(x), fy = fnd(y);
    if (fx == fy)
    {
        return;
    }
    if (rnk[fx] == rnk[fy])
    {
        rnk[fx]++;
        fa[fy] = fx;
        return;
    }
    if (rnk[fx] > rnk[fy])
    {
        fa[fy] = fx;
    }
    else
    {
        fa[fx] = fy;
    }
}

int p[maxn];
int main()
{
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        Union(i, p[i]);
    }
    set<int> trr;
    for (int i = 1; i <= n; i++)
    {
        trr.insert(fnd(i));
    }
    cout << trr.size() << endl;
}
