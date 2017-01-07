#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
const int maxk = 2000000;
struct Query
{
    int L, R, id;
} node[maxn];

int cnt[maxk];
int a[maxn];
int L, R;
int k;
int pos[maxn];
ll sum;
ll ans[maxn];
void add(int pos)
{
    sum += cnt[k ^ a[pos]];
    cnt[a[pos]]++;

}
void del(int pos)
{
    cnt[a[pos]]--;
    sum -= cnt[k ^ a[pos]];

}
bool cmp(const Query & a,const  Query & b)
{
    if (pos[a.L] != pos[b.L]) return pos[a.L] < pos[b.L];
    return a.R < b.R;
}
int main()
{
    int n, m;
    //ios::sync_with_stdio(false);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int sz = sqrt(n);
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
            a[i] = a[i] ^ a[i - 1];
            pos[i] = i / sz;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &node[i].L, &node[i].R);
            node[i].L--;
            node[i].id = i;
        }
        sort(node, node + m, cmp);
        L = 1;
        R = 0;
        sum = 0;
        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < m; i++)
        {
            while(L < node[i].L)
            {
                del(L);
                L++;
            }
            while(L > node[i].L)
            {
                L--;
                add(L);
            }
            while(R < node[i].R)
            {
                R++;
                add(R);
            }
            while(R > node[i].R)
            {
                del(R);
                R--;
            }
            ans[node[i].id] = sum;
        }
        for (int i = 0; i < m; i++)
        {
            printf("%lld\n", ans[i]);
        //    cout << ans[i] << endl;
        }
    }
}
