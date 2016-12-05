//sparse table version

#include<algorithm>
#include<cstdio>
using namespace std;

const int MAXN = 50010;
int dp[MAXN][20];
int dp2[MAXN][20];
int mm[MAXN];
//初始化RMQ, b数组下标从1开始，从0开始简单修改
void initRMQ(int n,int b[])
{
    mm[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
        dp2[i][0] = dp[i][0] = b[i];

    }
    for(int j = 1; j <= mm[n]; j++)
        for(int i = 1; i + (1<<j) -1 <= n; i++)
            {
                dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
                dp2[i][j] = min(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
            }
}
//查询最大值,x y inclusive>?
int rmq(int x,int y)
{
    int k = mm[y-x+1];
    return max(dp[x][k],dp[y-(1<<k)+1][k]) - min(dp2[x][k],dp2[y-(1<<k)+1][k]);
}

int a[MAXN];
int main()
{
    int n,m,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d",a +i);
        }
        initRMQ(n, a - 1);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &x,&y);
            printf("%d\n",rmq(x,y));
        }
    }
}
