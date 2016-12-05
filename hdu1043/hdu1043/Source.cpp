
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
using namespace std;

const int w = 9;
struct state
{
	int x[10];
	int zpos;
} cur;
const int maxc = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 + 5;
//int dis[maxc];
const int inf = 0x3f3f3f3f;
int pre[maxc];
char ope[maxc];
int fact[w];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char oper[] = { 'r','l','u','d' };
void init()
{
	fact[0] = 1;
	for (int i = 1; i < w; i++)
	{
		fact[i] = fact[i - 1] * (i);
	}
}

int encode(state x)
{
	int ans = 1;
	for (int i = 0; i < w; i++)
	{
		int rev = 0;
		for (int j = i + 1; j < w; j++)
		{
			if (x.x[j] > x.x[i])
			{
				rev++;
			}
		}
		ans += rev * fact[w - i - 1];
	}
	return ans;
}
//
//state decode(int x)
//{
//	memset(vis, 0, sizeof(vis));
//	state ans;
//	for (int i = 0; i < w; i++)
//	{
//		int rev = x / fact[w - i - 1];
//		int kur = w - 1;
//		while (rev)
//		{
//			if (!vis[kur])
//			{
//				//	vis[kur] = true;
//				rev--;
//			}
//			kur--;
//		}
//		while (vis[kur] && kur)
//		{
//			kur--;
//		}
//		vis[kur] = true;
//		ans.x[i] = kur;
//		x %= fact[w - i - 1];
//	}
//	return ans;
//}
int g;
bool bfs(state inp)
{
	//	map<int, char> ope;
	//map<int, int> pre;
	//	int cnt = 0;
	int s = encode(inp);

	queue<state> q;
	q.push(inp);
	//set<int> vis;
	//memset(dis, inf, sizeof(dis));
	//dis[s] = 0;
	//vis.insert(s);
	memset(pre, -1, sizeof(pre));
	//bool found = false;
	while (!q.empty())
	{

		state cur = q.front();
		int cod = encode(cur);
		if (cod == g)
		{
			return true;
		}
		q.pop();
		state &cr = cur;
		int zpos = cr.zpos;

		int x = zpos / 3;
		int y = zpos % 3;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (tx >= 0 && tx < 3 && ty >= 0 && ty < 3)
			{
				int tpos = tx * 3 + ty;
				state ts = cr;
				ts.zpos = tpos;
				swap(ts.x[zpos], ts.x[tpos]);
				int tcode = encode(ts);
				if (pre[tcode] == -1)
				{
					//dis[tcode] = dis[cur] + 1;

					pre[tcode] = cod;
					ope[tcode] = oper[i];
					q.push(ts);
					if (tcode == g)
					{
						return true;
					}
				}
			}
		}
		
	}
	if (q.empty())
	{
		printf("unsolvable\n");
		return false;
	}
	return true;
}

void print(state inp)
{
	int it = g;
	int s = encode(inp);
	string res;
	while (it != s)
	{
		res.push_back(ope[it]);
		it = pre[it];
	}
	reverse(res.begin(), res.end());
	printf("%s\n",res.c_str());
	return;
	
}
int main_TLE()
{

	init();
	state goal;
	for (int i = 1; i < w; i++)
	{
		goal.x[i - 1] = i;
	}
	goal.x[w - 1] = 0;
	g = encode(goal);
//	string s;
	//int n;
	state st;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	/*state p;
	for (int i = 0; i < w; i++)
	{
		p.x[i] = i;
	}
	while (true)
	{
		for (int i = 0; i < w; i++)
		{
			cout << p.x[i] << " ";
		}
		cout << endl;
		if (bfs(p)) print(p);
		next_permutation(p.x, p.x + w);
	}*/
	char s[1000];
	while (scanf("%s",s)!=EOF)
	{
		if (s[0] == 'x')
		{
			st.x[0] = 0;
			st.zpos = 0;
		}
		else
		{
			st.x[0] = s[0] - '0';
		}
		for (int i = 1; i < w; i++)
		{
			scanf("%s", s);
			if (s[0] == 'x')
			{
				st.x[i] = 0;
				st.zpos = i;
			}
			else
			{
				st.x[i] = s[0] - '0';
			}
		}
		if (bfs(st))
		{
			print(st);
		}
	}
	return 0;
}