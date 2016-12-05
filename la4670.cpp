#include<bits/stdc++.h>
using namespace std;
struct trie
{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	trie() { sz = 1; memset(ch[0], 0, sizeof(ch[0])) }
	int idx (char c) { return c -'a';}
	void insert(
}
void find(char * T)
{
	int n = strlen(T);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		int c = idx(T[i]);
		while(j && !ch[j][c] ) j = f[j];
		j = ch[j][c];
		if (val[j] ) print(i, j);
		else if (last[j]) print (i, last[i]);
	}
}

void print(int j )
{
	if (j)
	{
		printf("%d: %d\n", j, val[j]);
		print(last[j]);
	}
}

int getFail()
{
	queue<int> q;
	f[0] = 0;
	for (int c = 0; c < sigma_size; c++)
	{
		int u = ch[0][c];
		if (u) { f[u] = 0; q.push(u); last[u] = 0;}
	}
	while (!q.empty())
	{
		int r = q.front(); q.pop();
		for (int c = 0; c < sigma_size; c++)
		{
			int u = ch[r][c];
			if (!u) continue;
			q.push(u);
			int v = f[r];
			while( v && !ch[v][c]) v = f[v];
			f[u] = ch[v][c];
			last[u] = val[f[u]] ? f[u] : last[f[u]] ;
		}
	}
}


