#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const int maxb = 1000;
const ll moder = 777777777;
int lucked[3][3];
int n;
ll dp[maxn * 4][3][3];
int digit[maxn];

void pushup(int rt)
{

    const int lson = rt << 1 ;
    const int rson = rt << 1 | 1;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            dp[rt][x][y] = 0;
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    if (lucked[a][b])
                    {
            //            cout <<dp[lson][x][a] <<" "<< dp[rson][b][y] << endl;
                        dp[rt][x][y] = (dp[rt][x][y] + dp[lson][x][a] * dp[rson][b][y]) % moder;
                    }
                }
            }
    //        cout << dp[rt][x][y] <<" ";
        }
//        cout << endl;
    }
}
void build(int l = 1, int r = n, int rt = 1)
{
    if (l > r)
    {
        return;
    }
//    cout << l << " "<< r << endl;
    if (l == r)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) dp[rt][i][j] = 0;
        }
        for (int i = 0; i < 3; i++)
            dp[rt][i][i] = 1;
        return;
    }
    const int mid = (l + r) / 2;
    build(l, mid, rt << 1 );
    build(mid + 1, r, rt << 1 | 1);
//    cout << mid << endl;
    pushup(rt);
}
/*
unit query(int L, int R, int l = 1, int r = n, int rt = 1)
{
    unit ans;
    if (L <= l && r <= R)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ans.a[i][j] = dp[rt][i][j];
            }
        }
        return ans;
    }
    const int mid = (l + r) / 2;
    unit lhs, rhs;
    if(mid )
}*/

void update(int tar, int l = 1, int r = n, int rt = 1)
{
    if (l > r) return;
    if (l == r)
    {
    //    cout <<  digit[tar]<< endl;
        if (digit[tar] == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                dp[rt][i][i] = 1;
            }
        }
        else
        {
            for (int i = 0;  i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    dp[rt][i][j] = 0;
                }
            }
            dp[rt][digit[tar] - 1][digit[tar] - 1] = 1;
        }
        return;
    }
    const int mid = (l + r) / 2;
    if (tar > mid)
    {
        update(tar, mid + 1, r, rt << 1 | 1);
    }
    else
    {
        update(tar, l, mid, rt << 1);
    }
//    cout << mid << endl;
    pushup(rt);
}
int pos, ti, m;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", lucked[i] + j);
            }
        }
        memset(dp, 0, sizeof(dp));
        build();

        memset(digit, 0, sizeof(digit));

        while(m--)
        {
            scanf("%d%d", &pos, &ti);
            digit[pos] = ti;
            update(pos);
            ll sum = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                //    cout << dp[1][i][j] <<" ";
                    sum = (sum + dp[1][i][j]) % moder;
                }
        //        cout << endl;
            }
            printf("%lld\n", sum);
        }
    }
}
