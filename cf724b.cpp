#include<bits/stdc++.h>
using namespace std;
int grid[50][50];
    int n, m;
bool kkk()
{
    for(int i = 1; i <= n; i++)
    {
        int vio = 0;
        for(int j = 1; j <= m; j++)
        {
            if(grid[i][j] != j)
            {
                vio++;
            }
            if(vio > 2)
            {
                return false;
            }
        }
    }
    return true;
}
void swp(int a, int b)
{
    for(int i = 1; i <= n; i++)
    {
        swap(grid[i][a], grid[i][b]);
    }
}

bool solve()
{
    if(kkk())
    {
        return true;
    }
    for(int i = 1;i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i != j)
            {
                swp(i, j);
                if(kkk())
                {
                    return true;
                }
                swp(i, j);
            }
        }
    }
    return false;
}
int main()
{
    while(cin >> n >> m)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> grid[i][j];
            }
        }
    if(solve())
    {
        cout<<"YES\n";

    }
    else
    {

        cout<<"NO\n";
    }
    }
}
