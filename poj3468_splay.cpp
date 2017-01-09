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
const int maxn = 100000 + 1000;

ll add[maxn], sum[maxn], val[maxn], size[maxn];
int pre[maxn], ch[maxn][2], tot, root, n, q;
ll a[maxn];
void debug()
{
    for (int i = 0; i < tot; i++)
    {
        cout << "node "<< i << " chs: "<< ch[i][0] << " "<< ch[i][1] << " val/sum: "<<val[i] <<" "<< sum[i] << endl;
    }
}

void update_add(int r,ll x){
    add[r] += x;
    val[r] += x;
    sum[r] += 1LL * size[r] * x;
}

void pushdown(int r)
{
    if (!r) return;
    if (add[r])
    {
    /*    val[r] += add[r];
    //    sum[r] += add[r] * size[r];
        if (ch[r][0])
        add[ch[r][0]] += add[r];
        if (ch[r][1])
        add[ch[r][1]] += add[r];*/
        if(ch[r][0])update_add(ch[r][0],add[r]);
        if(ch[r][1])update_add(ch[r][1],add[r]);
        add[r] = 0;
    }
}

void pushup(int x)
{
    if (!x) return;
//    pushdown(ch[x][0]);
//    pushdown(ch[x][1]);
    sum[x] = val[x] + sum[ch[x][0]] + sum[ch[x][1]] ;
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
}

void newnode(int & pos, int fa, ll k)
{
    add[tot] = ch[tot][0] = ch[tot][1] = 0;
    pre[tot] = fa;
    sum[tot] = val[tot] = k;
    size[tot] = 1;
    pos = tot++;
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
bool _splay_parent(int x, int &y, int goal)
{
    return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}
void splay(int x, int goal)
{
    pushdown(x);
    for (int y,z; _splay_parent(x, y, goal);)
    {
        if (_splay_parent(y, z, goal))
        {
            pushdown(z);
            pushdown(y);
            pushdown(x);
            int d= y == ch[z][0];
            if (x == ch[y][d]) rotate(x, d ^ 1), rotate(x, d);
            else rotate(y, d), rotate(x, d);
        }
        else
        {
            pushdown(y), pushdown(x);
            rotate(x, x == ch[y][0]);
            break;
        }
    }
    pushup(x);
    if (goal == 0)
    {
        root = x;
    }
}
void init()
{
    for (int i = 0; i < n; i++)
    {
        //cin >> a[i];
        scanf("%lld", a + i);
    }
    tot = 0;
    newnode(root, 0, 0);
    size[0] = 0;
    newnode(ch[root][1], 0, 0);
    for (int i = 0; i < n; i++)
    {
        newnode(ch[i + 1][1], i + 1, a[i]);
    }
    newnode(ch[n + 1][1], n + 1, 0);
    for (int i = n; i > 0; i--)
    {
        pushup(i);
    }
}

ll query(int l , int r)
{

    splay(r + 2, 0);
    splay(l , root);
    return sum[ch[ch[root][0]][1]];
}

void addup(int l, int r, ll adder)
{
    splay(r + 2, 0);
    splay(l , root);
    update_add(ch[ch[root][0]][1], adder);
}

int main()
{
//    ios::sync_with_stdio(false);
    while(scanf("%d%d", &n,&q)!=EOF)
    {
        init();
        char cmd[100];
        while(q--)
        {
        //    cin >> cmd;
            scanf("%s", cmd);
            int A, B;
            ll C;
            if (cmd[0] == 'Q')
            {
    //            debug();
            //    cin >> A >> B;
                scanf("%d%d",&A,&B);
                cout << query(A, B)<< endl;
            }
            else
            {
//                debug();
        //        cin >> A >> B>> C;
                scanf("%d%d%lld", &A,&B,&C);
                addup(A, B, C);
            }
        }
//        debug();
    }
    return 0;
}
