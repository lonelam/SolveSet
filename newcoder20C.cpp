
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define pow10 poweroften
const int maxn = 200000 +5;
int a[maxn];
int id[maxn];
typedef long long ll;
int n;
int pow10[maxn];
int cnt[maxn];
vector<int> disc;
inline int lsb(int x)
{
    return x & (-x);
}
void add(int x)
{
    x++;
    while(x <= disc.size()+1)
    {
        cnt[x]++;
        x += lsb(x);
    }
}
int query(int x)
{
    x++;
    int ret = 0;
    while(x)
    {
        ret += cnt[x];
        x -= lsb(x);
    }
    return ret;
}
__gnu_pbds::tree<pair<int,int>, __gnu_pbds::null_type, less<pair<int,int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> st;
int main()
{
    pow10[0] = 1;
    for (int i = 1; i <= 9; i++) pow10[i] = pow10[i-1] * 10;
    pow10[0] = 0;
    while(~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a+i);
        }
        ll ans = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = n-1; i >= 0; i--)
        {
            int weishu = 1;
            int tmp = a[i]/10;
            while(tmp) tmp/=10, weishu++;
            for (int k = 1; k <= 9; k++)
            {
                //ans += abs(weishu - k) * (query(lower_bound(disc.begin(), disc.end(), pow10[k] - a[i]) - disc.begin() - 1)
                                  //         - query(upper_bound(disc.begin(), disc.end(), pow10[k-1] - a[i] - 1) - disc.begin() - 1));
                ans += abs(weishu - k) * (st.order_of_key({pow10[k] - a[i], -1}) - st.order_of_key({pow10[k-1] - a[i], -1}));
            }
            st.insert({a[i], i});
        }
        printf("%lld\n", ans);

    }
}
