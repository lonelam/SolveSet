#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x7f3f3f3f;
const int maxn = 300000;
int a[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i ++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int dis = inf, p = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] == dis)
        {
            p++;
        }
        else if (a[i] -a[i - 1] < dis)
        {
            dis = a[i] - a[i - 1];
            p = 1;
        }
    }
    cout << dis << " "<< p << endl;
}
