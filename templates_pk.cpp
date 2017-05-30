//There are some templates for Beijing Regional
//I can assume that c++11 is unable using these templates.
//which is caused by the odd Judge Computer of POJ!!!

//Part 1
//Search

//DLX dancing link
//Accurate Cover
/* ***********************************************
Index starts from 1. 横纵坐标都从1开始
Be conducted by 外部调用 dance(0)
ansd should be 为 ans数组的size
the answer is in ans数组 array存了答案
************************************************ */
const int maxnode = 100010;
const int MaxM = 1010;
const int MaxN = 1010;
//精确覆盖
struct DLX
{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[MaxN], S[MaxM];
    int ansd, ans[MaxN];
    void init(int _n,int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0;i <= m;i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for(int i = 1;i <= n;i++)
            H[i] = -1;
    }
    void Link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    void remove(int c)
    {
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for(int i = D[c];i != c;i = D[i])
            for(int j = R[i];j != i;j = R[j])
            {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
    }
    void resume(int c)
    {
        for(int i = U[c];i != c;i = U[i])
            for(int j = L[i];j != i;j = L[j])
                ++S[Col[U[D[j]]=D[U[j]]=j]];
        L[R[c]] = R[L[c]] = c;
    }
    //d为递归深度
    bool Dance(int d)
    {
        if(R[0] == 0)
        {
            ansd = d;
            return true;
        }
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        remove(c);
        for(int i = D[c];i != c;i = D[i])
        {
            ans[d] = Row[i];
            for(int j = R[i]; j != i;j = R[j])remove(Col[j]);
            if(Dance(d+1))return true;
            for(int j = L[i]; j != i;j = L[j])resume(Col[j]);
        }
        resume(c);
        return false;
    }
};

DLX g;



//重复覆盖
//Multiple Cover
/* ***********************************************
Author        :kuangbin
横纵坐标都从1开始
外部调用dance(0)
ansd为ans数组的size
ans数组存了答案
*************************************************/
const int inf = 0x3f3f3f3f;
const int maxnode = 100010;
const int maxn = 1010;
const int MaxN = 1010;

struct DLX
{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode];
	int Row[maxnode], Col[maxnode];
	int H[MaxN], S[MaxN];
	int ansd;
	int K;
	void init(int _n, int _m)
	{
		n = _n;
		ansd = inf;
		m = _m;
		for (int i = 0; i <= m; i++)
		{
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
			S[i] = 0;
		}
		R[m] = 0;
		L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)
		{
			H[i] = -1;
		}

	}
	void Link(int r, int c)
	{
		S[Col[++size] = c]++;
		Row[size] = r;
		U[size] = U[c];
		D[size] = c;
		D[U[c]] = size;
		U[c] = size;
		if (H[r] == -1)
		{
			H[r] = R[size] = L[size] = size;
		}
		else
		{
			R[size] = H[r];
			L[size] = L[H[r]];
			R[L[size]] = size;
			L[H[r]] = size;
		}
	}
	void remove(int c)
	{
		for (int i = D[c]; i != c; i = D[i])
		{
			L[R[i]] = L[i];
			R[L[i]] = R[i];
		}
	}
	void resume(int c)
	{
		for (int i = U[c]; i != c; i = U[i])
		{
			R[L[i]] = L[R[i]] = i;
		}
	}
	bool v[maxnode];
	int h()
	{
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c]) v[c] = true;
		for (int c = R[0]; c != 0; c = R[c])
		{
			if (v[c])
			{
				ret++;
				for (int i = D[c]; i != c; i = D[i])
				{
					for (int j = R[i]; j != i; j = R[j])
					{
						v[Col[j]] = false;
					}
				}
			}
		}
		return ret;
	}
	bool dance(int d)
	{
		if (d + h() > ansd)
		{
			return false;
		}
		if (R[0] == 0)
		{
			if (ansd > d) ansd = d;
			return true;
		}
		bool ret = false;
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
		{
			if (S[i] < S[c])
			{
				c = i;
			}
		}
		for (int i = D[c]; i != c; i = D[i])
		{
			remove(i);
			for (int j = R[i]; j != i; j = R[j])
			{
				remove(j);
			}
			if (dance(d + 1)) ret = true;
			for (int j = L[i]; j != i; j = L[j])
			{
				resume(j);
			}
			resume(i);
		}
		return ret;
	}
	void Dance(int d)
	{
		if (d + h() >= ansd)return;
		if (R[0] == 0)
		{
			if (d < ansd)ansd = d;
			return;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		for (int i = D[c]; i != c; i = D[i])
		{
			remove(i);
			for (int j = R[i]; j != i; j = R[j])remove(j);
			Dance(d + 1);
			for (int j = L[i]; j != i; j = L[j])resume(j);
			resume(i);
		}
	}
};

