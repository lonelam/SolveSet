#include<iostream>


using namespace std;


typedef int State[9];
const int maxstate = 1000000;
State st[maxstate], goal;
int dist[maxstate];

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
int vis[362880], fact[9];
void init_lookup_table()
{
	fact[0] = 1;
	for (int i = 1; i < 9; i++)
	{
		fact[i] = fact[i - 1] * i;
	}
}

int try_to_insert(int s)
{
	int code = 0;
	for (int i = 0; i < 9; i++)
	{
		int cnt = 0;
		for (int j = i + 1; j < 9; j++)
		{
			if (st[s][j] < st[s][i])
			{
				cnt++;
			}
		}
		code += fact[8 - i] * cnt;
	}
	if (vis[code])
	{
		return 0;
	}
	return vis[code] = 1;
}
int bfs()
{
	init_lookup_table();
	int front = 1, rear = 2;
	while (front < rear)
	{
		State & s = st[front];
		if (memcmp(goal, s, sizeof(s)) == 0)
		{
			return front;
		}
		int z;
		for (z = 0; z < 9; z++)
		{
			if (!s[z])
			{
				break;
			}
		}
		int x = z / 3, y = z % 3;
		for (int d = 0; d < 4; d++)
		{
			int tx = x + dx[d];
			int ty = y + dy[d];
			int tz = tx * 3 + ty;
			if (tx >= 0 && tx < 3 && ty >= 0 && ty < 3)
			{
				State & t = st[rear];
				memcpy(&t, &s, sizeof(s));
				t[tz] = s[z];
				t[z] = s[tz];
				dist[rear] = dist[front] + 1;
				if (try_to_insert(rear))
				{
					rear++;
				}
			}
		}
		front++;
	}
	return 0;
}
