#include<bits/stdc++.h>
#define LL long long int
using namespace std;

const int maxn  = 20006;
int arr[maxn];
int sum[maxn];
int dp[maxn][160];
int n;

void init()
{
    sum[0] = 0;
    memset(sum,0,sizeof(sum));
}

int main()
{
    int TT;
    scanf("%d", &TT);
    while(TT--)
    {
        scanf("%d", &n);
        init();
        for(int i = 1;i<=n;i++)
        {
          scanf("%d", arr + i);
            sum[i] = sum[i-1] + arr[i];
        }
        //system("pause");
        memset(dp,0,sizeof(dp));
        for(int i=n;i>=1;i--)
        {
            for(int k=151;k>=1;k--)
            {
                if( n-i+1 < k ) dp[i][k]=0;
                else
                {
                  if (n - i != k - 1)
dp[i][k]= max ( -dp[i+k][k] + sum[i+k-1]-sum[i-1],
                                     -dp[i+k+1][k+1] + sum[i+k]-sum[i-1]);
                                     else

 dp[i][k]= -dp[i+k][k] + sum[i+k-1]-sum[i-1] ;
              }
            }
        }
        printf("%d\n", dp[1][1]);
        // cout<<dp[1][1]<<endl;
    }
	return 0;
}
