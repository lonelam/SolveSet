#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int i = 2; k > 1 && i * i <= n; i++)
    {
        while(n % i == 0 && k > 1)
        {
            ans.push_back(i);
            k--;
            n /= i;
        }
    }
    if (k > 1 || n == 1) cout << -1 << endl;
    else
    {
        ans.push_back(n);
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
        {
            cout <<" "<< ans[i];
        }
        cout << endl;
    }
}
