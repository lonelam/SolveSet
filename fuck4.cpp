#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100;
char grid[maxn][maxn];
int dx[] = {1, 0, 1, 1};
int dy[] = {0, 1, -1, 1};
bool check()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 'O')
            for (int d = 0; d < 4; d++)
            {
                int cnt = 0;
                int cx = i + dx[d], cy = j + dy[d];
                while(cx >= 0 && cx < 9 && cy >= 0 && cy < 9 && grid[cx][cy] == 'B')
                {
                    cx += dx[d];
                    cy += dy[d];
                    cnt++;
                }
                cx = i - dx[d];
                cy = j - dy[d];
                while(cx >= 0 && cx < 9 && cy >= 0 && cy < 9 && grid[cx][cy] == 'B')
                {
                    cx -= dx[d];
                    cy -= dy[d];
                    cnt++;
                }
                if (cnt >= 4)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int n;
    while(cin >> n)
    {
        while(n--)
        {
            for (int i = 0; i < 9; i++)
            {
                cin >> grid[i];
            }
            if (check())
            {
                cout << "Yes!" << endl;
            }
            else
            {
                cout << "No!"<<endl;
            }

        }
    }
}
