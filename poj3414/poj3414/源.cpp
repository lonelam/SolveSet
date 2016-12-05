#include<iostream>
#include<queue>
#include<cstring>
#include<map>
#include<string>
#include<stack>
using namespace std;

struct state
{
	int a, b, t;
};
enum tranf {fill1,fill2,drop1,drop2,pour12,pour21};
struct state_trans
{
	state par;
	tranf method;
};
map<tranf, string> output;



int vol_a, vol_b, liq_c;
state_trans par[102][102];
bool used[102][102];
void bfs()
{
	queue<state> q;
	q.push({ 0,0,0 });
	state pos;
	memset(used, 0, sizeof(used));
	bool found = false;
	while (!q.empty()&& !found)
	{
		pos = q.front();
		q.pop();
		if (pos.a == liq_c || pos.b == liq_c)
		{
			found = true;
			continue;
		}
		used[pos.a][pos.b] = true;
		if (!used[vol_a][pos.b])
		{
			par[vol_a][pos.b] = { pos,fill1 };
			q.push({ vol_a,pos.b,pos.t + 1 });
		}
		if (!used[pos.a][vol_b])
		{
			par[pos.a][vol_b] = { pos,fill2 };
			q.push({ pos.a,vol_b,pos.t + 1 });
		}
		if (!used[0][pos.b])
		{
			par[0][pos.b] = { pos,drop1 };
			q.push({ 0,pos.b,pos.t + 1 });
		}
		if (!used[pos.a][0])
		{
			par[pos.a][0] = { pos,drop2 };
			q.push({ pos.a,0,pos.t + 1 });
		}
		if (pos.a + pos.b > vol_b)
		{
			if (!used[pos.a + pos.b - vol_b][vol_b])
			{
				par[pos.a + pos.b - vol_b][vol_b] = { pos,pour12 };
				q.push({ pos.a + pos.b - vol_b,vol_b,pos.t + 1 });
			}
		}
		else
		{
			if (!used[0][pos.a + pos.b])
			{
				par[0][pos.a + pos.b] = { pos,pour12 };
				q.push({ 0,pos.a + pos.b,pos.t + 1 });
			}
		}
		if (pos.a + pos.b > vol_a)
		{
			if (!used[vol_a][pos.a + pos.b - vol_a])
			{
				par[vol_a][pos.a + pos.b - vol_a] = { pos,pour21 };
				q.push({ vol_a,pos.a + pos.b - vol_a,pos.t + 1 });
			}
		}
		else
		{
			if (!used[pos.a+pos.b][0])
			{
				par[pos.a + pos.b][0] = { pos,pour21 };
				q.push({ pos.a + pos.b,0,pos.t + 1 });
			}
		}
	}
	if (found)
	{
		cout << pos.t << endl;
		stack<string> out;
		while (pos.a != 0 || pos.b != 0 || pos.t != 0)
		{
			out.push(output[par[pos.a][pos.b].method]);
			pos = par[pos.a][pos.b].par;
		}
		while (!out.empty())
		{
			cout << out.top();
			out.pop();
		}
	}
	else
	{
		cout << "impossible\n";
	}
}
int main()
{
	output.insert({ fill1, "FILL(1)\n" });
	output.insert({ fill2,"FILL(2)\n" }); output.insert({ drop1,"DROP(1)\n" }); output.insert({ drop2, "DROP(2)\n" }), output.insert({ pour12,"POUR(1,2)\n" }), output.insert({ pour21,"POUR(2,1)\n" });
	while (cin >> vol_a >> vol_b >> liq_c)
	{
		bfs();
	}
}