#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 250000 + 100;
typedef long long ll;
typedef long double ld;

struct State
{
	State *par;
	State *go[26];
	vector<State*> ch;
	int val, mi, cnt, right;
	void init(int _val = 0)
	{
		par = 0, val = _val, cnt = mi = right = 0;
		memset(go, 0, sizeof(go));
	}
	int calc()
	{
		if (par == 0) return 0;
		return val - par->val;
	}
};
State *root, *last, *cur;
State nodePool[maxn];
State* newState(int val = 0)
{
	cur->init(val);
	return cur++;
}
void initSAM()
{
	cur = nodePool;
	root = newState();
	last = root;
}
void extend(int w)
{
	State *p = last;
	State *np = newState(p->val + 1);
	np->right = 1;
	while (p && p->go[w] == 0)
	{
		p->go[w] = np;
		p = p->par;
	}
	if (p == 0)
	{
		np->par = root;
	}
	else
	{
		State *q = p->go[w];
		if (q->val == p->val + 1)
		{
			np->par = q;
		}
		else
		{
			State *nq = newState(p->val + 1);
			memcpy(nq->go, q->go, sizeof(q->go));
			nq->par = q->par;
			q->par = nq;
			np->par = nq;
			while (p && p->go[w] == q)
			{
				p->go[w] = nq;
				p = p->par;
			}
		}
	}
	last = np;
}
int F[maxn];
int p;
int dfs(State * u)
{
	if (u->ch.empty())
	{
		F[u->val] = max(F[u->val], 1);
		return 1;
	}
	int ret = 0;
	for (State * v : u->ch)
	{
		ret += dfs(v);
	}
	F[u->val] = max(F[u->val], ret);
	return ret;
}

void init()
{
	memset(F, 0, sizeof(F));
}


char s[maxn];
int main()
{
	while (cin >> s)
	{
		initSAM();
		init();
		int n = strlen(s);
		for (int i = 0; i < n; i++)
		{
			extend(s[i] - 'a');
		}

		for (State * i = nodePool + 1; i < cur; i++)
		{
			cout << "p"<<i - nodePool << ": "<<(i->par - nodePool) << " "<<i->val<< endl;
			i->par->ch.push_back(i);
		}
		dfs(root);
		for (int i = n-1; i >= 0; i--)
		{
			F[i] = max(F[i + 1], F[i]);
		}
		for (int i = 0; i <= n; i++)
		{
			cout << F[i] << endl;
		}
	}
}