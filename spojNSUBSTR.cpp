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
const int maxn = 500000 + 100;
const int chsize = 26;
typedef long long ll;
typedef long double ld;
char s[maxn];
struct node
{
	int len, size;
	node *f, *ch[chsize];
}pool[maxn << 1], *head, *tail;

int tot;
void init()
{
	for (int i =0; i < maxn; i++)
    {
        pool[i].len = pool[i].size = 0;
        pool[i].f = 0;
        memset(pool[i].ch, 0, sizeof(pool[i].ch));
    }
	tot = 0;
	head = tail = &pool[0];
    tail->len = 0;
}
void add(int c, int m)
{
	node *p = tail, *np = &pool[++tot];
    np->size++;
	np->len = m;
	for (; p && !p->ch[c]; p = p->f)
	{
		p->ch[c] = np;
	}
    np->f = head;
	tail = np;
	if (!p)
		np->f = head;
	else if (p->len + 1 == p->ch[c]->len)
		np->f = p->ch[c];
	else
	{
		node * q = p->ch[c], *r = &pool[++tot];
		*r = *q;
        memcpy(r->ch, q->ch, sizeof(q->ch));
        r->size = 0;
		r->len = p->len + 1;
		q->f = np->f = r;
		for (; p && p->ch[c] == q; p = p->f)
		{
			p->ch[c] = r;
		}
	}
}

int cnt[maxn << 1];
int ans[maxn << 1];
int topo[maxn << 1];
int main()
{
	while (scanf("%s", s) != EOF)
	{
		memset(ans, 0, sizeof(ans));
		memset(cnt, 0, sizeof(cnt));

		int n = strlen(s);
		init();
		for (int i = 0; i < n; i++)
		{
			add(s[i] - 'a', i + 1);
		}

        /*for (int i = 1;i <= tot; i++)
        {
            cout << pool[i].len <<"_" <<pool[i].size<<" ";
        }
        cout << endl;*/
		for (int i = 1; i <= tot; i++) ++cnt[pool[i].len];
		for (int i = 1; i <= tot; i++) cnt[i] += cnt[i - 1];
		for (int i = 1; i <= tot; i++) topo[cnt[pool[i].len]--] = i;

		for (int i = tot; i >= 1; i--)
		{
			ans[pool[topo[i]].len] = max(ans[pool[topo[i]].len], pool[topo[i]].size);
			if (pool[topo[i]].f) pool[topo[i]].f->size += pool[topo[i]].size;
		}
		//for (int i = tot; i >= 1; i--) ans[pool[i].len] = max(ans[pool[i].len], pool[i].size);
		//for (int i = n - 1; i >= 0; i--) ans[i] = max(ans[i], ans[i + 1]);
		for (int i = 1; i <= n; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
}
//dsajoghiwoe
