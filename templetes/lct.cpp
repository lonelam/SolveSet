const int maxn = 300000 + 1000;
int pre[maxn], ch[maxn][2];
bool rev[maxn];
int n, q;
int key[maxn];
int lazy[maxn];
int sum[maxn];
int mx[maxn];
void debug()
{
    for (int i = 0; i <= n; i++)
    {
        cout << "node #"<< i << " chs:" << ch[i][0] <<" "<< ch[i][1] <<" , pre"<< pre[i] << ", key/ mx"<<key[i] <<" / "<<mx[i] <<endl;
    }
}
void push_down(int r)
{
    if (!r) return;
    if (rev[r])
    {
        swap(ch[r][0], ch[r][1]);
        if (ch[r][0]) rev[ch[r][0]] ^= 1;
        if (ch[r][1]) rev[ch[r][1]] ^= 1;
        rev[r] = 0;
    }
    if (lazy[r])
    {
        if (ch[r][0])
        {
            lazy[ch[r][0]] += lazy[r];
            key[ch[r][0]] += lazy[r];
    //        sum[ch[r][0]] += lazy[r];
            mx[ch[r][0]] += lazy[r];
        }
        if (ch[r][1])
        {
            lazy[ch[r][1]] += lazy[r];
            key[ch[r][1]] += lazy[r];
//            sum[ch[r][1]] += lazy[r];
            mx[ch[r][1]] += lazy[r];
        }
        lazy[r] = 0;
    }
}


void push_up(int x)
{
    if (!x) return;
//    sum[x] = sum[ch[x][0]] + sum[ch[x][1]] + key[x];
    mx[x] = max({mx[ch[x][0]], mx[ch[x][1]], key[x]});
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
    push_down(x);
    for (int y, z; _splay_parent(x, y, goal);)
    {
        if (_splay_parent(y, z, goal))
        {
            push_down(z);
            push_down(y);
            push_down(x);
            int d = y == ch[z][0];
            if (x == ch[y][d]) rotate(x, d ^ 1), rotate(x, d);
            else rotate(y, d), rotate(x, d);
        }
        else
        {
            push_down(y), push_down(x);
            rotate(x, x == ch[y][0]);
            break;
        }
    }
    push_up(x);
}

int access(int u)
{
    int v = 0;
    for (; u; u = pre[u])
    {
        splay(u);
        ch[u][1] = v;
        push_up(v = u);
    }
    return v;
}

void makeroot(int x)
{
    rev[access(x)] ^= 1;
    splay(x);
}

void link(int x, int y)
{
    makeroot(x);
    pre[x] = y;
}

void cut(int x, int y)
{
    makeroot(x);
    access(y);
    splay(y);
    pre[ch[y][0]] = 0;
    ch[y][0] = 0;
    push_up(y);
}