DLX gg;

//Dijkstra, no need to explain, just in case
typedef pair<int, int> pii;
const int maxn = 10005;
int dis[maxn];
vector<int> G[maxn];
const int inf = 0x3f3f3f3f;
int ecnt;
struct edge
{
	int from, to, cost;
};
edge es[maxn * maxn];

void dijkstra(int s)
{
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0, s});
	dis[s] = 0;
	while (!q.empty())
	{
		pii c = q.top();
		q.pop();
		int cur = c.second;

		for (int i = 0; i < G[cur].size(); i++)
		{
			edge & e = es[G[cur][i]];
			if (dis[e.to] > dis[e.from] + e.cost)
			{
				dis[e.to] = dis[e.from] + e.cost;
				q.push({dis[e.to],e.to});
			}
		}

	}
}
void init(int n)
{
    ecnt = 0;
    for(int i = 0; i < n; i++)
    {
        G[i].clear();
    }
    memset(dis, inf, sizeof(dis));
}
void addedge(int u, int v, int w)
{
    es[ecnt] = {u, v, w};
    G[u].push_back(ecnt++);
}


//Part2
//Graph Algorithms
//Some Maxi(Mini)mize Tools

//Bidirectional Connected Component

int pre[maxn], iscur[maxn], bccno[maxn], dfs_clock, bcc_cnt;
vector<int> G[maxn], bcc[maxn];

stack<edge> s;
int dfs(int u, int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i = 0 ; i < G[u].size();i++)
    {
        int v= G[u][i];
        edge e = (edge) {u, v};
        if(!pre[v])
        {
            s.push(e);
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if(lowv >= pre[u])
            {
                iscut[u] = true;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;)
                {
                    edge x = s.top(); s.pop();
                    if(bccno[x.u] != bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u] = bcc_cnt;
                    }
                    if(bccno[x.v] != bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v] = bcc_cnt;
                    }
                    if(x.u == u && x.v == v)
                    {
                        break;
                    }
                }
            }
            else if(pre[v] < pre[u] && v != fa)
            {
                S.push(e);
                lowu = min(lowu, pre[v]);
            }
        }
        if(fa < 0 && child == 1)
        {
            iscut[u] = 0;
        }
    }
    return lowu;
}
void find_bcc(int u)
{
    memset(pre, 0, sizeof(pre));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    dfs_clock = bcc_cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(!pre[i]) dfs(i, -1);
    }
}

//
//TODO : Strong Connect Component // looking to Stanford notebook


// Binary indexed tree for interval queries
//looking to Stanford notebook


//find cuts


int dfs_clock;
int dfs(int u, int fa)
{
    int lowu = pre[u] = ++dfs_clock;//
    int child = 0;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!pre[v])//have not been visited
        {
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if(lowv >= pre[u])
            {
                iscut[u] = true;
            }
        }
        else if(pre[v] < pre[u] && v != fa)
        {
            lowu = min(lowu, pre[u]);
        }
    }
    if(fa < 0 && child == 1)
    {
        iscut[u] = 0;
    }
    low[u] = lowu;
    return lowu;
}

//splay tree

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
} 5 


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

// FFT

typedef long long ll;
typedef double ld;
int n;
int bmask, blen;
const ld pi = M_PI;
void init()
{
	bmask = 1;
	blen = 1;
	while (bmask < n)
	{
		++blen;
		bmask <<= 1;
	}
	bmask <<= 1;
}
inline int bitrev(int x)
{
	int r = 0;
	for (int i = 0; i < blen; i++)
	{
		r <<= 1;
		r |= x & 1;
		x >>= 1;
	}
	return r;
}

