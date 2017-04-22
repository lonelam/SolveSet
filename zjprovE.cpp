#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

char pad[100];
int digit[100];
int cost[] = {6,2,5,5,4,5,6,3,7,6,6,5,4,5,5,4};
int presum[20];
int idx(char x)
{
    if (isdigit(x))
    {
        return x - '0';
    }
    else
    {
        return 10 + x - 'A';
    }
}
int main()
{
    int T;
    ll n;
    presum[0] = cost[0];
    for (int i = 1; i < 16; i++)
    {
        presum[i] = presum[i - 1] + cost[i];
    }
    cout << presum[15];
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            scanf("%lld%s", &n, pad);
            ll hmask = 1, upcost = 0, downcost = 0;
            for (int i = 0; i < 8; i++)
            {
                digit[i] = idx(pad[7 - i]);
                upcost += cost[digit[i]];
            }
            int i;
            ll ans = 0;
            /*cout << "**"<<n << endl;
            for (int i = 0; i < 8; i++)
            {
                cout << digit[i] <<" ";
            }
            cout << endl;*/
            for (i = 0; i < 8; i++)
            {
                //if (!digit[i]) continue;
                if (n >= (16 - digit[i]) * hmask)
                {
                    n -= (16 - digit[i]) * hmask;
                    upcost -= cost[digit[i]];
                    ans += downcost * (16 - digit[i]);
                    ans += upcost * (16 - digit[i]) * hmask;
                    if (digit[i]) ans += hmask * (presum[15] - presum[digit[i] - 1]);
                    else ans += hmask * presum[15];
                //    cout <<"debug  "<< ans <<" "<< n << endl;
                    downcost *= 16LL;
                    downcost += hmask * presum[15];
                    digit[i] = 0;
                    for (int j = i + 1; j < 8; j++)
                    {
                        upcost -= cost[digit[j]];
                        if (digit[j] != 15)
                        {

                            digit[j]++;
                            upcost += cost[digit[j]];
                            break;
                        }
                        else
                        {
                            digit[j] = 0;
                            upcost += cost[digit[j]];
                        }
                    }
                    hmask *= 16;
                }
                else
                {
                    upcost -= cost[digit[i]];
                    downcost *= 16LL;
                    downcost += hmask * presum[15];
                    hmask *= 16;
                    break;
                }
            }
            if (i == 8) i--;
            /*for (int o = 0; o < 8; o++)
            {
                cout << digit[o] <<" ";
            }
            cout << endl;*/
            for (; i >= 0; i--)
            {
                hmask /= 16;
                downcost -= hmask * presum[15];
                downcost /= 16;
                int t = n / hmask;
                ans += upcost * t * hmask;
        //        cout <<"ddbug   "<< ans << " "<< n << endl;
                ans += downcost * t;
                if (digit[i]) ans += (presum[digit[i] + t - 1] - presum[digit[i] - 1]) * hmask;
                else if (t) ans += presum[t - 1] * hmask;
                digit[i] += t;
                upcost += cost[digit[i]];
                n %= hmask;
            }
            printf("%lld\n", ans);
        }
    }
}
