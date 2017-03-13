#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;

int r[maxn];
int n,m;
int vis[maxn];
vector<int> sw[maxn];

struct edge
{
    int to, nex;
} es[maxn];

int head[maxn], tot;
void init()
{
    tot = 0;
    memest(head, -1, sizeof(head));
    
}
