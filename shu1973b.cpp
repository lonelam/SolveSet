#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000;

int n,Q;
int cnt[maxn*2][3];
int lazy[maxn*2];

void pushup(int rt)
{
    for (int k = 0; k < 3; k++)
    {
        cnt[rt][k] = cnt[rt << 1][k] + cnt[rt << 1 | 1][k];
    }
}
void build(int l = 0, int r = n, int rt = 1)
{
    /*...*/
    //cout << rt << endl;
    if (l >= r)
    {
        return;
    }
    cnt[rt][0] = r - l ;
    const int mid = l + (r - l) / 2;
    if (l + 1 == r) return;
    //这里千万不要手贱去写什么mid + 1，左闭右开的区间里没有常数！
    build(l, mid, rt << 1);
    build(mid, r, rt << 1 | 1);
    if (l + 1 != r) pushup(rt);

    //cnt[rt][0] = r - l + 1;
}
void upd(int rt)
{
    swap(cnt[rt][0],cnt[rt][2]);
    swap(cnt[rt][2], cnt[rt][1]);
}
void pushdown(int rt)
{
//    cout << rt << endl;
    while(lazy[rt])
    {
        lazy[rt]--;
        lazy[rt << 1] = (lazy[rt << 1] + 1) % 3;
        lazy[rt<< 1|1] = (lazy[rt<<1|1] + 1) % 3;
        upd(rt << 1);
        upd(rt << 1 | 1);
    }
}
void add(int L, int R, int l = 0, int r = n, int rt = 1)
{
//    printf("ewf");
//cout << rt << endl;
    if (l >= r)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        lazy[rt] = (lazy[rt] + 1) % 3;
        upd(rt);
        return;
    }
    if (l + 1 == r)
    {
        //upd(rt);
        return;
    }
    const int mid = (l + r) / 2;
    pushdown(rt);
    if (L < mid) add(L, R, l, mid, rt << 1);
    if (mid <= R) add(L, R, mid, r, rt << 1 | 1);
    if (r - l != 1) pushup(rt);
    return;
}
int query(int L, int R, int l = 0, int r = n, int rt = 1)
{
//    cout << l << " "<<r <<" "<< rt<< endl;
    if (l >= r)
    {
        //这里务必返回，此时rt下标是没有数据的
        return 0;
    }
    if (L <= l && r <= R)
    {
        return cnt[rt][0];
    }
    //cout << "weg"<<endl;
    if (l + 1 == r) return 0;
    const int mid = l + (r - l) / 2;
    int sum = 0;
    pushdown(rt);
    //这里也是坑点啊。。注意mid所在的位置，然后根据mid在不在范围里面来确定是否相等就不容易错一点。。。
    if (L < mid) sum += query(L, R, l, mid, rt << 1);
    if (mid <= R) sum += query(L, R, mid, r, rt << 1|1);
    return sum;
}
int main()
{
    scanf("%d%d",&n,&Q);
    build();
    while(Q--)

    {
        int cmd, lb,rb;
        scanf("%d%d%d",&cmd,&lb,&rb);
        if (cmd == 0)
        {
            add(lb-1,rb);
        }
        else
        {
            printf("%d\n", query(lb-1,rb));
        }
    }
}
