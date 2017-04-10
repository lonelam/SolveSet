j#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;
int m[maxn * 4];
int grade[maxn];
int n;
void push_up(int cur)
{
    m[cur] = max(m[cur << 1], m[cur << 1 | 1]);
}
void init(int L = 0, int R = n, int x = 1)
{
    if (L + 1 == R)
    {
        m[x] = grade[L];
        return;
    }
    const int mid = L + (R - L) / 2;
    init(L, mid, x << 1);
    init(mid, R, x << 1 | 1);
    push_up(x);
}

void upd(int tar, int L = 0, int R = n, int x = 1)
{
    if (L + 1 == R)
    {
        if (tar == L){
            m[x] = grade[tar];
        //    cout <<"upd: "<< grade[tar] << endl;
        }
        return;
    }
    const int mid = L + (R - L )/ 2;
    if (tar < mid)
    {
        upd(tar, L, mid, x << 1);
    }
    else
    {
        upd(tar, mid, R, x << 1 | 1);
    }
    push_up(x);
}
int query(int ql, int qr, int L = 0, int R = n, int x = 1)
{
    if (qr < L || ql > R)
    {
        return 0;
    }
    if (ql >= L && qr <= R)
    {
        cout <<ql <<" "<< qr << endl;
        return m[x];
    }
    const int mid = L + (R - L) / 2;
    int ret = 0;
    if (ql < mid)
    {
        ret = max(ret, query(ql, qr, L, mid, x << 1));
    }
    if (qr > mid)
    {
        ret = max(ret, query(ql, qr, mid, R, x << 1 | 1));
    }
    return ret;
}


int main()
{
    int m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> grade[i];
        }
        init();
        string cmd;
        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> cmd >> a >> b;
            if (cmd == "Q")
            {
                cout << query(a - 1, b) << endl;
            }
            else if (cmd == "U")
            {
                grade[a - 1]= b;
                upd(a - 1);
            }
        }
    }
}
