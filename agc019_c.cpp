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
const int maxn = 200000 + 100;
typedef long long ll;
typedef long double ld;
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}
template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}


const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
inline void write()
{
    fwrite(bufout,sizeof(char),pout-bufout,stdout);
    pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(char *s)
{
    while(*s)
    {
        *(pout++) = *(s++);
        if(pout == pend) write();
    }
}
template <class T>
inline void out_int(T x) {
    if(!x)
    {
        out_char('0');
        return;
    }
    if(x < 0) x = -x,out_char('-');
    int len = 0;
    while(x)
    {
        outtmp[len++] = x%10+48;
        x /= 10;
    }
    outtmp[len] = 0;
    for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
    out_str(outtmp);
}
struct node
{
	int x, y;
	bool operator<(const node & rhs) const
	{
		return y < rhs.y;
	}
}ns[maxn];
int mx[maxn << 4];
vector<int> disc;
void pushup(int x)
{
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
void update(int q, int tar, int L = 0, int R = disc.size(), int o = 1)
{
	if (L + 1 == R)
	{
		mx[o] = tar;
		return;
	}
	const int mid = (L + R) / 2;
	if (q < mid)
	{
		update(q, tar, L, mid, o << 1);
	}
	else
	{
		update(q, tar, mid, R, o << 1 | 1);
	}
	pushup(o);
}
int query(int ql, int qr, int L = 0, int R = disc.size(), int o = 1)
{
	if (ql <= L && R <= qr)
	{
		return mx[o];
	}
	const int mid = (L + R) / 2;
	int ret = 0;
	if (ql < mid)
	{
		ret = query(ql, qr, L, mid, o << 1);
	}
	if (mid < qr)
	{
		ret = max(ret, query(ql, qr, mid, R, o << 1 | 1));
	}
	return ret;
}
const int up = 1e8 + 1;
int tot;
const ld pi = 3.14159265358979323846264;
int main()
{
  // freopen("data.in", "r", stdin);
	int x1, y1, x2, y2;
	int n;
	const ld diff = (ld)20 - (ld)5 * pi;
	const ld diff2 = 10 * pi - 20;
	// while (~scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n) != EOF)
  while(in(x1))
	{
    in(y1);in(x2);in(y2);in(n);
		tot = 0;
		ld ans = 0;
		if (x1 != x2 && y1 != y2)
		{
			bool xflip = false, yflip = false;
			if (x1 > x2)
			{
				xflip = true;
				x1 = up - x1;
				x2 = up - x2;
			}
			if (y1 > y2)
			{
				yflip = true;
				y1 = up - y1;
				y2 = up - y2;
			}
			for (int i = 0; i < n; i++)
			{
				// scanf("%d%d", &ns[tot].x, &ns[tot].y);
        in(ns[tot].x);in(ns[tot].y);
				if (xflip)
				{
					ns[tot].x = up - ns[tot].x;
				}
				if (yflip)
				{
					ns[tot].y = up - ns[tot].y;
				}
				if (x1 <= ns[i].x && ns[i].x <= x2 && y1 <= ns[i].y && ns[i].y <= y2)
				{
					tot++;
				}
			}
			for (int i = 0; i < tot; i++)
			{
				disc.push_back(ns[i].x);
			}
			sort(disc.begin(), disc.end());
			for (int i = 0; i < tot; i++)
			{
				ns[i].x = lower_bound(disc.begin(), disc.end(), ns[i].x) - disc.begin();
			}
			sort(ns, ns + tot);
			memset(mx, 0, sizeof(mx));
			for (int i = 0; i < tot; i++)
			{
				int trail = query(0, ns[i].x);
				update(ns[i].x, trail + 1);
			}
			int all = query(0, disc.size());
			ans = (ld)((x2 - x1 + y2 - y1) * 100 )- diff * (ld)all;
		}
		else
		{
			bool cross = false;
			for (int i = 0; i < n; i++)
			{
				// scanf("%d%d", &ns[i].x, &ns[i].y);
        in(ns[tot].x);in(ns[tot].y);
				if (x1 == ns[i].x && ns[i].x == x2 || y1 == ns[i].y && ns[i].y == y2)
				{
					cross = true;
				}
			}
			if (x1 > x2)
			{
				swap(x1, x2);
			}
			if (y1 > y2)
			{
				swap(y1, y2);
			}
			ans = (ld)((x2 - x1 + y2 - y1) * 100) + diff2;
		}
    printf("%.16Lf\n", ans);
		// cout.setf(ios::fixed);
		// cout.precision(15);
		// cout << ans << endl;
	}
}
