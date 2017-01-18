#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
ll gcd(ll a,ll b)
{
    if ( b==0)
    return a;
    return gcd(b,a%b);
}
string tobin(ll a)
{
    string res = "";
    while(a)
    {
        res += char((a & 1) + '0');
        a >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}
const int mod = 1e9 + 7;
ll expo(ll base, ll pow)
{
    ll ans = 1;
    while(pow != 0)
    {
        if (pow & 1 == 1)
        {
            ans = ans * base;
            ans = ans % mod;
        }
        base *= base;
        base %= mod;
        pow /= 2;
    }
    return ans;
}
ll inv(ll x)
{
    return expo(x, mod - 2);
}

const int M = 1001111;

vector<int> BIT(M);
ll res = 1;
int isP[222];
int N, K, X = 0;
void sieve()
{
    isP[1] = 1;
    for (int i = 2; i < 100; i++)
    {
        if (isP[i])
        {
            continue;
        }
        for (ll j = i * 1LL* i; j < 100; j+= i)
        {
            isP[j] = 1;
        }
    }
}
ll dofor(int a,int b)
{
    ll ult = 0;
    for (int r = b + 1; r > 0; r -= r & -r)
    {
        ult += BIT[r];
    }
    for (int l = 1; l > 0 ; l -= l & -l)
    {
        ult -= BIT[l];
    }
    if (a > b)
    {
        for (int r = N; r > 0; r -= r & -r)
        {
            ult += BIT[r];
        }
    }
    return ult;
}
void read()
{
    cin >> N >> K;
}
void print(ll ans)
{
    printf("%lld ",ans);
}
void up(int we)
{
    we = we + 1;
    for (; we < M; we += we & -we)
    {
        BIT[we]++;
    }
}
void solve()
{
    for (int i = 0; i < N; i++)
    {
        int st = (X + 1) % N;
        int en = (X + K - 1) % N;
        res += dofor(st, en) + 1;
        print(res);
        up(X);
        up((X + K) % N);
        X = (X + K) % N;
    }
}
int main()
{
    sieve();
    read();
    solve();
}
