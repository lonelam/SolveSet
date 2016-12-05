
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxw = 4;
const int maxs = 1 << maxw;
typedef long long ll;
ll dp[2][maxs];//s means that if the next row whether filled.
int moder;
int main()
{
    int h, w;
    w = 4;
    int ms = 1 << w;
    while(scanf("%d", &h)!=EOF && h!= -1)
    {
        int flip = 0;
        memset(dp,0,sizeof(dp));
        dp[1][0] = 1;
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {

                flip ^= 1;
                for(int s = 0;  s < ms; s++)
                {
                    if(s & ( 1 << j))
                    {
                        dp[flip ^ 1][s & ~(1 << j)] += dp[flip][s];
                    }
                    else
                    {
                        if(!(s & ( 1 << ( j + 1))) && (j + 1) < w)
                        {
                            dp[flip^ 1][s | (1 <<(j + 1))] += dp[flip][s];
                        }
                        dp[flip ^ 1][s | (1 << j)] += dp[flip][s];
                    }
                }
                memset(dp[flip], 0, sizeof(dp[flip]));
            }
        }
        flip ^= 1;
        printf("%I64d\n",dp[flip][0]);
    }
}
