#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
const int maxb = 1000;
struct node
{
    int rm[5][5];
    node()
    {
        memset(rm, inf, sizeof(rm));
    }
};
node operator+(node lhs, node rhs)
{
    node ans;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            for (int k = i; k <= j; k++)
            {
                ans.rm[i][j] = min(ans.rm[i][j] , lhs.rm[i][k] + rhs.rm[k][j]);
            }
        }
    }
    return ans;
}
node ns[maxn];
node Bs[maxb];
int bsize, bnum, n;
int belong[maxn];
int L[maxb], R[maxb];
char s[maxn];
void build()
{
    bsize = sqrt(n);
    bnum = n / bsize;
    if (n % bsize) bnum++;
    for (int i = 0; i < bnum; i++)
    {
        L[i] = i * bsize;
        R[i]  = (i + 1) * bsize;
    }
    R[bnum - 1] = n;
    for (int i = 0; i < n; i++)
    {
        belong[i] = i / bsize;
        for (int j = 0; j < 5; j++)
        {
            ns[i].rm[j][j] = 0;
        }
        if (s[i] == '2')
        {
            ns[i].rm[0][0] = 1;
            ns[i].rm[0][1] = 0;
        }
        else if (s[i] == '0')
        {
            ns[i].rm[1][1] = 1;
            ns[i].rm[1][2] = 0;
        }
        else if (s[i] == '1')
        {
            ns[i].rm[2][2] = 1;
            ns[i].rm[2][3] = 0;
        }
        else if (s[i] == '7')
        {
            ns[i].rm[3][3] = 1;
            ns[i].rm[3][4] = 0;
        }
        else if (s[i] == '6')
        {
            ns[i].rm[3][3] = ns[i].rm[4][4] = 1;
        }
    }
    for (int i = 0; i < bnum; i++)
    {
        memset(Bs[i].rm, inf, sizeof(Bs[i].rm));
        for (int j = 0; j < 5; j++)
        {
            Bs[i].rm[j][j] = 0;
        }
        for (int j = L[i]; j < R[i]; j++)
        {
            Bs[i] = Bs[i] + ns[j];
        }
    }
}
int query(int l, int r)
{
    node ans;
    for (int i = 0; i < 5; i++)
    {
        ans.rm[i][i] = 0;
    }
    if (belong[l] == belong[r])
    {
        for (int i = l; i <= r; i++)
        {
            ans = ans + ns[i];
        }
        return ans.rm[0][4];
    }
    for (int i = l; i < R[belong[l]]; i++)
    {
        ans = ans + ns[i];
    }
    for (int i = belong[l] + 1; i < belong[r]; i++)
    {
        ans = ans + Bs[i];
    }
    for (int i = L[belong[r]]; i <= r; i++)
    {
        ans = ans + ns[i];
    }
    return ans.rm[0][4];
}

int main()
{
    int q;
    while(scanf("%d%d",&n, &q)!=EOF)
    {
        scanf("%s", s);
        build();
        int l, r;
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d",&l,&r);
            int ans = query(l - 1, r - 1);
            if (ans == inf) ans = -1;
            printf("%d\n", ans);
        }
    }
}
