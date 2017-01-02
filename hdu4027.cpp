#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000+100;
const int maxb = 1000;
ll endur[maxn];
bool allone[maxb];
int belong[maxn];
ld sum[maxb];
int L[maxb], R[maxb];
int n, bsize, bnum;
void debug()
{
    for (int i = 0; i < n; i++)
    {
        cout << endur[i] << " ";
    }
    cout << endl;
}
void build()
{
    bsize = sqrt((ld)n);
    bnum = n / bsize;
    if (n % bsize) bnum++;
    for (int i = 0; i < bnum; i++)
    {
        L[i] = bsize * i;
        R[i] = (i + 1) * bsize;
        allone[i] = false;
        sum[i] = 0;
    }
    R[bnum - 1] = n;
    for (int i = 0; i < n; i++)
    {
        belong[i] = i / bsize;
        sum[belong[i]] += endur[i];
    }
}

void pushdown(int bno)
{
    if (allone[bno])
    return;
    sum[bno] = 0;
    bool oneone = true;
    for (int i = L[bno]; i < R[bno]; i++)
    {
    //    sum[belong[i]] -= endur[i];
        endur[i] = sqrt((ld)endur[i]);
        sum[bno] += endur[i];
        if (endur[i] != 1)
        {
            oneone = false;
        }
    }
    if (oneone)
    {
        allone[bno]=true;
    }
}

void update(int l, int r)
{
    if (belong[l] == belong[r])
    {
        if (allone[belong[l]])
        {
            return;
        }
        for (int i = l; i <= r; i++)
        {
            sum[belong[i]] -= endur[i];
            endur[i] = sqrt((ld)endur[i]);
            sum[belong[i]] += endur[i];
        }
        return;
    }
    //cout << "debug";
    if (!allone[belong[l]])
    {
        for (int i = l; i < R[belong[l]]; i++)
        {
            sum[belong[i]] -= endur[i];
            endur[i] = sqrt((ld)endur[i]);
    //        cout << i << endl;
            sum[belong[i]] += endur[i];
        }
    }
    for (int i = belong[l] + 1; i < belong[r]; i++)
    {
            pushdown(i);
        //    cout << "debug\n";
    }
    if (!allone[belong[r]])
    {
        for (int i = L[belong[r]]; i <= r; i++)
        {
            sum[belong[i]] -= endur[i];
            endur[i] = sqrt((ld)endur[i]);
            sum[belong[i]] += endur[i];
//            cout << i << endl;
        }
    }
}

ll query(int l, int r)
{
    ld ans = 0;
    if (belong[l] == belong[r])
    {
        for (int i = l; i <= r; i++)
        {
            ans += endur[i];
        }
        return ans;
    }
    for (int i = l; i < R[belong[l]]; i++)
    {
        ans += endur[i];
    }
    for (int i = belong[l] + 1; i < belong[r]; i ++)
    {
        ans += sum[i];
    }
    for (int i = L[belong[r]]; i <= r; i++)
    {
        ans += endur[i];
    }
    return ans;
}
int main()
{
    int kase = 1;
    while(scanf("%d", &n)!= EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", endur + i);
        }
        printf("Case #%d:\n", kase++);
    //    char cmd[100];
        int q, cmd, x, y;

        build();
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d%d", &cmd,&x,&y);
            if (x > y)
            {
                swap(x, y);
            }
            if (cmd == 0)
            {
                update(x - 1, y - 1);
            //    debug();
            }
            else
            {

                printf("%lld\n", query(x - 1, y - 1));
            }
        }
        printf("\n");
    }
}
