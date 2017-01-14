#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,t,n,m;
int dp[2010][2010],s[2010][2010],sum[2010],num[2010],INF=1e9;
int main()
{
    int i,j,k,ret,ans,len;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            num[i+n]=num[i];
        }
        for(i=1;i<=n*2;i++)
           sum[i]=sum[i-1]+num[i];
        for(i=1;i<=n*2;i++)
           s[i][i]=i-1;
        for(len=1;len<=n;len++)
           for(i=1;i+len<=n*2;i++)
           {
                j=i+len;
                dp[i][j]=INF;
                for(k=s[i][j-1];k<=s[i+1][j];k++)
                {
                    ret=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                    if(ret<dp[i][j])
                    {
                        dp[i][j]=ret;
                        s[i][j]=k;
                    }

                }
                cout <<"dp"<<i - 1<<" "<<j<<" = "<< dp[i][j] <<"  K = "<< s[i][j]<< endl;
            }
        ans=INF;
        for(i=1;i<=n;i++)
           ans=min(ans,dp[i][i+n-1]);
        printf("%d\n",ans);
    }
}
