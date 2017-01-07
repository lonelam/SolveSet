#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 1000;
int li[maxn], ri[maxn];
int cnt[maxn * 4];
int disc[maxn * 2];
int n, k;
int dn;
void init()
{
    dn = 0;
    for (int i = 0; i < n; i++)
    {
        disc[dn++] = li[i] * 2 + 1;
        disc[dn++] = ri[i] * 2;
    }
    sort(disc, disc + dn);
    dn = unique(disc, disc + dn) - disc;
    memset(cnt, 0, sizeof(cnt));
}
int lsb(int x)
{
    return x & (-x);
}
void add(int x, int val)
{
    x++;
    while(x <= dn)
    {
        cnt[x] += val;
        x += lsb(x);
    }
}

int sum(int x)
{
    x++;
    int ret = 0;
    while(x > 0)
    {
        ret += cnt[x];
        x -= lsb(x);
    }
    return ret;
}
void solve()
{
    cout << "degb";
    init();
    cout <<"deb";
    for (int i = 0; i < n;i ++)
    {
        int lpos = lower_bound(disc, disc + dn, li[i] * 2 + 1) - disc;
        int rpos = lower_bound(disc, disc + dn, ri[i] * 2  ) - disc;
        add(rpos, 1);
        add(lpos - 1, -1);
    }
    int pre = 0;
    int ansL = 0;
    int ansR = 0;
    int ans = 0;
    for (int i = 0; i < dn; i++)
    {
        int tt = sum(i) - sum(i - 1);
        if (tt < k && pre != i )
        {
            int len = disc[i-1] / 2 - disc[pre] / 2+1;
            if (len > ans)
            {
                ans = len;
                ansL = disc[pre] / 2;
                ansR = disc[i - 1] / 2;
            }
        }
        if (tt < k)
        {
            pre = i+1;
        }
    }
    if (pre != dn)
    {
        int len = disc[dn - 1] / 2 - disc[pre] / 2 + 1;
        if (len > ans)
        {
            ans = len;
            ansL = disc[pre] / 2;
            ansR = disc[dn - 1] / 2;
        }
    }
    if (ans == 0)
    {
        printf("0\n");
        for (int i = 1; i < k; i++)
        {
            printf("%d ", i);
        }
        printf("%d\n",k);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (li[i] <= ansL && ansR <= ri[i])
            {
                k--;
                printf("%d%c", i + 1, k?' ':'\n');
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
    //    cout << n << endl;
        for (int j = 0; j < n; j++)
        {
        //    cout <<"debug";
        cout << n << endl;
        scanf("%d%d", li + j, ri+j);
            //cin >> li[j] >> ri[j];
        }
        cout << "deubg";
        solve();
    }
}
