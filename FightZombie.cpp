#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

ll xcoodi[100];
ll ycoodi[100];
struct point
{
    ll x,y;
} ps[100];
bool xcmp(const point lhs, const point rhs)
{
    return lhs.x < rhs.x;
}



int main()
{
    freopen("fz.in","r", stdin);
    freopen("fz.out","w", stdout);
    //system("read -rsp $'Press any key to continue...\n' -n 1 key");
    int T;
    cin >> T;
    int kase = 1;
    while(T--)
    {
        ll n, r;
        cin >> n >> r;
        for (int i = 0; i < n; i++)
        {
            cin >> ps[i].x >> ps[i].y;
            xcoodi[i] = ps[i].x;
            ycoodi[i] = ps[i].y;
        }
        sort(ps, ps + n, xcmp);
        sort(xcoodi, xcoodi + n);
        sort(ycoodi, ycoodi + n);
        int ans = 0;
        for (int mid = 0; mid < n; mid++)
        {
//            system("read -rsp $'Press any key to continue...\n' -n 1 key");
            for (int i = 0; i < n; i++)
            {
                ll bup = xcoodi[i] - r, bdown = xcoodi[i];
                if (bdown > xcoodi[mid]) continue;
                for (int j = 0; j < n; j++)
                {
                    ll bleft = ycoodi[j], bright = ycoodi[j] + r;
                    int cnt= 0;
                    for (int k = 0; k < n; k++)
                    {
                        if (ps[k].x >= bup &&ps[k].x <= bdown && ps[k].y >= bleft && ps[k].y <= bright)
                        {
                             cnt++;
                        }
                    }
                    for (int ii = 0; ii < n; ii++)
                    {
                        ll rbup = xcoodi[ii], rbdown = xcoodi[ii] + r;
                        if (rbup <= xcoodi[mid]) continue;
                        for (int jj = 0; jj < n; jj++)
                        {
                            ll rbleft = ycoodi[jj], rbright = ycoodi[jj] + r;
                            int cnt2= 0;
                            for (int k = 0; k < n; k++)
                            {
                                if (ps[k].x >= rbup &&ps[k].x <= rbdown && ps[k].y >= rbleft && ps[k].y <= rbright)
                                {
                                     cnt2++;
                                }
                            }
                            ans = max(cnt + cnt2, ans);
                        }
                    }
                }
            }
        }
        for (int mid = 0; mid < n; mid++)
        {
            for (int i = 0; i < n; i++)
            {
            //    ll bup = xcoodi[i], bdown = xcoodi[i] + r;
                ll bleft = ycoodi[i] - r, bright = ycoodi[i];
                if (bright > ycoodi[mid]) continue;
                for (int j = 0; j < n; j++)
                {
                    ll bup = xcoodi[j], bdown = xcoodi[j] + r;
            //        ll bleft = ycoodi[j], bright = ycoodi[j] + r;
                    int cnt= 0;
                    for (int k = 0; k < n; k++)
                    {
                        if (ps[k].x >= bup &&ps[k].x <= bdown && ps[k].y >= bleft && ps[k].y <= bright)
                        {
                             cnt++;
                        }
                    }
                    for (int ii = 0; ii < n; ii++)
                    {
                        ll rbleft = ycoodi[ii], rbright = ycoodi[ii] + r;
                        if (rbleft <= ycoodi[mid]) continue;
                        for (int jj = 0; jj < n; jj++)
                        {
                            ll rbup = xcoodi[jj], rbdown = xcoodi[jj] + r;

                            int cnt2= 0;
                            for (int k = 0; k < n; k++)
                            {
                                if (ps[k].x >= rbup &&ps[k].x <= rbdown && ps[k].y >= rbleft && ps[k].y <= rbright)
                                {
                                     cnt2++;
                                }
                            }
                            ans = max(cnt + cnt2, ans);
                        }
                    }
                }
            }
        }
        cout <<"Case #"<<kase++<<": "<< ans << endl;
    }
    cout << "done(delete this line)\n";
}
/*
1
50 3

1 5
2 3
2 1
5 1
6 3
4 4
4 5
4 1
0 0
0 2

10 0
10 2
4 2
0 0
0 2
10 0
10 2
7 3
8 5
3 6

9 2
4 5
3 2
1 8
2 8
7 6
8 5
3 6
9 2
4 5

1 8
2 8
7 6
8 5
3 6
9 2
4 5
3 2
1 8
2 8

0 2
10 0
10 2
7 3
8 5
3 6
9 2
4 5
3 2
3 2

*/
