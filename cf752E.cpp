#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 100;
ll a[maxn];


int main()
{
    int n, k;
    ios::sync_with_stdio(false);
    while(cin >> n >> k)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum < k)
        {
            cout << -1 << endl;
            continue;
        }
        sort(a, a+ n, greater<ll>());
        int pl = 0, pr =
    }
}
