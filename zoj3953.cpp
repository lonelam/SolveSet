#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 100;

struct seg
{
    int l, r;
    int id;
    bool operator<(const seg & rhs) const
    {
        return l < rhs.l;
    }
//    bool cmp(seg & lhs, seg & rhs) const

} ss[maxn];

struct cmp
{
    bool operator()(const seg & lhs, const seg & rhs)
    {
        return lhs.r < rhs.r;
    }
};
int disc[maxn * 2];
int cnt[maxn * 4];
int dn, n;
void pushdown(int x)
{
    cnt[x << 1] += cnt[x];
    cnt[x << 1 | 1] += cnt[x];
    cnt[x] = 0;
}

void add(int ql, int qr, int a, int L = 0, int R = dn, int x = 1)
{
    //cout << x <<endl;
    if (ql >= R || L >= qr)
    {
        return;
    }
    if (ql <= L && R <= qr)
    {
        cnt[x] += a;
        return;
    }
    const int mid = L + (R - L) / 2;
    pushdown(x);
    if (ql < mid) add(ql, qr, a, L, mid, x << 1);
    if (mid < qr) add(ql, qr, a, mid, R, x << 1 | 1);
}

int query(int q, int L = 0, int R = dn, int x = 1)
{
    if (L + 1 == R)
    {
        return cnt[x];
    }
    //cout << x <<endl;
    pushdown(x);
    const int mid = L + (R - L) / 2;
    if (q < mid) return query(q, L, mid, x << 1);
    else return query(q, mid, R, x << 1 | 1);
}

int main()
{
    int T;
    while(cin >> T)
    {
        while(T--)
        {

        //    memset(bit, 0, sizeof(bit));
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cin >> ss[i].l >> ss[i].r;
                ss[i].id = i + 1;
                disc[i] = ss[i].l;
                disc[i + n] = ss[i].r;
            }
            //cout << "debug" << endl;
            sort(ss, ss + n);
            sort(disc, disc+ 2 * n);
            int sp = 0;
            priority_queue<seg, vector<seg>, cmp> Q;
            vector<int> ans;
            dn = unique(disc, disc + 2 * n) - disc;
            for (int i = 0; i < n; i++)
            {
                //
                ss[i].l = lower_bound(disc, disc + dn, ss[i].l) - disc;
                ss[i].r = lower_bound(disc, disc + dn, ss[i].r) - disc;
            }
            //cout << "debug";
            for (int i = 0; i < dn; i++)
            {
                //cout << "debug"<< endl;
                while(sp < n && ss[sp].l <= i)
                {
                    //cout <<"debug" << endl;
                    Q.push(ss[sp]);
                    add(ss[sp].l, ss[sp].r + 1, 1);
                //    cout <<"**" << disc[ss[sp].l] << " "<< disc[ss[sp].r] <<endl;
                    //cout << query(ss[sp].l) << endl;
                    sp++;
                //    cout << "debug";
                }
                while(query(i) > 1)
                {

                    const seg & tmp = Q.top();
                //    cout << "--" << i <<" "<<query(i) << " "<< disc[tmp.l] <<" "<< disc[tmp.r] << endl;
                    ans.push_back(tmp.id);
                    add(tmp.l, tmp.r + 1, -1);
                    Q.pop();
                    //cout <<"debug" << endl;
                }
            //    cout <<"debug"<<endl;
            }
            cout << ans.size() << endl;
            if (ans.size()) cout << ans[0] ;
            for (int i = 1; i < ans.size(); i++)
            {
                cout << " "<< ans[i];
            }
            cout << endl;

        }
    }
}
