#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn];
int main()
{
    int n;
    cin >> n;
    int mm = -1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mm = max(mm,a[i]);
    }
    cout << mm * n - sum<< endl;
}
