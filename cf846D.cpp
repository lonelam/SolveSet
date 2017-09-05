#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
#define MAXN 505
int dp[MAXN][MAXN][20];
int dp1[MAXN][MAXN][20];
int a[MAXN][MAXN];
int n,m;
int k, q;
void st(){
    for(int i=1;i<=n;i++)
    for(int k=0;(1<<k)<=m;k++){
    for(int j=1;j+(1<<k)-1<=m;j++){
        if(k==0){
            dp[i][j][k]=dp1[i][j][k]=a[i][j];
        }
        else {
            dp[i][j][k]=max(dp[i][j][k-1],dp[i][j+(1<<(k-1))][k-1]);
            dp1[i][j][k]=min(dp1[i][j][k-1],dp1[i][j+(1<<(k-1))][k-1]);
        }
    }
    }
}
int rmq2dmax(int x,int y,int x1,int y1){
    int k=log2(y1-y+1);
    int mm=max(dp[x][y][k],dp[x][y1-(1<<k)+1][k]);
    for(int i=x+1;i<=x1;i++)
        mm=max(mm,max(dp[i][y][k],dp[i][y1-(1<<k)+1][k]));
    return mm;
}
int rmq2dmin(int x,int y,int x1,int y1){
    int k=log2(y1-y+1);
    int mm=min(dp1[x][y][k],dp1[x][y1-(1<<k)+1][k]);
    for(int i=x+1;i<=x1;i++)
        mm=min(mm,min(dp1[i][y][k],dp1[i][y1-(1<<k)+1][k]));
    return mm;
}
int main()
{
  scanf("%d%d%d%d", &n, &m, &k, &q);
  memset(a, inf, sizeof(a));
  for (int i = 0; i < q; i++)
  {
    int x, y, t;
    scanf("%d%d%d", &x, &y, &t);
    a[x][y] = t;
  }
  st();
  int ans = inf;
  for (int i = 1; i + k-1 <= n; i++)
  {
    for (int j = 1; j + k-1 <= m; j++)
    {
      // cout << rmq2dmax(i, j, i + k, j + k-1) << " ";
      ans = min(ans, rmq2dmax(i, j, i + k-1, j + k-1));
    }
    // cout << endl;
  }
  if (ans == inf) ans = -1;
  printf("%d\n", ans);

}
