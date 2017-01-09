#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 1000;
int ch[maxn][2], pre[maxn];
int size[maxn], keya[maxn];
int tot;
int mxa[maxn];
int root;
void debug()
{
    for (int i = 0; i < tot; i++)
    {
        cout << "node " << i << ": chs:" << ch[i][0] <<" "<< ch[i][1] << "pre:  "<< pre[i] << " key: " << keya[i] <<" size: " << size[i]<< endl;
    }
    cout << endl;
}
void push_up(int x)
{
    if (!x) return;
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    mxa[x] = max({mxa[ch[x][0]], mxa[ch[x][1]], keya[x]});
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

void splay(int x, int goal = 0)
{
//    push_down(x);
    for (int y, z; _splay_parent(x, y, goal);)
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
    if (goal == 0)
    {
        root = x;
    }
}

void newnode(int & pos,int fa, int a)
{
    keya[tot] = mxa[tot] = a;
    size[tot] = 1;
    ch[tot][0] = ch[tot][1] = 0;
    pre[tot] = fa;
    pos = tot++;
}

int getpos(int a, int c, int u = root)
{
    if (c > size[ch[u][0]] && a > mxa[ch[u][0]] && a > keya[u])
    {
        return getpos(a, c - size[ch[u][0]] - 1, ch[u][1]);
    }

    if ( a > mxa[ch[u][0]] && (c == size[ch[u][0]]|| (c > size[ch[u][0]]  && a < keya[u])))
    {
    //    debug();
    //    cout <<"debug U : "<< u << "geted!"<<endl;
        return u;
    }
    return getpos(a, c, ch[u][0]);
}
void insertpre(int u, int a)
{
    if (!ch[u][0])
    {
        newnode(ch[u][0], u, a);
        while(u)
        {
            push_up(u);
            u = pre[u];
        }
        return;
    }
    int p = ch[u][0];
    while(ch[p][1])
    {
        p = ch[p][1];
    }
    newnode(ch[p][1], p, a);
    //ifbug position
    while(p)
    {
        push_up(p);
    //    cout << "deubg"<<p << endl;
        p = pre[p];
    }
//    splay(ch[p][1]);
}
void inorder(vector<int> & ans, int u)
{
//    cout <<"???";
//    cout << u << "  ";
    if (ch[u][1])
    {
        inorder(ans, ch[u][1]);
    }
    ans.push_back(u - 1);
    if (ch[u][0])
    {
        inorder(ans, ch[u][0]);
    }
}
int main()
{
//    ios::sync_with_stdio(false);
    int n;
    int aa,cc;
    while(scanf("%d",&n) !=EOF)
    {
        tot = 0;
        newnode(root, 0,0);
        size[0] = 0;
        newnode(ch[0][1], 0, inf);
        root = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&aa, &cc);
        //    cin >> aa >> cc;
            int tartar = getpos(aa, cc, root);
    //        debug();

            insertpre(tartar, aa);
            splay(tot - 1);
    //        debug();
        }
        vector<int> ans;
//        debug();
    //    debug();
        inorder(ans, root);
        for (int i = 1; i < ans.size(); i++)
        {
            printf("%d ", ans[i]);
//            cout << ans[i] << " ";
        }
//        cout << endl;
    }
}
