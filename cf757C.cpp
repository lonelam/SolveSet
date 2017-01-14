#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;

int setno[maxn];
int settot;
struct tup
{
    int cnt, id, setno;
    bool operator<(const tup & rhs)
    {
        if (cnt != rhs.cnt) return cnt < rhs.cnt;
        return setno < rhs.setno;
    }
};
tup tmp[maxn];
ll fact[1000000 + 100];
const ll moder = 1e9 + 7;
int main()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        fact[i] = (fact[i - 1] ) * (ll) i  % moder;
    }
    int n, m;
    settot = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int gi;
        map<int, int> cnt;
        scanf("%d", &gi);
        int pokeno;
        for (int j = 0; j < gi; j++)
        {
            scanf("%d", &pokeno);
            cnt[pokeno]++;
        }
        int k = 0;
        for (pair<int, int> x: cnt)
        {
            tmp[k++] = {x.second, x.first, setno[x.first]};
        }
        sort(tmp, tmp + k);
        for (int j = 0; j < k; j++)
        {
            //cout <<"debug";
            if (j == 0 || tmp[j].cnt != tmp[j - 1].cnt || tmp[j].setno != tmp[j - 1].setno) settot++;
            setno[tmp[j].id] = settot;
        }
    }
    map<int, int> finalcnt;
    for (int i = 1; i <= m; i++)
    {
    //    cout << setno[i] << " ";
        finalcnt[setno[i]]++;
    }
    ll ans = 1;
    for (auto x : finalcnt)
    {
        ans = (ans * fact[x.second]) % moder;
    }
    printf("%lld\n", ans);
}
