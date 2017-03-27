#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 +  100;

char n[maxn];
int len;
void ers(int x)
{
    //cout << x << endl;
    if (x == 0)
    {
        int delto = 0;
        for (int i = 1; i < len; i++)
        {
            if (n[i] != '0')
            {
                delto = i;
            //    cout << i << endl;

                break;
            }
        //    cout << n[i] << endl;
        }
    //    cout << delto<<endl;
        if (delto)
        strcpy(n, n + delto);
        else strcpy(n,n + len - 1);
        len = strlen(n);
    }
    else
    {
        strcpy(n + x,n + x + 1);
        len = strlen(n);
    }
}
int main()
{
    cin >> n;
    len = strlen(n);
    int sig = 0;
    int cnt[3] = {0,0,0};
    for (int i = 0; i < len; i++)
    {
        sig = (sig + n[i] - '0') % 3;
        cnt[(n[i]-'0')%3]++;
    }
    //cout << sig << endl;
    if (sig == 0) cout << n;
    else if (sig == 1)
    {
        if(cnt[1]
        && len > 1)
        for (int i = len - 1; i >= 0; i--)
        {
            if ((n[i] - '0')%3 == 1)
            {ers(i);
            cout << n;
            return 0;
        }
        }
        else if (cnt[2] >= 2 && len > 2)
        {
            for (int k = 0; k < 2; k++)
            for (int i = len - 1; i >=0; i--)
            {
                if ((n[i] - '0')%3 == 2)
                {
                    ers(i);
                    break;
                }
            }
            for (int i = len - 1; i >=0; i--)
            {
                if ((n[i] - '0')%3 == 2)
                {
                    ers(i);
                    break;
                }
            }
            cout << n;
            return 0;
        }
        else
        {
            cout << -1<< endl;
            return 0;
        }
    }
    else if (sig == 2)
    {
        if(cnt[2] && len > 1)
        for (int i = len - 1; i >= 0; i--)
        {
            if ((n[i] - '0')%3 == 2)
            {ers(i);
            cout << n;
            return 0;}
        }
        else if (cnt[1] >= 2 && len > 2)
        {
            for (int k = 0; k < 2; k++)
            for (int i = len - 1; i >=0; i--)
            {
                if ((n[i] - '0')%3 == 1)
                {
                    ers(i);
                    break;
                }
            }
            for (int i = len - 1; i >=0; i--)
            {
                if ((n[i] - '0')%3 == 1)
                {
                    ers(i);
                    break;
                }
            }
            cout << n;
            return 0;
        }
        else
        {
            cout << -1<< endl;
            return 0;
        }
    }
}
