#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 1000;

int ch[maxn][2], pre[maxn], root;
int tot;
ll msum[maxn][5], val[maxn], mx[maxn];
int size[maxn];
int n;


void debug()
{
    for (int i = 0; i < tot; i++)
    {
        cout << "node["<<i <<"] ="<<val[i] <<" chs:"<<ch[i][0] <<" "<< ch[i][1] <<" msum:  ";
        for (int j = 0; j < 5; j++)
        {
            cout << msum[i][j]<<" ";
        }
        cout <<"size: "<<size[i] << endl;
    }
}
void pushup(int x)
{
    if (!x) return;
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    for (int i = 0; i < 5; i++)
    {
        msum[x][i] = msum[ch[x][0]][i] + msum[ch[x][1]][(i - size[ch[x][0]] - 1 + 500000) % 5];
    }
    if(x != 1) msum[x][(1 + size[ch[x][0]]) % 5] += val[x];
    mx[x] = max({mx[ch[x][0]], mx[ch[x][1]], val[x]});
}
void newnode(int & pos, int fa, ll k)
{
    for (int i = 0; i < 5; i++)
    {
        msum[tot][i] = 0;
    }
    mx[tot] = msum[tot][1] = val[tot] = k;
    pre[tot] = fa;
    size[tot] = 1;
    ch[tot][0] = ch[tot][1] = 0;
    pos = tot ++;
}
void rotate(int x, int d)
{
    const int y = pre[x];
    ch[y][!d] = ch[x][d];
    if (ch[x][d]) pre[ch[y][!d]] = y;
    if (ch[pre[y]][0] == y)
    {
        ch[pre[y]][0] = x;
    }
    else if (ch[pre[y]][1] == y)
    {
        ch[pre[y]][1] = x;
    }
    pre[x] = pre[y];
    pre[y] = x;
    ch[x][d] = y;
    pushup(y);
}
bool _splay_parent(int x, int & y, int goal)
{
    return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}
void splay(int x, int goal = 0)
{
    for (int y, z; _splay_parent(x, y, goal);)
    {
        if (_splay_parent(y, z, goal))
        {
            int d = y == ch[z][0];
            if (x == ch[y][d]) rotate(x, !d), rotate(x, d);
            else rotate(y, d), rotate(x, d);
        }
        else
        {
            rotate(x, x == ch[y][0]);
            break;
        }
    }
    pushup(x);
    root = x;
}
int getpos(ll x, int u = root)
{
    if (x > mx[ch[u][0]])
    {
        if (x <= val[u])
        {
            return u;
        }
        return getpos(x, ch[u][1]);
    }
    return getpos(x, ch[u][0]);
}
void insert(int u, ll x)
{
    if (!ch[u][0])
    {
        newnode(ch[u][0], u, x);
    }
    else
    {
        u = ch[u][0];
        while(ch[u][1])
        {
            u = ch[u][1];
        }
        newnode(ch[u][1], u, x);
    }
    while(u)
    {
        pushup(u);
        u = pre[u];
    }
    splay(tot - 1);
}
void del(ll x)
{
    int u = getpos(x);
    splay(u);
    int v =getpos( x + 1);
    splay(v);
    ch[v][0] = ch[u][0];
    pre[ch[u][0]] = v;
    pushup(v);
}
char cmd[20];
int main()
{
    int n;
    while(cin >> n)
    {
        tot = 0;
        newnode(root, 0, 0);
        size[0] = 0;
        ll x;
        newnode(ch[0][1], 0, inf);
        msum[1][1] = 0;
        while(n--)
        {
            cin >> cmd;
            if (cmd[0] == 'a')
            {
                cin >> x;
                int nex = getpos(x);
                insert(nex, x);
            }
            else if (cmd[0] == 'd')
            {
                cin >> x;
                del(x);
            }
            else if (cmd[0] == 's')
            {
                cout << msum[root][3] << endl;
            }
    //        debug();
        }
    }
}
/*


14
add 1
add 7
add 2
add 5
sum
add 6
add 8
add 9
add 3
add 4
add 10
sum
del 1
sum

*/