complex<ld> A[maxn], B[maxn], C[maxn];
void FFT(complex<ld> * alpha, int r = 1)
{
	for (int i = 0; i < bmask; i++)
	{
		int revi = bitrev(i);
		if (i < revi) swap(alpha[i], alpha[revi]);
	}
	for (int k = 2; k <= bmask; k <<= 1)
	{
		int h = k >> 1;
		complex<ld> omega_n(cos(2.0 * pi / k * r), sin(2.0 * pi / k * r));
		for (int i = 0; i < bmask; i += k)
		{
			int hi = h + i;
			complex<ld> omega(1,0);
			for (int j = i; j < hi; j++)
			{
				complex<ld> t = alpha[j + h] * omega;
				alpha[j + h] = alpha[j] - t;
				alpha[j] = alpha[j] + t;
				omega *= omega_n;
			}
		}
	}
	if (r == -1)
	{
		for (int i = 0; i < bmask; i++)
		{
			alpha[i] /= (ld)bmask;
		}
	}
}



//Dinic Net flow

typedef long long ll;
struct edge
{
    int u, v;
    ll cap, flow;
    edge() {}
    edge(int u, int v, ll cap):u(u), v(v), cap(cap), flow(0){}
};

struct dinic
{
    int n;
    vector<edge> es;
    vector<vector<int> > g;
    vector<int> d, pt;
    dinic(int n) : n(n), es(0), g(n), d(n), pt(n) {}
    void addedge(int u, int v, ll cap)
    {
        if (u != v)
        {
            es.push_back(edge(u, v, cap));
            g[u].push_back(es.size() - 1);
            es.push_back(edge(v, u, 0));
            g[v].push_back(es.size() - 1);
        }
    }
    bool bfs(int S, int T)
    {
        queue<int> q;
        q.push(S);
        fill (d.begin(), d.end(), n + 1);
        d[S] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == T) break;
            for (int k = 0; k < g[u].size(); k++)
            {
                edge & e = es[g[u][k]];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1)
                {
                    d[e.v] = d[e.u] + 1;
                    q.push(e.v);
                }
            }
        }
        return d[T] != n + 1;
    }

    ll dfs(int u, int T, ll flow = -1)
    {
        if (u == T || flow == 0) return flow;
        for (int & i = pt[u]; i < g[u].size();++i)
        {
            edge & e = es[g[u][i]];
            edge & oe = es[g[u][i] ^ 1];
            if (d[e.v] == d[e.u] + 1)
            {
                ll amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (ll pushed = dfs(e.v, T, amt))
                {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    ll maxflow(int S, int T)
    {
        ll total = 0;
        while(bfs(S,T))
        {
            fill(pt.begin(), pt.end(), 0);
            while(ll flow = dfs(S, T))
                total += flow;
        }
        return total;
    }
};

//AC 自动机

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;

/*
基于HDOJ 2222 的 AC自动机
文本串对多个模板串的查找
*/

const int maxn=610000;
const int chsize = 26;
int ch[maxn][chsize],fail[maxn],flg[maxn], vis[maxn];
int root,sz;
char str[1000100];

int newnode()
{
	memset(ch[sz],-1,sizeof(ch[sz]));
	flg[sz++]=0;
	return sz-1;
}

void init()
{
	sz=0;
	root=newnode();
}

void insert(char str[])
{
	int len=strlen(str);
	int now=root;
	for(int i=0;i<len;i++)
	{
		int& temp=ch[now][str[i]-'a'];
		if(temp==-1) temp=newnode();
		now=temp;
	}
	flg[now]++;
}

void build()
{
	queue<int> q;
	fail[root]=root;

	for(int i=0;i<26;i++)
	{
		int& temp=ch[root][i];
		if(temp==-1) temp=root;
		else
		{
			fail[temp]=root;
			q.push(temp);
		}
	}
	while(!q.empty())
	{
		int now=q.front(); q.pop();
		//// 嵌套串
		if(flg[fail[now]]) flg[now]++;
		for(int i=0;i<chsize;i++)
		{
			if(ch[now][i]==-1)
				ch[now][i]=ch[fail[now]][i];
			else
			{
				fail[ch[now][i]]=ch[fail[now]][i];
				q.push(ch[now][i]);
			}
		}
	}
}

int query(char str[])
{
    int len=strlen(str);
    int now=root;
    int ret=0;
	memset(vis, 0,sizeof(vis));
    for(int i=0;i<len;i++)
    {
        now=ch[now][str[i]-'a'];
        int temp=now;
        while(temp!=root&&~flg[temp] && !vis[temp])
        {
            ret+=flg[temp];
			//one enough
            flg[temp]=-1;
			vis[temp] = 1;
            temp=fail[temp];
        }
    }
    return ret;
}
