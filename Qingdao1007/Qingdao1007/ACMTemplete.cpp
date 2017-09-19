#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<memory.h>
#include<cstdio>
#include <cstring>
#define ll long long
#define inf 0x3f3f3f3f
#define For(i,x,y)	for(ll i=x;i<=y;++i)
using namespace std;
//inline ll read() { ll x = 0, f = 1; char ch = getchar();    while (ch<'0' || ch>'9') { if (ch == '-')	f = -1;	ch = getchar(); }	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }    return x*f; }
inline void write(ll x) { if (x<0)	x = -x, putchar('-');	if (x >= 10) write(x / 10);    putchar(x % 10 + '0'); }
void writeln(ll x) { write(x);    puts(""); }
struct data {
	ll num, color;
}t[1010];
ll a[1010], f[1010][1010], v[1010];
char s[1010];
void solve() {
	scanf("%s", s);
	int n = strlen(s);
	int now = 0;
	char pre = '?';
	memset(f, inf, sizeof(f));
	for (int i = 0; i < n; i++)
	{
		if (s[i] == pre)
		{
			t[now - 1].num++;
		}
		else
		{
			pre = s[i];
			t[now].color = s[i] - '0';
			t[now++].num = 1;
		}
	}
	for (int i = 0; i < now; i++)
	{
		f[i][i + 1] = 3 - t[i].num;
		f[i][i] = 0;
	}
	f[now][now] = 0;
	for (int len = 2; len <= now; len++)
	{
		for (int i = 0; i + len <= now; i++)
		{
			if (t[i].color == t[i + len - 1].color)
			{
				if (t[i].num + t[i + len - 1].num > 2)
				{
					f[i][i + len] = min(f[i][i + len], f[i + 1][i + len - 1]);
					if (!(t[i].num == 2 && t[i + len - 1].num == 2))
					for (int j = i + 1; j + 1< i + len; j++)
					{
						if (t[j].color == t[i].color&& !(t[j].num + t[i].num > 2 && t[j].num + t[i + len - 1].num > 2) )
							f[i][i + len] = min(f[i][i + len], f[i + 1][j] + f[j + 1][i + len - 1]);
					}
				}
				else
				{
					f[i][i + len] = min(f[i][i + len], f[i + 1][i + len - 1] + 1);
					for (int j = i + 1; j + 1< i + len; j++)
					{
						if (t[j].color == t[i].color && !(t[j].num + t[i].num > 2 && t[j].num + t[i + len - 1].num > 2))
							f[i][i + len] = min(f[i][i + len], f[i + 1][j] + f[j+1][i + len - 1]);
					}
				}
			}
			else
			{
				for (int j = i + 1; j < i + len; j++)
				{
					if (t[i].color == t[j].color || t[i + len - 1].color == t[j-1].color)
					f[i][i + len] = min(f[i][i + len], f[i][j] + f[j][i + len]);
				}
			}
		}
	}
	printf("%d\n", f[0][now]);
}
int main()
{
	int T;
	scanf("%d", &T);
	int kase = 1;
	while (T--)
	{
		printf("Case #%d: ", kase++);
		solve();
	}
	//system("pause");
}
