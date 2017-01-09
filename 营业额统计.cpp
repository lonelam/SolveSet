#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 1000;

int pre[maxn], key[maxn], ch[maxn][2], root, tot;

void push_down(int r)
{
    if (!r) return;
}

void push_up(int x)
{

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
    push_up(y);
}

bool _splay_parent(int x, int & y, int goal)
{
    return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}

void splay(int x, int goal)
{
    push_down(x);
    for (int y, z ; _splay_parent(x, y, goal);)
    {
        if (_splay_parent(y, z, goal))
        {
            push_down(z);
            push_down(y);
            push_down(x);
            int d = y == ch[z][0];
            if (x == ch[y][d]) rotate (x, d ^ 1), rotate(x, d);
            else rotate(y, d), rotate(x, d);
        }
        else
        {
            push_down(y), push_down(x);
            rotate(x, x == ch[y][0]);
            break;
        }
    }
}
int newnode(int fa, int k)
{
    pre[tot] = fa;
    ch[tot][0] = ch[tot][1] = 0;
    key[tot] = k;
    return tot++;
}
void build()
{
    tot = 0;
    root = newnode(-1, -inf);
}

bool insert(int u, int k)
{
    if (k == key[u])
    {
        return false;
    }
    if (k > key[u])
    {
        if (ch[u][1]) return insert(ch[u][1], k);
        ch[u][1] = newnode(u, k);
        return true;
    }
    else
    {
        if (ch[u][0]) return insert(ch[u][0], k);
        ch[u][0] = newnode(u, k);
        return true;
    }
}
int getnex(int x)
{
    if (!ch[x][1])
    {
        return inf;
    }
    int p = ch[x][1];
    while(ch[p][0])
    {
        p = ch[p][0];
    }
    return key[p];
}
int getpre(int x)
{
    if (!ch[x][0])
    {
        return inf;
    }
    int p = ch[x][0];
    while(ch[p][1])
    {
        p = ch[p][1];
    }
    return key[p];
}
int main()
{
    int n;
    int tar;
    while(cin >> n)
    {
        build();
        int ans = 0;
        cin >> tar;
        ans += tar;
        insert(root, tar);
        for (int i = 1; i < n; i++)
        {
            cin >> tar;
            if (insert(root, tar))
            {
                splay(tot - 1, root);
                int val = inf;
                int ppre = getpre(ch[root][1]);
                int nnex = getnex(ch[root][1]);
                if ( ppre != inf)
                {
                    val = abs(ppre - tar);
                }
                if (nnex != inf)
                {
                    val = min(val, abs(nnex - tar));
                }
            //    cout << val << " ";
                if (val != inf)
                ans += val;
            }

        }
        cout << ans << endl;
    }
}
