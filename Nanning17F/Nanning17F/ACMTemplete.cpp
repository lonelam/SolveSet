#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;
#define INF 0x3f3f3f3f  
#define MAX 1100  
#define LL rt*2  
#define RR rt*2+1  
typedef long long ll;
struct segment //保存矩形上下边界  
{
	ll l, r, h; //左右横坐标，纵坐标  
	int f; //-1为下边界，1为上边界  
} ss[2 * MAX];
struct node //线段树节点  
{
	int l, r;
	int cover; //该节点被覆盖的情况  
	double len; //该区间被覆盖的总长度  
} tt[2 * MAX * 4];
ll pos[2 * MAX];
int nums;

int cmp(struct segment a, struct segment b)
{
	return a.h < b.h;
}

void build(int a, int b, int rt)
{
	tt[rt].l = a;
	tt[rt].r = b;
	tt[rt].cover = 0;
	tt[rt].len = 0;
	if (a == b)
		return;
	int mid = (tt[rt].l + tt[rt].r) / 2;
	build(a, mid, LL);
	build(mid + 1, b, RR);
}

int binary(double key, int low, int high)
{
	while (low <= high)
	{
		int mid = (low + high) >> 1;
		if (pos[mid] == key)
			return mid;
		else if (key < pos[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

void pushup(int rt)
{
	if (tt[rt].cover) //非0，已经被整段覆盖  
		tt[rt].len = pos[tt[rt].r + 1] - pos[tt[rt].l];
	else if (tt[rt].l == tt[rt].r) //已经不是一条线段  
		tt[rt].len = 0;
	else //是一条线段但是又没有整段覆盖，那么只能从左右孩子的信息中获取  
		tt[rt].len = tt[LL].len + tt[RR].len;
}

void update(int a, int b, int val, int rt)
{
	if (tt[rt].l == a && tt[rt].r == b) //目标区间  
	{
		tt[rt].cover += val; //更新这个区间被覆盖的情况,//插入或删除操作直接让cover[]+=flag。当cover[]>0时，该区间一定有边覆盖。  
		pushup(rt);  //更新这个区间被覆盖的总长度  
		return;
	}
	int mid = (tt[rt].l + tt[rt].r) / 2;
	if (b <= mid) //只访问左孩子  
		update(a, b, val, LL);
	else if (a > mid) //只访问有孩子  
		update(a, b, val, RR);
	else //左右都要访问  
	{
		update(a, mid, val, LL);
		update(mid + 1, b, val, RR);
	}
	pushup(rt); //计算该区间被覆盖的总长度  
}

int main()
{
	int Case = 0;
	int n;
	ll x1, y1, x2, y2;
	while (scanf("%d", &n) != EOF && n)
	{
		nums = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
			ss[nums].l = x1;
			ss[nums].r = x2;
			ss[nums].h = y1;
			ss[nums].f = 1;
			//记录下边界的信息  
			ss[nums + 1].l = x1;
			ss[nums + 1].r = x2;
			ss[nums + 1].h = y2;
			ss[nums + 1].f = -1;
			//记录上边界的信息  
			pos[nums] = x1;
			pos[nums + 1] = x2;
			//记录横坐标  
			nums += 2;
		}
		sort(ss, ss + nums, cmp); //横线 按纵坐标(高度)升序排序  
		sort(pos, pos + nums); //横坐标 升序排序,离散化  
							   //        for(int i = 0; i < nums; i++)  
							   //            printf("%.2lf %.2lf  %.2lf\n",ss[i].l,ss[i].r,ss[i].h);  
		int m = 1;
		for (int i = 1; i < nums; i++)
			if (pos[i] != pos[i - 1]) //去重,为了离散化  
				pos[m++] = pos[i];

		build(0, m - 1, 1);  //离散化后的区间就是[0,m-1]，以此建树  
		ll ans = 0;
		for (int i = 0; i < nums; i++) //拿出每条横线并且更新  
		{
			int l = binary(ss[i].l, 0, m - 1);
			int r = binary(ss[i].r, 0, m - 1) - 1;
			update(l, r, ss[i].f, 1); //用这条线段去更新//每插入一次就算一次 ，相对应的边在线段树中会抵消  
			ans += (ss[i + 1].h - ss[i].h)*tt[1].len;//高 X 低  
													 //printf("%.2lf\n",ans);  
		}
		//printf("Test case #%d\n", ++Case);
		printf("%lld\n", ans);
	}
	printf("*\n");
	return 0;
}