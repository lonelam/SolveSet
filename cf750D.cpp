#include<iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
bool grid[500][500];
bool vis[500][500][8][31];
int t[50];
int id[8] = {0, 1, 2,   3,  4, 5, 6, 7};
///-----------------------------------------
int dx[8]  = {0,0, 1,   1, 1, -1, -1, -1};
int dy[8] = {1,-1, 0,  -1,  1,  0,-1  ,1};
int to1[8] = {4, 3, 3, 2, 0,  6, 5, 5};
int to2[8] = {7, 6, 4, 1, 2,  7, 1, 0};
int n;
void dfs(int cx, int cy, int cdir, int dep)
{

    if (vis[cx][cy][cdir][dep] || dep == n)
    {
        return;
    }
    vis[cx][cy][cdir][dep] = true;
    int tx = cx;
    int ty = cy;
    for (int i = 0; i < t[dep]; i++)
    {

        tx += dx[cdir];
        ty += dy[cdir];
        grid[tx][ty] = true;
    }

    dfs(tx, ty, to1[cdir], dep + 1);
    dfs(tx, ty, to2[cdir], dep + 1);

}
int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> t[i];
        }
        memset(vis, 0, sizeof(vis));
        memset(grid, 0, sizeof(grid));
        dfs(250, 250, 0, 0);
        int cnt = 0;
        for (int i = 1; i < 500; i++)
        {
            for (int j = 0; j < 500; j++)
            {
                if (grid[i][j])
                {
                    cnt++;
                }
            }
        }
        cout << cnt <<endl;
    }
}
