#include<iostream>
using namespace std;
const int maxn = 100000 +20;
int n, W;
const int maxw = 100000 +1;
int dp[maxw +1];
int deq[maxw +1];
int deqv[maxw + 1];

void solve()
{

    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a < w[i]; a++)
        {
            int s = 0, t = 0;
            for (int j = 0; j * w[i] +a <= W; j++)
            {
                int val = dp[j * w[i] + a] - j * v[i];
                while(s < t && deqv[t - 1] <= val) t--;
                deq[t] = j;
                deqv[t++] = val;
                dp[j *w[i] +a] = deqv[s] +j * v[i];
                if (deq[s] == j - m[i])
                {
                    s++;
                }
            }
        }
    }
    printf( )
}
