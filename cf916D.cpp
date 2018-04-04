#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int N = maxn * 30;
int q;
map<string, int> Idtable;
int Idtot;
char cmd[100];
char a[100];


struct Tree {
	int l,r,size;
	int val,max;
	Tree() {}
	Tree(int _l,int _r,int s,int v,int m):l(_l),r(_r),size(s),val(v),max(m) {}
};
struct Treap { //以根作为接口
	Tree tree[maxn*100];
	int size;
#define val(x) tree[x].val
#define size(x) tree[x].size
	int newnode(int v) {
		tree[++size]=Tree(0,0,1,v,v);
		return size;
	}
	void push_up(int index) {
		int l=tree[index].l,r=tree[index].r;
		size(index)=size(l)+size(r)+1;
		tree[index].max=max(val(index),max(tree[l].max,tree[r].max));
	}
	pii split(int index,int num) {
		if(!index)return mp(0,0);
		int l=tree[index].l,r=tree[index].r;
		int now=++size;
		tree[now]=tree[index];
		if(num<=size(l)) {
			pii lt=split(l,num);
			tree[now].l=lt.second;
			push_up(now);
			return mp(lt.first,now);
		} else {
			pii rt=split(r,num-size(l)-1);
			tree[now].r=rt.first;
			push_up(now);
			return mp(now,rt.second);
		}
	}
	int merge(int a,int b) {
		if(!a||!b)return a+b;
		int now=++size;
		if(g()%(size(a)+size(b))<size(a)) {
			tree[now]=tree[a];
			tree[now].r=merge(tree[a].r,b);
		} else {
			tree[now]=tree[b];
			tree[now].l=merge(a,tree[b].l);
		}
		push_up(now);
		return now;
	}
} bbt;

int main()
{

}
