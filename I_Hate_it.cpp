#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 1000;
int a[maxn], key[maxn];
int ch[maxn][2], tot, pre[maxn], root;
int mx[maxn];
int n, q;
void debug()
{
    for (int i = 0; i < tot; i++)
    {
        cout << "node "<< i << " :"<<ch[i][0] <<"  " << ch[i][1] << " "<< mx[i] << endl;
    }
}
void pushup(int x)
{
    if (!x) return;
    mx[x] = max({key[x], mx[ch[x][0]], mx[ch[x][1]]});
}

void rotate(int x, int d)
{
//    cout << x <<" "<< d << endl;
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

bool _splay_parent(int x, int & y, int goal)
{
    return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}
void splay(int x, int goal)
{
    for (int y,z; _splay_parent(x, y, goal);)
    {
        if (_splay_parent(y, z, goal))
        {
            int d = y == ch[z][0];
            if (x == ch[y][d]) rotate(x, d ^ 1), rotate(x, d);
            else rotate(y, d), rotate(x, d);
        }
        else
        {
            rotate(x, x == ch[y][0]);
            break;
        }
    }
    pushup(x);

}
void newnode(int & pos, int fa, int k)
{
    pre[tot] = fa;
    mx[tot] = key[tot] = k;
    ch[tot][0] = ch[tot][1] = 0;
    pos = tot;
    tot++;
}
void init()
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    tot = 0;
    root = 0;
    mx[0] = key[0] = pre[0] = 0;
    newnode(root, 0, 0);
    for (int i = 0; i < n; i++)
    {
        newnode(ch[i][1], i, a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        pushup(i);
    }
//    tot = n + 1;
    newnode(ch[n][1], n, 0);
//    debug();
}
int query(int x, int y)
{
//    debug();
    if (x == y) return key[x];
    splay(x, 0);
//    debug();
    splay(y + 1, x);
//    debug();
    return max(key[x], mx[ch[y + 1][0]]);
}
void update(int x, int y)
{
//    debug();
    splay(x, 0);
    key[x] = y;
    pushup(x);
}
int main()
{
    while(cin >> n >> q)
    {
        init();
        while(q--)
        {
            string cmd;
            int A, B;
            cin >> cmd >> A >> B;
            if (cmd == "Q")
            {
                cout << query(A, B) << endl;
            }
            else
            {
                update(A, B);
            }
        }
    }
}
