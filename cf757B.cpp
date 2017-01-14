#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int s[maxn];
int S[maxn];
int nprime[maxn];
int ans[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        S[s[i]]++;
    }
    int mx = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!nprime[i])
        {
            ans[i] += S[i];
            for (int j = i + i; j < maxn; j+= i)
            {
                nprime[j] = 1;
                ans[i] += S[j];
            }
            mx = max(ans[i], mx);
        }
    }
    cout << mx << endl;
}
