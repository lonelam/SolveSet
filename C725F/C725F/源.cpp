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
	int prior, no;
};
struct msgcmp
{
	bool operator()(msg & a, msg & b)
	{
		if (a.prior < b.prior)
		{
			return true;
		}
		if (a.prior == b.prior)
			return a.no > b.no;
		return false;
	}
};
int main()
{
	int cnt = 0, t, a, b, id;
	char cmd[100];
	while (scanf("%d", &t) != EOF)
	{
		id = 1;
		priority_queue<msg, vector<msg>, msgcmp> q[4];
		while (t--)
		{
			scanf("%s", cmd);
			if (cmd[0] == 'I')
			{
				scanf("%d%d", &a, &b);
				q[a].push({ b, id++ });
			}
			if (cmd[0] == 'O')
			{
				scanf("%d", &a);
				if (q[a].empty())
				{
					printf("EMPTY\n");
				}
				else
				{
					msg cur = q[a].top();
					q[a].pop();
					printf("%d\n", cur.no);
				}
			}
		}
	}
}