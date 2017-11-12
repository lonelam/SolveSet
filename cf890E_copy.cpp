#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define DEB 1
#define dbg_tab(x,l) if(DEB) { cerr << #x << ":"; for(int i=0;i<l;i++) cerr << " " << x[i]; cerr << endl; }
#define dbg_vec(x) if(DEB) { cerr << #x << ":"; for(auto y:x) cerr << " " << y; cerr << endl; }

int n, k;
const int N = 1e6;
int mod = 1e9 + 7;
int sil[N + 7];
int silr[N + 7];
int dp[N + 7];
int dppom[N + 7];

int potmod(long long x, int m) {
    long long res = 1;
    while(m > 0) {
        if(m & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        m /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    sil[0] = 1;
    for(int i = 1; i <= n; ++i) sil[i] = ((long long) sil[i - 1] * i) % mod;
    silr[n] = potmod(sil[n], mod - 2);

    for(int i = n - 1; i >= 0; --i) silr[i] = ((long long) silr[i + 1] * (i + 1)) % mod;

    long long sum = 0;

    for(int i = 1; i <= n; ++i) {
        if(i >= k) {
            sum += dppom[i - k];
            sum %= mod;
        }
        dp[i] = (sum * sil[i]) % mod;
        if(i + k <= n) {
            long long rr = sil[i + k - 1];
            rr *= silr[k + i];
            rr %= mod;
            rr *= silr[i - 1];
            rr %= mod;
            rr *= ((long long) sil[i - 1] + mod - dp[i - 1]);
            rr %= mod;
            dppom[i] = rr % mod;
        }
    }

    long long wynik = 0;
    for(int i = 1; i <= n; ++i) {
        long long res = dp[i - 1];
        res *= sil[n - 1];
        res %= mod;
        res *= silr[i - 1];
        res %= mod;
        res *= silr[n - i];
        res %= mod;
        res *= sil[n - i];
        res %= mod;
        wynik += res;
    }
    wynik %= mod;
    cout << wynik << endl;
    return 0;
}
