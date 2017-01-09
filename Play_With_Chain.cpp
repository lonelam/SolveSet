#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 1000;
int ch[maxn][2];
int pre[maxn];
bool flipped[maxn];
int size[maxn];
//int L[maxn], R[maxn];
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
    ch[x]d] = y;
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
int newnode()
{

}
void build()
