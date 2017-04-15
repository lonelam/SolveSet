#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
//int vis[maxn];
map<int, int> vis, cnt;
int main()
{
    int u, v;
    int kase = 1;
    int ecnt = 0, vcnt = 0;
    while(scanf("%d%d",&u,&v)!= EOF)
    {
        if (u < 0 || v < 0) break;
        if (u == 0 && v == 0)
        {
            int ok = true;

            vcnt = vis.size();
            for (map<int, int> ::iterator i = vis.begin(); i != vis.end(); i++)
            {
                if (cnt[i->first] > 1)
                {
                    ok=false;
                }
            }
            if (ecnt && ecnt != vcnt - 1) ok = false;
            ecnt = vcnt = 0;
            if (ok)
            {
                printf("Case %d is a tree.\n", kase++);
            }
            else
            {
                printf("Case %d is not a tree.\n", kase++);
            }
            vis.clear();
            cnt.clear();
            //memset(cnt, 0, sizeof(cnt));
        }
        else
        {
            ecnt++;
            vis[u] = vis[v] = true;
            cnt[v]++;
        }
    }
}
