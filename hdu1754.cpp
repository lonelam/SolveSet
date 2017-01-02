#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000;
const int maxb = 1000;
int belong[maxn];
int n, bsize, bnum;
int L[maxb], R[maxb];
int M[maxb];
int m[maxn];
void build()
{
    bsize = sqrt(n);
    bnum = n / bsize;
    if (n % bsize) bnum++;
    for (int i = 0; i < bnum; i++)
    {
        L[i] = i * bsize;
        R[i] = (i + 1) * bsize;
        M[i] = 0;
        for (int j = L[i]; j < R[i]; j++)
        {
            M[i] = max(M[i], m[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        belong[i] = i / bsize;
    }
}
void update(int i, int score)
{
    m[i] = score;
    M[belong[i]] = 0;
    for (int k = L[belong[i]]; k < R[belong[i]]; k++)
    {
        M[belong[i]] = max(M[belong[i]], m[k]);
    }
}
int query(int i, int j)
{
    if (belong[i] == belong[j])
    {
        int ans = 0;
        for (int k = i; k <= j; k++)
        {
            ans = max(ans, m[k]);
        }
        return ans;
    }
    int ans = 0;
    for (int k = i; k < R[belong[i]]; k++)
    {
        ans = max(ans, m[k]);
    }
    for (int k = belong[i] + 1; k < belong[j]; k++)
    {
        ans = max(ans, M[k]);
    }
    for (int k = L[belong[j]]; k <= j; k++)
    {
        ans = max(ans, m[k]);
    }
    return ans;

}
int main()
{
    int mm;
    while(scanf("%d%d", &n, &mm)!=EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", m + i);
        }
        build();
        for (int i = 0; i < mm; i++)
        {
            int op1, op2;
            char cmd[100];
            scanf("%s%d%d", cmd, &op1, &op2);
            if (cmd[0] == 'Q')
            {
                printf("%d\n", query(op1 - 1, op2 - 1));
            }
            else if (cmd[0] == 'U')
            {
                update(op1 - 1, op2);
            }
        }

    }
}
