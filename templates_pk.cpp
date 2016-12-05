//There are some templates for Beijing Regional
//I can assume that c++11 is unable using these templates.
//which is caused by the odd Judge Computer of POJ!!!

//Part 1
//Search

//DLX dancing link
//Accurate Cover
/* ***********************************************
Author        :kuangbin
Index starts from 1. 横纵坐标都从1开始
Be conducted by 外部调用 dance(0)
ansd should be 为 ans数组的size
the answer is in ans数组 array存了答案

************************************************ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<functional>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
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
#include<iostream>
#include<vector>
#include<cstring>
#include<functional>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
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








