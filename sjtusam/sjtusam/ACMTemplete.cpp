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
const int maxn = 100000 + 100;
const int chsize = 26;
typedef long long ll;
typedef long double ld;
struct node
{
	int len;
	node * f, *ch[chsize];
}pool[maxn << 1], *init, *tail;
int tot;
void initial()
{
	tot = 0;
	init = tail = &pool[0];
	memset(pool, 0, sizeof(pool));
}
void add(int c)
{
	node *p = tail, *np = &pool[++tot];
	np->len = p->len + 1;
	for (; p && !p->ch[c]; p = p->f)
	{
		p->ch[c] = np;
	}
	tail = np;
	if (!p) np->f = init;
	else if (p->ch[c]->len == p->len + 1) np->f = p->ch[c];
	else
	{
		node *q = p->ch[c], *r = &pool[++tot];
		*r = *q;
		r->len = p->len + 1;
		q->f = np->f = r;
		for (; p && p->ch[c] == q; p = p->f)
		{
			p->ch[c] = r;
		}
	}
}

char s[maxn];

int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			
			scanf("%s", s);
			initial();
			int len = strlen(s);
			for (int j = 0; j < 2; j++)
				for (int i = 0; i < len; i++)
				{
					add(s[i] - 'a');
				}
			node *p = init;
			
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < chsize; j++)
				{
					if (p->ch[j])
					{
						p = p->ch[j];
						break;
					}
				}
			}
			printf("%d\n", p->len - len + 1);
		}
	}
}