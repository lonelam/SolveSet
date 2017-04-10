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
const int maxn = 300000 + 100;

int n, q;
int tot, pre[maxn], ch[maxn][2], key[maxn], size[maxn], root;
bool flip[maxn];
void debug()
{
    for (int i = 0; i < tot; i++)
    {
        cout << "node# "<< i <<"chs: "<<ch[i][0] << " "<< ch[i][1] <<" "<< key[i] <<"flip:"<< flip[i] <<"size:"<<size[i] << endl;
    }
    cout << endl;
}
void pushdown(int r)
{
    if (!r) return;
    if (flip[r])
    {
        swap(ch[r][0], ch[r][1]);
        if (ch[r][0])
        {
            flip[ch[r][0]] = !flip[ch[r][0]];
        }
        if (ch[r][1])
        {
            flip[ch[r][1]] = !flip[ch[r][1]];
        }
        flip[r] = false;
    }
}


void pushup(int x)
{
    if (!x) return;
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
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
bool _splay_parent(int x, int & y, int goal)
{
    return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}
void splay(int x, int goal)
{
    pushdown(x);
    for (int y, z; _splay_parent(x, y, goal);)
    {
        if (_splay_parent(y, z, goal))
        {
            pushdown(z);
            pushdown(y);
            pushdown(x);
            int d = y == ch[z][0];
            if (x == ch[y][d])
                rotate(x, d ^ 1), rotate(x, d);
            else
                rotate(y, d), rotate(x, d);
        }
        else
        {
            pushdown(y), pushdown(x);
            rotate(x, x == ch[y][0]);
            break;
        }
    }
    pushup(x);
    if (goal == 0) root = x;
}

void newnode(int & pos, int father, int k)
{
    pre[tot] = father;
    ch[tot][0]=ch[tot][1] = 0;
    flip[tot] = false;
    key[tot] = k;
    size[tot] = 1;
    pos = tot++;
}
void build(int l, int r, int & p, int father)
{
    if (l > r)
    {
        return;
    }
    const int mid = (l + r)/ 2;
    newnode(p, father, mid);
    build(l, mid - 1,ch[p][0], p);
    build(mid + 1, r, ch[p][1], p);
    pushup(p);
}
void init()
{
    tot = 0;
    newnode(root, 0, 0);
    size[root] = 0;
    //newnode(ch[0][1], 0, 0);
    root = 1;
//    build(0, n + 1, ch[0][1], 0);
    for (int i = 0; i <= n; i++)
    {
        newnode(ch[i][1], i, i);
    }
    newnode(ch[tot - 1][1], tot - 1, tot - 1);
    for (int i = tot - 2; i > 0; i--)
    {
        pushup(i);
    }
}
int getkth(int u, int k)
{
    pushdown(u);
    if (size[ch[u][0]] == k - 1)
    {
        return u;
    }
    if (size[ch[u][0]] > k - 1)
    {
        return getkth(ch[u][0], k);
    }
    return getkth(ch[u][1], k - size[ch[u][0]] - 1);
}
void inverse(int l, int r)
{
    if (l == r)
    {
        return;
    }
//    debug();
    splay(getkth(root, r + 2 ), 0);
    splay(getkth(root, l), root);
    flip[ch[ch[root][0]][1]] ^= 1;
//    debug();
}
void insertnex(int u, int y)
{
//    cout << u <<"  "<< y<< endl;
    pushdown(u);
    if (!ch[u][1])
    {
    //    cout << "deg";
        ch[u][1] = y;
        pre[y] = u;
    //    cout << u << endl;
        while(u)
        {
            pushup(u);
            u = pre[u];
    //        debug();
        }
        return;
    }
    int p = ch[u][1];
    pushdown(p);
    while(ch[p][0])
    {
    //    cout << "weg";
    //    cout << p << endl;
        p = ch[p][0];
        pushdown(p);
    }
    ch[p][0] = y;
    pre[y] = p;
    while(p)
    {
        pushup(p);
        p = pre[p];
    }
}
void cut(int l, int r, int c)
{

        splay(getkth(root, r+2 ), 0);
        splay(getkth(root, l), root);
//        debug();
//    size[ch[root][0]] -= size[ch[ch[root][0]][1]];


    const int y = ch[ch[root][0]][1];
    ch[ch[root][0]][1] = 0;
    pushup(ch[root][0]);
    pushup(root);
//    debug();
    insertnex(getkth(root, c+1), y);
//    debug();
}

void inorder(vector<int> & ans, int u)
{
    //cout <<"weg";
    if (!u) return;
    pushdown(u);
    inorder(ans, ch[u][0]);
    ans.push_back(key[u]);
    inorder(ans, ch[u][1]);
}
int main()
{
    while(scanf("%d%d", &n, &q) !=EOF)
    {
        if (n == -1 && q == -1)
        {
            return 0;
        }
        init();
//        debug();
        char cmd[20];
        int A,B,C;
        while(q--)
        {
        //    cout << "fewg";
            scanf("%s", cmd);
    //        cout << "debug\n";
        //    cout << "weg\n";
            if (cmd[0] == 'C')
            {
            //    cout << "Weg";
                scanf("%d%d%d", &A,&B,&C);
                cut(A, B, C);
            }
            else
            {
                scanf("%d%d",&A,&B);
                inverse(A, B);
            }
        }
        vector<int> ans;
        inorder(ans, root);
        for (int i = 1; i + 1< ans.size(); i++)
        {
            printf("%d%c", ans[i], i + 2 == ans.size() ? '\n' : ' ');
        }
    }
}
