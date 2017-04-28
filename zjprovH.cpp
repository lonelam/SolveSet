#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int par[maxn];
int seq1[maxn];
int seq2[maxn];
int pos1[maxn];
int pos2[maxn];
int chcnt[maxn];
int gener(int L1, int R1, int L2, int R2, int p)
{
    if (L1 == R1)
    {
        return 0;
    }
    if (L2 == R2)
    {
        cout <<"debug"<< endl;
        return 0;
    }
    if (seq1[L1] == seq2[L2])
    {
        par[seq1[L1]] = p;
        chcnt[p] += 1;
        int ret = 1 + gener(L1 + 1, R1, L2 + 1, R2, seq1[L1]);
        if (p && ret < R1 - L1)
        {
            p = seq1[L1];
            while(p && chcnt[p] == 2) p = par[p];
            ret += gener(L1 + ret, R1, L2 + ret, R2, p);
        }
        return ret;
    }
    else
    {

        //par[seq1[L1]] = par[seq2[L2]] = p;
        //chcnt[p] += 1;
        //cnt1 += 2;
        int ret = gener(L1, pos1[seq2[L2]], pos2[seq1[L1]], pos2[seq1[L1]] + pos1[seq2[L2]] - L1, p);
        ret += gener(pos1[seq2[L2]], pos1[seq2[L2]] + pos2[seq1[L1]] - L2, L2, pos2[seq1[L1]], p);
        return ret;
    }
}
int main()
{
    int T;
    int n;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            scanf("%d", &n);
            memset(chcnt, 0, sizeof(chcnt));
            for (int i = 0; i < n; i++)
            {
                scanf("%d", seq1 + i);
                pos1[seq1[i]] = i;
            }
            for (int i = 0; i < n; i++)
            {
                scanf("%d", seq2 + i);
                pos2[seq2[i]] = i;
            }
            gener(0, n, 0, n, 0);
            for (int i = 1; i < n; i++)
            {
                printf("%d ", par[i]);
            }
            printf("%d\n", par[n]);
        }
    }
}


/*

100
11
1 2 4 8 5 3 6 10 9 11 7
1 2 5 4 8 3 6 10 9 11 7


*/
