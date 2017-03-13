#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

ll a[maxn];
ll sum[maxn];
ll BIT[maxn];
ll disc[maxn];
ll cnt[maxn];
int n;

int lsb(int x)
{
    return x & (-x);
}
void add(int x)
{
    while(x <= n)
    {
        BIT[x] ++;
        x += lsb(x);
    }
}
int query(int x)
{
    int ret = 0;
    while(x)
    {
        ret += BIT[x];
        x -= lsb(x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;

    while(cin >> n >> k)
    {
    //    ll sum = 0;
        ll UP = 0;
        for (int i = 0; i < n; i++)
        {

            cin >> a[i];
            UP += abs(a[i]);
            if (i != 0)
            sum[i] = sum[i - 1] + a[i];
            else
            {
                sum[i] = a[i];
            }
            disc[i] = sum[i];

        }
        sort(disc, disc + n);
        map<ll,ll> dd;

        for (int i = 0; i < n; i++)
        {
            dd[disc[i]] = i + 1;
        }
        dd[0] = n + 1;
        //int l = 0, r= 0;
        ll pk = 1, tot = 0;

        ll ans = 0;
        set<int> allkp;
        if (k == 1) allkp = {1};
        else if(k == -1) allkp = {-1, 1};
        else
        {
            while(abs(pk) <= UP)
            {
                allkp.insert(pk);
                pk *= k;
            }

        }

        for (int kp : allkp)
        {
            memset(cnt,0,sizeof(cnt));
            cnt[dd[0]] = 1;
        //    multiset<ll> st;
    //        st.insert(0);
            for (int i = 0; i < n; i++)
            {
                ans += cnt[dd[sum[i] - kp]];
                //if (kp == sum[i]) ans++;
                //ans += distance(st.lower_bound(sum[i] - kp), st.upper_bound(sum[i] - kp));
                cnt[dd[sum[i]]] ++;
            //    st.insert(sum[i]);
            }
        //    pk *= k;
        }
        cout << ans<<endl;
    }
}
