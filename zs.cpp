#include<iostream>
#include<stdio.h>
using namespace std;
int dp[4505][4505];
int solve(int n,int m)
{
int i,j;
for(i=1;i<=n;++i)
{
   dp[i][0]=0;
   for(j=1;j<=m;++j)
   {
    dp[0][j]=0;
    if(i>=j)
     dp[i][j]=dp[j-1][j]+1;
    else
    {
     dp[i][j]=dp[i-1][j]+dp[i][j-i];
     if(dp[i][j]>=1000000007)
      dp[i][j]-=1000000007;
    }
   }
}
return dp[n][m];
}
int main()
{
int n,m;
scanf("%d %d",&n,&m);
printf("%d\n",solve(n,m));
return 0;
}
