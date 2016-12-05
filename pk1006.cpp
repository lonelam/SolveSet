#include<bits/stdc++.h>
using namespace std;
const int maxn = 60005;
int arr[maxn];
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int ar2[maxn];
int main()
{
    int n, t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ll diff = inf;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",arr + i);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d",ar2 + i);
        }
        //int nn = n - 1;
        for(int k = 0; k < n; k++)
        {
            ll sum = 0;
            int i;
            for(i = 0; i < n; i++)
            {
                ll td = arr[i] - ar2[(i + k) % n];
                sum += (td * td);
                if(sum >= diff)
                {
                    break;
                }
            }
            if(i == n && sum < diff)
            {
                diff = sum;
            }
        }
        printf("%I64d\n",diff);
    }
}
