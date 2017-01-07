#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000+1000;
char S1[maxn];
const ll moder = 1e9+7;
const ll P = 27;
char S2[maxn];
ll hhash[maxn];
ll upperp[maxn];
bool check()
{
    int n = strlen(S1);
    int m = strlen(S2);
    memcpy(S1 + n, S1, sizeof(char) * (n + 1));
    n*=2;
    ll tar = 0;
    ll tag = 0;
    if (n < m) return false;
    for (int i = 0; i < m; i++)
    {
        tar = (tar*P + S2[i]) % moder;
    }
    hhash[0] = 0;
    upperp[0] = 1;
//    upperp[1] = 1;
//    hhash[1] = S1[0];
    for (int i = 0; i < n; i++)
    {
        hhash[i + 1] = (hhash[i] * P + S1[i]) % moder;

        upperp[i + 1] = (upperp[i] * P) % moder;

    }
    for (int i = 0; i + m <= n; i++)
    {
    //    cout << (hhash[i + m - 1] - hhash[i - 1] * upperp[i - 1] % moder + moder)%moder << endl;
        if ((hhash[i + m] - (hhash[i] * upperp[m]) % moder + moder)%moder == tar)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin >> S1 >> S2)
    {
    //    int n=strlen(S1);
        if (check())
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}
