#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
map <string, int> userid;

bool valid[maxn][maxn];
int pos[maxn];
//int preid = 0;
int n, m;
bool check()
{
    int preid = -1;
    for (int i = 0; i < n; i++)
    {
        if (pos[i] == preid || pos[i])
        {
            return false;
        }
    }
}
int main()
{
    for (int i = 0; i < m;i ++)
    {
        for (int j = 0; j < n; j++)
        {
            
        }
    }
}
