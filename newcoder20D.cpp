#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans;
const int maxn = 500 +5;
char grid[maxn][maxn];
int upx[maxn][maxn];
int upo[maxn][maxn];
int diagx[maxn][maxn];
int diago[maxn][maxn];
int rdiagx[maxn][maxn];
int rdiago[maxn][maxn];

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", grid[i]);
        }
        bool cntx = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[j][i] == 'X')
                {
                    cntx = true;
                    upx[j][i] = (j?upx[j-1][i]:0)+ 1;
                    diagx[j][i] = ((i && j)?diagx[j-1][i-1]:0) + 1;
                }
                if (grid[j][i] == 'O')
                {
                    upo[j][i] = (j?upo[j-1][i]:0)+ 1;
                    diago[j][i] = ((i && j)?diago[j-1][i-1]:0) + 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (grid[i][j] == 'X')
                {
                    rdiagx[i][j] = ((i && (j < m - 1))? rdiagx[i-1][j+1]: 0) + 1;
                }
                if (grid[i][j] == 'O')
                {

                    rdiago[i][j] = ((i && (j < m - 1))? rdiago[i-1][j+1]: 0) + 1;
                }
            }
        }/*
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                cout << upo[i][j] << " ";
            }
            cout << endl;
        }*/
        ans = 0;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'X')
                {
                    ans = 0;

                    while(i-ans >= 1 && j - ans >= 1 && i + ans < n-1 && j + ans < n-1)
                    {
                        if(
                          upx[i+ans + 1][j - ans - 1] >= ans* 2 + 3 && upo[i+ans +1][j+ans+1] >= ans * 2 + 3&&
                          diagx[i][j] >= ans + 1 && rdiagx[i + ans + 1][j-ans - 1] >= ans + 1 &&
                          diago[i+ans+1][j+ans+1] >= ans && rdiago[i-1][j+1] >= ans
                          )
                        {
                            ret = max(ret, ans+1);
                           // cout << i << " " << j << endl;
                        }
                        ans++;
                    }
                }
            }
        }
        printf("%d\n", cntx?(ret* 2 +1):0);
    }
}
