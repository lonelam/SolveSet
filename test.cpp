#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
bool via[100];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = INT_MAX;
    do
    {
        int cnt = 0;
        int pre = a[0];
        for (int i = 0; i < n; i++)
        {
                if (__gcd(a[i], pre) != 1)
                {
                    pre = 1;
                    cnt++;
                }
                pre *= a[i];
        }
        ans = min(ans, cnt);
    }while(next_permutation(a, a + n));
    cout << ans << endl;
}
