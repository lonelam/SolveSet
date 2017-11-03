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
struct segment //����������±߽�  
{
	ll l, r, h; //���Һ����꣬������  
	int f; //-1Ϊ�±߽磬1Ϊ�ϱ߽�  
} ss[2 * MAX];
struct node //�߶����ڵ�  
{
	int l, r;
	int cover; //�ýڵ㱻���ǵ����  
	double len; //�����䱻���ǵ��ܳ���  
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
	if (tt[rt].cover) //��0���Ѿ������θ���  
		tt[rt].len = pos[tt[rt].r + 1] - pos[tt[rt].l];
	else if (tt[rt].l == tt[rt].r) //�Ѿ�����һ���߶�  
		tt[rt].len = 0;
	else //��һ���߶ε�����û�����θ��ǣ���ôֻ�ܴ����Һ��ӵ���Ϣ�л�ȡ  
		tt[rt].len = tt[LL].len + tt[RR].len;
}

void update(int a, int b, int val, int rt)
{
	if (tt[rt].l == a && tt[rt].r == b) //Ŀ������  
	{
		tt[rt].cover += val; //����������䱻���ǵ����,//�����ɾ������ֱ����cover[]+=flag����cover[]>0ʱ��������һ���б߸��ǡ�  
		pushup(rt);  //����������䱻���ǵ��ܳ���  
		return;
	}
	int mid = (tt[rt].l + tt[rt].r) / 2;
	if (b <= mid) //ֻ��������  
		update(a, b, val, LL);
	else if (a > mid) //ֻ�����к���  
		update(a, b, val, RR);
	else //���Ҷ�Ҫ����  
	{
		update(a, mid, val, LL);
		update(mid + 1, b, val, RR);
	}
	pushup(rt); //��������䱻���ǵ��ܳ���  
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
			//��¼�±߽����Ϣ  
			ss[nums + 1].l = x1;
			ss[nums + 1].r = x2;
			ss[nums + 1].h = y2;
			ss[nums + 1].f = -1;
			//��¼�ϱ߽����Ϣ  
			pos[nums] = x1;
			pos[nums + 1] = x2;
			//��¼������  
			nums += 2;
		}
		sort(ss, ss + nums, cmp); //���� ��������(�߶�)��������  
		sort(pos, pos + nums); //������ ��������,��ɢ��  
							   //        for(int i = 0; i < nums; i++)  
							   //            printf("%.2lf %.2lf  %.2lf\n",ss[i].l,ss[i].r,ss[i].h);  
		int m = 1;
		for (int i = 1; i < nums; i++)
			if (pos[i] != pos[i - 1]) //ȥ��,Ϊ����ɢ��  
				pos[m++] = pos[i];

		build(0, m - 1, 1);  //��ɢ������������[0,m-1]���Դ˽���  
		ll ans = 0;
		for (int i = 0; i < nums; i++) //�ó�ÿ�����߲��Ҹ���  
		{
			int l = binary(ss[i].l, 0, m - 1);
			int r = binary(ss[i].r, 0, m - 1) - 1;
			update(l, r, ss[i].f, 1); //�������߶�ȥ����//ÿ����һ�ξ���һ�� �����Ӧ�ı����߶����л����  
			ans += (ss[i + 1].h - ss[i].h)*tt[1].len;//�� X ��  
													 //printf("%.2lf\n",ans);  
		}
		//printf("Test case #%d\n", ++Case);
		printf("%lld\n", ans);
	}
	printf("*\n");
	return 0;
}