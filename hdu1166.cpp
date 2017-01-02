#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 100;
const int maxb = 1000 + 100;
int bsize, bnum, n;
int belong[maxn];
int L[maxb], R[maxb];
int a[maxn];
int AA[maxb];
void build()
{
    bsize = sqrt(n);
    bnum = n / bsize;
    if (n % bsize)
    {
        bnum++;
    }
    for (int i = 0; i < n; i++)
    {
        belong[i] = i / bsize;
    }
    for (int i = 0; i < bnum; i++)
    {
        L[i] = bsize * i;
        R[i] = bsize * (i + 1);
        AA[i] = 0;
        for (int j = L[i]; j < R[i]; j++)
        {
            AA[i] += a[j];
        }
    }
}
void update(int i, int adder)
{
    a[i] += adder;
    AA[belong[i]] += adder;
}
int query(int i, int j)
{
    if (belong[i] == belong[j])
    {
        int ans = 0;
        for (int k = i; k <= j; k++)
        {
            ans += a[k];
        }
        return ans;
    }
    int ans = 0;
    for (int k = i; k < R[belong[i]]; k++)
    {
        ans += a[k];
    }
    for (int k = belong[i] + 1; k < belong[j]; k++)
    {
        ans += AA[k];
    }
    for (int k = L[belong[j]]; k<= j; k++)
    {
        ans += a[k];
    }
    return ans;
}
char cmd[100];
int main()
{
    int T;
    int kase = 1;
    while(scanf("%d", &T)!= EOF)
    {
        while(T--)
        {
            scanf("%d", &n);
        //    string cmd;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", a + i);
            }
            build();
            printf("Case %d:\n", kase++);
            while(scanf(
                "%s", cmd
            )!= EOF && strcmp(cmd, "End") != 0)
            {
                int op1, op2;
                scanf("%d%d", &op1, &op2);
                if (strcmp(cmd, "Add") == 0)
                {
                    update(op1 - 1, op2);
                }
                else if (strcmp(cmd, "Sub") == 0)
                {
                    update(op1 - 1, -op2);
                }
                else if (strcmp(cmd , "Query") == 0)
                {
                    printf("%d\n", query(op1 - 1, op2 - 1));
                }
            }
        }
    }
}
