

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxn = 200000 + 10;
ld ans[maxn];
//number of people after operation
ll people[maxn];
char tp[maxn][2];
int no[maxn];
ll t[maxn];
int main()
{

    while(~scanf("%d",&n))
    {
        int p = 0;
        n *= 2;
        for (int i = 0; i < n; i++)
        {
            scanf("%s%lld", tp[i], t + i);
            //cin >> tp[i] >> t[i];
            if (i) people[i] = people[i-1];
            if (tp[i][0] == '-')
            {
                people[i]--;
            }
            else if (tp[i][0] == '+')
            {
                no[i] = p++;
                people[i]++;
            }
        }
        ld Etail = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (tp[i][0] == '-')
            {
                Etail *= (ld)people[i] / (ld) (people[i] + 1);
                Etail += (ld)1 / (ld) (people[i] +1) * (ld)t[i];
            }
            else if (tp[i][0] == '+')
            {
                ans[no[i]] = Etail - t[i];
            }
        }
        n /= 2;

        for (int i = 0; i < n; i++)
        {
            printf("%.10Lf\n", ans[i]);
            //cout << ans[i] << endl;
        }
    }
}
