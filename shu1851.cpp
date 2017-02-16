#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int a[maxn];
int BIT[maxn];
int bsize, bnum, belong[maxn], n, q;
int b[maxn];
map<int, int> disc;
void init()
{
    bsize = sqrt(n);
    bnum = n / bsize;
    if (n % bsize) bnum ++;
    for (int i = 0; i < n; i++)
    {
        belong[i] =  i / bsize;
    }
    disc.clear();
    memset(BIT, 0, sizeof(BIT));
}
int lsb(int x)
{
    return x & (-x);
}
void add(int x, int d)
{
    while(x <= n)
    {
        BIT[x]+= d;
        x += lsb(x);
    }
}
int sum(int x)
{
    int ret = 0;
    while(x > 0)
    {
        ret += BIT[x];
        x -= lsb(x);
    }
    return ret;
}
struct node
{
    int L, R, id, ans;
    bool operator< (const node & rhs) const
    {
        if (belong[L] != belong[rhs.L]) return belong[L] < belong[rhs.L];
        return belong[R] < belong[rhs.R];
    }
} ns[maxn];

int query[maxn];
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        init();
        for (int i = 0; i < n;i++)
        {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(b, b+ n);
        for (int i = 0; i < n; i++)
        {
            disc[b[i]] = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            a[i] = disc[a[i]];
        }
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &ns[i].L, &ns[i].R);
            ns[i].L--;
            ns[i].R--;
            ns[i].id = i;
        }
        sort(ns, ns + q);
        multiset<int> st;
        int l = 0, r = -1;
        int ans = 0;
        for (int i = 0; i < q; i++)
        {
            query[ns[i].id] = i;
        //    cout << "** "<< ns[i].id <<" "<< ns[i].L<< " "<< ns[i].R<< " now: "<< l <<" "<< r << endl;
            while(r < ns[i].R)
            {
                r++;
                //st.insert(a[r]);
                add(a[r], 1);
                //ans += distance(st.upper_bound(a[r]), st.end());
                ans += r - l + 1 - sum(a[r]);
            }
            while(r > ns[i].R)
            {
                ans -= r - l + 1- sum(a[r]);
                //ans -= distance(st.upper_bound(a[r]), st.end());
                //st.erase(st.find(a[r]));
                add(a[r], -1);
                r--;
            }
            while(l > ns[i].L)
            {
                l--;
                //st.insert(a[l]);
                add(a[l], 1);
                ans += sum(a[l] - 1);
                //ans += distance(st.begin(), st.lower_bound(a[l]));
            }
            while(l < ns[i].L)
            {
                add(a[l], -1);
                //st.erase(st.find(a[l]));
                ans -= sum(a[l] - 1);
                //ans -= distance(st.begin(), st.lower_bound(a[l]));
                l++;
            }
            ns[i].ans = ans;
        }
        for (int i = 0; i < q; i++)
        {
            printf("%d\n", ns[query[i]].ans);
        }
    }
}
