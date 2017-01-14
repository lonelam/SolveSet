#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;

int sa[maxn], cntA[maxn], ch[maxn];
int rnk[maxn], cntB[maxn], tsa[maxn], height[maxn];
int A[maxn], B[maxn];
int n;
void solve()
{
    for (int i = 0; i < 256; i++) cntA[i] = 0;
    for (int i = 1; i <= n; i++) cntA[ch[i]] ++;
    for (int i = 1; i < 256; i++) cntA[i] += cntA[i - 1];
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
    int N, K;
    while(cin >> n >> K)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> ch[i];
        }
        solve();
        multiset<int> Q;
        for (int i = 1; i < K; i++)
        {
            Q.insert(height[i]);
        }
        int ans = *Q.begin();
        for (int i = K ; i <= n; i++)
        {
            Q.erase(Q.find(height[i - K + 1]));
            Q.insert(height[i]);
            ans = max(ans, *Q.begin());
        }
        cout << ans << endl;
    }
}
/*

8 3
1
2
3
2
3
2
3
1

*/
