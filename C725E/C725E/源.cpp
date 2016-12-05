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
	int prior, val,no;
	string s;
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
		    return a.no > b.no;
		return false;
	}
};
int main()
{
	char ss[100], cmd[100];
	int para, prio;
	int cnt = 0;
	priority_queue<msg, vector<msg>, msgcmp> q;
	while (scanf("%s", cmd)!=EOF)
	{
		if (cmd[0] == 'G')
		{
			if (q.empty())
			{
				printf("EMPTY QUEUE!\n");
			}
			else
			{
				msg cur = q.top();
				q.pop();
				printf("%s %d\n", cur.s.c_str(), cur.val);
			}
		}
		else if (cmd[0] == 'P')
		{
			scanf("%s%d%d", ss, &para, &prio);
			q.push({ prio, para,cnt++, ss });
		}
	}
}