#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 200;
int a[maxn];
int b[maxn];
int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a + l - 1, a + r);
    sort(b + l - 1, b + r);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "LIE\n";
            return 0;
        }
    }
    cout <<"TRUTH" << endl;
}
