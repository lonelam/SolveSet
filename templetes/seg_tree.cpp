const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int minv[maxn];
int v0;
int * pv;
void init(int n)
{
    v0 = 1;
    while(v0 < n)
    {
        v0 <<= 1;
    }
    pv = minv + v0;
}

//l, r, ql, qr ,all inclusive
int query(int o, int l, int r, int ql, int qr)
{
    int mid = l + (r - l) / 2;
    int ans = inf;
    if(ql <= l && r <= qr)
    {
        return minv[o];
    }
    if(ql <= mid)
    {
        ans = min(ans, query(o << 1, l, mid, ql, qr));
    }
    if(M < qr)
    {
        ans = min(ans, query(o * 2 + 1, mid + 1, r, ql, qr));
    }
    return ans;
}
//Point update; l, r inclusive
void update(int o, int l, int r, int p, int v);
{
    int mid = l + (r - l)/2;
    if(l == r)
    {
        minv[o] = v;
    }
    else
    {
        if(p <= mid)
        {
            update(o * 2, l, mid, p, v);
        }
        else
        {
            update(o * 2 + 1, mid + 1, r, p, v);
        }
        minv[o] = min(minv[o * 2 + 1], minv[o * 2]);
    }
}

void maintain(int o, int l, int r)
{
    int lc = o * 2;
    int rc = o * 2 + 1;
   // sumv[o] = minv[lc] = maxv[o] = 0;
    if(r > l)
    {
        sumv[o] = sumv[lc] + sumv[rc];
        minv[o] = min(minv[lc], minv[rc]);
        maxv[o] = max(maxv[lc], maxv[rc]);
    }
    minv[o] += addv[o];
    maxv[o] += addv[o];
    sumv[o] += addv[o] * (R - L + 1);
}

void update(int o, int l, int r, int v)
{
    int lc = o * 2;
    int rc = o * 2 + 1;
    if(y1 <= l && y2 >= r)
    {
        add[o] += v;
    }
    else
    {
        int mid = l +(r - l) / 2;
        if( y1 <= mid)
        {
            update(lc, l, mid);
        }
        if(y2 > mid)
        {
            update(rc, mid + 1, r);
        }
        maintain(o, l, r);
    }
}
int _min, _max, _sum;
void query(int o, int l, int r, int add, int y1, int y2)
{
    if(y1 <= l && y2 >= r)
    {
        _sum += sumv[o] + add * (r - l + 1);
        _min = min(_min, minv[o] + add);
        _max = max(_max, minv[o] + add);
    }
    else
    {
        int mid = l + (r - l) / 2;
        if(y1 <= mid)
        {
            query(o * 2, l, mid, add + addv[o], y1, y2);
        }
        if(y2 > mid)
        {
            query(o * 2 + 1, mid + 1, r, add + addv[o], y1, y2);
        }
    }
}

void update(int o, int l, int r)
{
    int lc = o * 2, rc = o * 2 + 1;
    if()
}
