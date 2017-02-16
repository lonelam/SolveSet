#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000;
const int maxb = 1000;
int cnt[maxn][3];
int CNT[maxb][3];
int belong[maxn];
int lazy[maxb];
int L[maxb], R[maxb];
int bnum, bsize,n,Q;
int cmd,lef,rr;
void build()
{
    bsize = sqrt(n);
    bnum = n / bsize;
    if (n % bsize) bnum++;
    //cout << bsize <<" "<< bnum <<" "<< n << endl;
    for (int i = 0; i < bnum; i++)
    {
        L[i] = bsize * i;
        R[i] = (i + 1) * bsize;
    }
    R[bnum - 1] = n;
    for (int i = 0; i < bnum; i++)
    {
        CNT[i][0] = R[i] - L[i];
    }
    for (int i = 0; i < n; i++)
    {
        belong[i] = i / bsize;
        cnt[i][0] = 1;
    }
}
void upd(int x)
{
//    cout <<"upd" <<x<<endl;
    int tmp = cnt[x][0];
    cnt[x][0] = cnt[x][2];
    cnt[x][2] = cnt[x][1];
    cnt[x][1] = tmp;
}
void UPD(int X)
{
    int tmp = CNT[X][0];
    CNT[X][0] = CNT[X][2];
    CNT[X][2] = CNT[X][1];
    CNT[X][1] = tmp;
}
void pushdown(int blk)
{
    //cout <<blk<<endl;
    while(lazy[blk])
    {
        lazy[blk]--;
    //    cout << lazy[blk]<<endl;
        for (int i = L[blk]; i < R[blk]; i++)
        {
        //    cout <<"d";
            upd(i);
        }
    }
}
void pushup(int blk)
{
    CNT[blk][0] = CNT[blk][1] = CNT[blk][2] = 0;
    for (int i = L[blk]; i < R[blk]; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            CNT[blk][k] += cnt[i][k];
        }
    }
}
void add(int lb, int rb)
{
    //cout <<"debug";
    if (belong[lb] == belong[rb-1])
    {
        pushdown(belong[lb]);
        for (int i = lb; i < rb; i++)
        {
            upd(i);
        //    cout << "debug";
        }
        pushup(belong[lb]);
        return;
    }
    pushdown(belong[lb]);
    for (int i = lb; i < R[belong[lb]]; i++)
    {
        upd(i);
    //    cout <<"deg";
    }
    pushup(belong[lb]);
    for (int i = belong[lb] + 1; i < belong[rb-1]; i++)
    {
        UPD(i);
        lazy[i] = (lazy[i] + 1) % 3;
    }
    pushdown(belong[rb-1]);
    for (int i = belong[rb-1]; i < rb; i++)
    {
        upd(i);
    //    cout <<"ewg";
    }
    pushup(belong[rb-1]);
}


int query(int lb,int rb)
{
//    cout << lb <<" "<< rb;
//    cout <<"debug";
    int sum = 0;
    if (belong[lb] == belong[rb-1])
    {
        pushdown(belong[lb]);
        for (int i = lb; i < rb; i++)
        {
            sum += cnt[i][0];
        }
        //pushup(belong[lb]);
        return sum;
    }
    //cout << "debewfug";
    pushdown(belong[lb]);
    for (int i = lb; i < R[belong[lb]]; i++)
    {
        sum += cnt[i][0];
    }
    pushup(belong[lb]);
//    cout << "dbg";
    for (int i = belong[lb] + 1; i < belong[rb-1]; i++)
    {
        sum += CNT[i][0];
        //lazy[i] = (lazy[i] + 1) % 3;
    }
    pushdown(belong[rb-1]);
    for (int i = L[belong[rb-1]]; i < rb; i++)
    {
        sum += cnt[i][0];
    }
    //cout <<"dowig";
//    pushup(belong[rb]);
    return sum;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cin >> n >> Q;
    scanf("%d%d",&n,&Q);
    build();
    //cout <<"debug";
    while(Q--)
    {

        //int cmd,ll,rr;
        //cin >> cmd >> ll >> rr;
        //cout <<"debg\n";
        //cout << cmd << ll << rr;
        scanf("%d%d%d",&cmd,&lef,&rr);
        //cout <<"debug";
        if (cmd == 0)
        {
            add(lef-1,rr);
        }
        else if (cmd == 1)
        {
            printf("%d\n", query(lef-1,rr));
    //       cout <<"debug";
            //cout << query(ll-1,rr) << endl;
        }
    }
}
