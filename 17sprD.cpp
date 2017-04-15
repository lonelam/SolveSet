#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn];
bool cmp(const int lhs, const int b)
{
    if (abs(lhs) != abs(b))
    return abs(lhs) > abs(b);
    else return lhs < b;
}
int main()
{
    int T;
    cin >> T;
    int n,m;
    while(T--)
    {
        cin >> n >> m;
        int neg = -1, ans = 1;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a,a+n, cmp);
        for (int i = 0 ; i < m; i++)
        {
            ans *= a[i];
        }

        if (ans < 0)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                if (a[i] < 0)
                {
                    neg = i;
                    break;
                }
            }

            for (int i = m; i < n; i++)
            {
                if (a[i] >= 0)
                {
                    ans /= a[neg];
                    ans *= a[i];
                    break;
                }
            }
            //cout << "debug"<<endl;
            if (ans < 0)
            {
                    ans = 1;
                    for (int i = n - 1; i >= n - m; i--)
                    {
                        ans *= a[i];
                    }
            }
            int ax = 1;
            for (int i = 0; i < m; i++)
            {
                ax *= a[i];
            }
            neg = -1;
            for (int i = m - 1; i >= 0; i--)
            {
                if (a[i] > 0)
                {
                    neg = i;
                    break;
                }
            }
            if (neg != -1)
            {
                for (int i = m; i < n; i++)
                {
                    if (a[i] < 0)
                    {
                        ax /= a[neg];
                        ax *= a[i];
                    }
                }
            }
            ans = max(ans, ax);
        }
        cout << ans << endl;
        /*
100
5 2
4 -4 3 -2 1
5 3
3 4 -3 -4 -2


*/
    }
}
