#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<cstdio>
#include<functional>
#include<vector>
#include<utility>
#include<string>
using namespace std;
struct msg
{
	int prior;
	string no;
};
struct msgcmp
{
	bool operator()(msg & a, msg & b)
	{
		if (a.prior > b.prior)
		{
			return true;
		}
		if (a.prior == b.prior)
			return a.no < b.no;
		return false;
	}
};
int main()
{
	char cmd[100];
	char name[1000];
	int n, m, xi,xj, rp;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		vector <priority_queue<msg, vector<msg>, msgcmp> > train(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &xi);
			while (xi--)
			{
				scanf("%s%d", name, &rp);
				train[i].push({ rp, string(name) });
			}
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%s", cmd);
			if (cmd[0] == 'J')
			{
				scanf("%d%d", &xi, &xj);
				while (!train[xj- 1].empty())
				{
					train[xi-1].push(train[xj-1].top());
					train[xj-1].pop();
				}
			}
			else if (cmd[0] == 'G' && cmd[4] == 'N')
			{
				scanf("%d%s%d", &xi, name, &rp);
				train[xi-1].push({ rp, string(name) });
			}
			else if (cmd[0] == 'G' && cmd[4] == 'U')
			{
				scanf("%d", &xi);
				if (!train[xi-1].empty())
				{
					msg cur = train[xi-1].top();
					train[xi - 1].pop();
					printf("%s\n", cur.no.c_str());
				}
			}
		} 
	}
}