
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2500 +100;
char s[maxn];
int n;
char t[maxn];
int m;
int mem[maxn][maxn];

int dfs(int p = 0, int q = 0)
{
    //cout << p << " "<< q<<endl;
    if (mem[p][q] != -1) return mem[p][q];
    if (q >= m)
    {
        if (p == n) return mem[p][q] =1;
        return mem[p][q] = 0;
    }
    bool dot = t[q] == '.' && p < n;
    if (dot)
    {
        t[q] = s[p];
    }
    if (q+1 < m && t[q + 1] == '*')
    {
     //   if (dfs(p, q + 2)) return mem[p][q] =1;
        int k = 0;
        while(p + k < n && t[q] == s[p + k])
        {
            k++;
            //if (dfs(p + k, q + 2)) return mem[p][q] = 1;
            //if (p + i >= n) break;
        }
        for (int i = k; i >= 0; i--)
        {
            if (dfs(p + i, q + 2)) return mem[p][q] = 1;
        }
    }
    else if (p < n && t[q] == s[p])
    {
        if (dfs(p + 1, q + 1)) return mem[p][q] = 1;
    }
    if (dot)
    {
        t[q] = '.';
    }
    return mem[p][q] = 0;
}
int main()
{
    for (int k = 0; k < 15; k++)
    {
        memset(mem, -1,sizeof(mem));

    }

}
