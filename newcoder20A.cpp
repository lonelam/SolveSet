
#include <bits/stdc++.h>
using namespace std;


const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}
template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}


const int N = 1e5 + 7;
int n;
typedef long double ld;

double p[N];
double postdp[N];

int a[N];
int pre_sum[N];
int main()
{
    int m;
    while(in(n))
    {
        in(m);
        for(int i = 1;i<=n;i++)
        {
            in(a[i]);
            pre_sum[i] = pre_sum[i-1] + a[i];
            //cout << pre_sum[i] << " ";
        }
        //cout << endl;
        for(int j = 0;j<m;j++)
        {
            int x;
            memset(p, 0, sizeof(p));
            in(x);
            int flag = 1;
            for(int i = 1;i<=n;i++)
            {
                if(a[i] > x)
                {
                    flag = 0;
                    break;
                }
            }
            if(!flag)
            {
                printf("YNOI is good OI!\n");
                continue;
            }
            for(int j = 0;j<=n;j++)
                p[j] = 0;
            int i;
            p[n] = 1;
            postdp[n] = 1;
            /*for(i = n ;i >= 1;i--)
            {
                if (pre_sum[n] - pre_sum[i-1] >= x) break;
                dp[i] = 1;
                add(i, 1);
            }*/
            int R = n;
            for (i = n - 1; i >= 1; i--)
            {
                while(x + pre_sum[i-1] < pre_sum[R]) R--;
                //cout << x + pre_sum[i-1] << " ";
                //const int c = upper_bound(pre_sum + i, pre_sum + n + 1, x + pre_sum[i-1]) - pre_sum - i;
                const int c = R - i + 1;
                //cout << c << endl;
                p[i] = (postdp[i + 1] - postdp[i + c + 1]) / (ld)(c) + 1;
                postdp[i] = postdp[i+1] + p[i];
               // add(i, p[i]);
            }
            //cout << endl;
            printf("%.2f\n", p[1]);
           // cout << p[1] << endl;
        }
    }
}
