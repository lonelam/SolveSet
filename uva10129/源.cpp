#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
/*
-----------Answered by Lonelam---------
*
*          ┌─┐       ┌─┐
*       ┌──┘ ┴───────┘ ┴──┐
*       │                 │
*       │       ───       │
*       │  ─┬┘       └┬─  │
*       │                 │
*       │       ─┴─       │
*       │                 │
*       └───┐         ┌───┘
*           │         │
*           │         │
*           │         │
*           │         └──────────────┐
*           │                        │
*           │                        ├─┐
*           │                        ┌─┘
*           │                        │
*           └─┐  ┐  ┌───────┬──┐  ┌──┘
*             │ ─┤ ─┤       │ ─┤ ─┤
*             └──┴──┘       └──┴──┘
*                 神兽保佑
*                 代码无BUG!
*/
using namespace std;
int par[26];
int in_degree[26],out_degree[26];
int rankk[26];


int fnd(int a)
{
	if (par[a] == a)
	{
		return a;
	}
		par[a] = fnd(par[a]);
		return par[a];

}

void _union(int a, int b)
{
	if (fnd(a) == fnd(b))
	{
		return;
	}
	if (rankk[fnd(a)] > rankk[fnd(b)])
	{
		rankk[par[a]] += rankk[par[b]];
		par[par[b]] = par[a];
		
	}
	else
	{
		rankk[par[b]] += rankk[par[a]];
		par[par[a]] = par[b];
	}
}

bool ans()
{
	int cnt = 0;//# of chars
	int thert;
	bool rtfound = false;
	bool morein = false, moreout = false;
	for (int i = 0; i < 26; i++)
	{
		if (in_degree[i] || out_degree[i])
		{
			cnt++;
			if (!rtfound)
			{
				rtfound = true;
				thert = fnd(i);
			}
			else if (thert != fnd(i))
			{
				return false;
			}
			switch (in_degree[i] - out_degree[i])
			{
			case 1:
				if (morein)
				{
					return false;
				}
				else
				{
					morein = true;
				}
				break;
			case -1:
				if (moreout)
				{
					return false;
				}
				else
				{
					moreout = true;
				}
				break;
			case 0:
				break;
			default:
				return false;
			}

		}
		
	}
	if (rankk[fnd(0)] != cnt)
	{
		return false;
	}
	return true;
}


int main()
{
	int t;
	while (cin >> t)
	{
		while (t--)
		{
			memset(in_degree, 0, sizeof(in_degree));
			memset(out_degree, 0, sizeof(out_degree));
			for (int i = 0; i < 26; i++)
			{
				par[i] = i;
				rankk[i] = 1;
			}
			int n;
			cin >> n;
			string tmp;
			while (n--)
			{
				cin >> tmp;
				int inwd = tmp.front() - 'a';
				int outwd = tmp.back() - 'a';
				_union(inwd, outwd);
				in_degree[inwd]++;
				out_degree[outwd]++;
			}
			if (ans())
			{
				cout << "Ordering is possible.\n";

			}
			else
			{
				cout << "The door cannot be opened.\n";
			}
		}
	}
}