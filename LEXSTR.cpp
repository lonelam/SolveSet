#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

int fa[maxn], rnk[maxn];
void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        rnk[i] = 1;
        fa[i] = -1;
    }
}
int fnd(int x)
{
    if (fa[x] != -1)
    {
        return fa[x]=fnd(fa[x]);
    }
    return x;
}

void combine(int x, int y)
{
    int fx = fnd(x);
    int fy = fnd(y);
    if (fx == fy)
    {
        return;
    }
    if (rnk[fx] == rnk[fy])
    {
        fa[fx] = fy;
        rnk[fy]++;
        return;
    }
    if (rnk[fx] < rnk[fy])
    {
        fa[fx] = fy;
    }
    else
    {
        fa[fy] = fx;
    }
}
int n,m;
char s[maxn];
vector<int> sets[maxn];
int main()
{
    int T;
    int a,b;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%s", s);
            scanf("%d", &m);
            n = strlen(s);
            init(n);
            for (int i = 0; i < m; i++)
            {
                scanf("%d%d", &a,&b);
                combine(a,b);
            }

            for (int i = 0; i < n; i++)
            {
                sets[i].clear();
            }
            for (int i = 0; i < n; i++)
            {
                sets[fnd(i)].push_back(i);
            }
            for (int i = 0; i < n; i++)
            {
                if (!sets[i].empty())
                {
                    string tmp;
                    for (int j = 0; j < sets[i].size(); j++)
                    {
                        tmp.push_back(s[sets[i][j]]);
                    }
                    sort(tmp.begin(), tmp.end());
                    for (int j = 0; j < sets[i].size(); j++)
                    {
                        s[sets[i][j]] = tmp[j];
                    }
                }
            }
            printf("%s\n", s);
        }
    }
}
