
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
