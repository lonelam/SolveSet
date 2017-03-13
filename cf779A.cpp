#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn];
int b[maxn];
int main()
{
    int n;
    cin >> n;
    map<int, int> am, bm;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        am[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {

        cin >> b[i];
        bm[b[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= 5; i++)
    {
        if ((am[i] + bm[i])& 1)
        {
            ans  = -1;
            break;
        }
        else
        {
            ans += abs(am[i] - bm[i])  / 2;
        }
    }
    if (ans != -1)
    {
        ans /= 2;
    }
    cout << ans << endl;
}
