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
const int maxn = 200010;
int pre[maxn], ch[maxn][2], key[maxn], size[maxn];
int root, tot1;
int mx[maxn];
int s[maxn], tot2;
int a[maxn];
int n, q;
void newnode(int & r, int father, int k)
{
    if (tot2) r = s[tot2--];
    else r = ++tot1;
    pre[r] = father;
    ch[r][0] = ch[r][1] = 0;
    key[r] = k;
    mx[r] = k;
    size[r] = 1;
}

void pushup(int r)
{
    int lson = ch[r][0], rson = ch[r][1];
    size[r] = size[lson] + size[rson] + 1;
    mx[r] = max({key[r], mx[lson], mx[rson]});
}
void build(int &x, int l, int r, int father)
{
    if (l > r) return;
    int mid = (l + r) / 2;
    newnode(x, father, a[mid]);
    build(ch[x][0], l, mid - 1, x);
    build(ch[x][1], mid + 1, r, x);
    pushup(x);
}

void init()
{
    root = tot1 = tot2 = 0;
    ch[root][0] = ch[root][1] = size[root] = pre[root] = 0;
    key[root] = mx[root] = -inf;
    newnode(root, 0, -1);
    newnode(ch[root][1], root, -1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(ch[ch[root][1]][0], 0, n - 1,ch[root][1]);
    pushup(ch[root][1]);
    pushup(root);
}


void rotate(int x, int d)
{
    const int y = pre[x];
    ch[y][!d] = ch[x][d];
    if (ch[x][d]) pre[ch[x][d]] = y;
    pre[x] = pre[y];
    if (ch[pre[y]][0] == y) ch[pre[x]][0] = x;
    else if (ch[pre[y]][1] == y) ch[pre[x]][1] = x;
    pre[y] = x;
    ch[x][d] = y;
    pushup(y);
}
void splay(int r, int goal)
{
    while(pre[r] != goal)
    {
        if (pre[pre[r]] == goal)
        {
            rotate(r, ch[pre[r]][0] == r);
        }
        else
        {
            int y = pre[r];
            int kind = ch[pre[y]][0] == y;
            if (ch[y][kind] == r)
            {
                rotate(r, !kind);
                rotate(r, kind);
            }
            else
            {
                rotate(y, kind);
                rotate(r, kind);
            }
        }
    }
    pushup(r);
    if (goal == 0) root = r;
}

int getkth(int r, int k)
{
    int t = size[ch[r][0]] + 1;
    if (t == k) return r;
    if (t > k) return getkth(ch[r][0], k);
    else return getkth(ch[r][1], k - t);
}


int getmax(int pos, int tot)
{
    splay(getkth(root, pos), 0);
    splay(getkth(root, pos + tot + 1), root);
    return mx[ch[ch[root][1]][0]];
}

void update(int pos, int to)
{
    splay(getkth(root, pos), 0);
    key[root] = to;
    pushup(root);
}

int main()
{
    while(scanf("%d%d", &n, &q)!=EOF)
    {
        init();
        char cmd[100];
        while(q--)
        {
            int op1, op2;
            scanf("%s%d%d", cmd, &op1, &op2);
            if(cmd[0] =='Q')
            {
                printf("%d\n", getmax(op1, op2 - op1 + 1));
            }
            else
            {
                update(op1 + 1, op2);
            }
        }
    }
}
