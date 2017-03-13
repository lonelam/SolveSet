#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
    int n,k;
    cin >> n >> k;
    int ans = 0;
    int acc = 0;
    int cnt = 0;
    while(n)
    {
        cnt++;
        if (n % 10)
        {
            acc++;
        }
        else
        {
            ans++;
            k--;
        }
        if (k == 0)
        {
            break;
        }
        n /= 10;
    }
    if (k != 0 && ans != 0)
    {
        acc = cnt - 1;
    }
    cout << acc << endl;
}
