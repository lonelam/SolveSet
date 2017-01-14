#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 1000;
#define rep(i, n) for (int i = 0; i < n; i++)

int sa[maxn], cntA[maxn], ch[maxn], up;
int rnk[maxn], cntB[maxn], tsa[maxn], height[maxn];
int A[maxn], B[maxn];
int n;
void solve()
{
    for (int i = 0; i < up; i++) cntA[i] = 0;
    for (int i = 1; i <= n; i++) cntA[ch[i]] ++;
    for (int i = 1; i < up; i++) cntA[i] += cntA[i - 1];
    for (int i = n; i; i--) sa[cntA[ch[i]]--] = i;
    rnk[sa[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        rnk[sa[i]] = rnk[sa[i - 1]];
        if (ch[sa[i]] != ch[sa[i - 1]]) rnk[sa[i]]++;
    }
    for (int l = 1; rnk[sa[n]] < n; l<<= 1)
    {
        for (int i = 0; i <= n; i++) cntA[i] = 0;
        for (int i = 0; i <= n; i++) cntB[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cntA[A[i] = rnk[i]]++;
            cntB[B[i] = (i + l<= n) ?rnk[i + l] : 0] ++;
        }
        for (int i = 1; i <= n; i++) cntB[i] += cntB[i - 1];
        for (int i = n; i; i--) tsa[cntB[B[i]]--] = i;
        for (int i = 1;  i<= n; i++) cntA[i] += cntA[i - 1];
        for (int i = n ; i; i--) sa[cntA[A[tsa[i]]]--] = tsa[i];
        rnk[sa[1]] = 1;
        for (int i = 2; i <= n; i++)
        {
            rnk[sa[i]] = rnk[sa[i - 1]];
            if (A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) rnk[sa[i]]++;
        }
    }
    for (int i = 1, j = 0; i <= n; i++)
    {
        if (j) j--;
        while(ch[i + j] == ch[sa[rnk[i] - 1] + j]) j++;
        height[rnk[i]] = j;
    }
}

int main()
{
//    int n;
    while(cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> ch[i];
        up = 1001;
    //    w[n] = 0;
        solve();
        int L = 0, R = n / 2 + 1;
    //    for (int i = 1; i <= n; i++) cout << height[i] <<" ";
//        for (int i = 1; i <= n; i++) cout << sa[i] <<" ";
        while(L + 1 < R)
        {
            const int M = (L + R) / 2;
            int ll = 2, rr = 2;
        //    multiset<int> Q;
            int mx = sa[1];
            int mn = sa[1];
            multiset<int> NoSet;
            bool ok = false;
            while(ll <= n)
            {
                while(height[rr] >= M)
                {
                    mx = max(mx, sa[rr]);
                    mn = min(mn, sa[rr]);
                    rr++;
                }
                if (mx -mn>= M)
                {
                    ok = true;break;
                }
                while(rr <= n && height[rr] < M )
                {
                    rr++;
                }
                ll = rr;
                mn = mx = sa[ll - 1];
            }
            if (ok)
            {
                L = M;
            }
            else
            {
                R = M;
            }
        }
        cout << L << endl;
    }
}
