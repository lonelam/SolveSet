#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const int MAX_N = 1000010;

int T, cases = 0, a, b, c, d, k, prime_cnt;
int mu[MAX_N], vis[MAX_N], prime[MAX_N];

void init()
{
    prime_cnt = 0;
    mu[1] = 1;
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i < MAX_N; i++) {
        if(vis[i] == 0) {
            prime[prime_cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < prime_cnt && i * prime[j] < MAX_N; j++) {
            vis[i * prime[j]] = 1;
            if(i % prime[j] ) {
                mu[i * prime[j]] = -mu[i];
            }else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
}

ll solve(int n, int m)
{
    ll res = 0;
    int low = min(n, m);
    for(int i = 1; i <= low; ++i) {
        res += (ll)mu[i] * (n / i) * (m / i);
    }
    ll tmp = 0;
    for(int i = 1; i <= low; ++i) {
        tmp += (ll)mu[i] * (low / i) * (low / i);
    }
    res -= tmp / 2;
    return res;
}
int main()
{
  int nnn;
  while(scanf("%d", &nnn) != EOF)

}
