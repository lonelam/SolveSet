#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000+ 500;
const int bmaxn = 1000;
ll Max[maxn];
ll n, q;
int bnum, bsize;
int belong[maxn];
int L[bmaxn], R[bmaxn];
ll Bmax[bmaxn];

void build()
{
    n++;
    bsize = sqrt(n);
    bnum = n / bsize;
    if (n % bsize) bnum++;
    for (int i = 0; i < bnum; i++)
    {
        L[i] = i * bsize;
        R[i] = (i + 1) * bsize;
    }
    R[bnum - 1] = n;
    for (int i = 0; i < n; i++)
    {
        belong[i] = i / block;
    }
}

int main()
{
    while(scanf("%d%d", &n, &q)!=EOF)
    {
        int cmd;
        ll op1, op2;
        build();
        for (int i = 0; i < q; i++)
        {
            scanf("%d%lld%lld", &cmd, &op1, &op2);
            if (cmd == 1)
            {
                Max[op1] += op2;
                Bmax[belong[op1]] = max(Bmax[belong[op1]], Max[op1]);
            }
            else if (cmd == 2)
            {
                ll = ans;
                if (belong[op1] == belong[op2])
                {
                    for (int i = op1; i <= op2; i++)
                    {
                        ans = max(ans, max)
                    }
                }
            }
        }
    }
}
