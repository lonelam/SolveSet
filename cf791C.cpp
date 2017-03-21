#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
string proj(int x)
{
    return char('A' + x % 26) + string(1, char('a' + x / 26));
}
int a[maxn];
string s[maxn];
int main()
{
    int n;
    int k;
    cin >> n >> k;
    int cnt = n + 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    for (int i = k; i <= n; i++)
    {
        cin >> s[i];
        if (s[i] == "NO")
        {
            a[i] = a[i - k + 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << proj(a[i]) <<( (i == n)? "\n":" ");
    }
}
