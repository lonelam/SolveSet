#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int w[maxn];
int main()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0 ; i < n; i++)
    {
        cin >> w[i];
        cnt += w[i] / k;
        if (w[i] % k) cnt++;
    }
    if (cnt & 1) cnt++;
    cnt /= 2;
    cout << cnt << endl;
}
