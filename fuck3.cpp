#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
typedef pair<int, int> pii;
char bignum[maxn];
char tar[maxn];
int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    {
        while(T--)
        {
            int k;
            cin >> bignum >> k;
        //    int l = 0, r = k;
            int len = strlen(bignum);
            int c = 0;
            while( c < len && k > 0)
            {
                int pre = c;
                for (int i = c; i <= c + k && i < len; i++)
                {

                    if (bignum[i] == '$')
                    {
                        continue;
                    }
                    if (bignum[pre] > bignum[i])
                    {
            //            cout << i << endl;
                        pre = i;
                    }
                    //pre = i;
                }
                bignum
                for (int i = c; i < pre; i++)
                {
        //            cout << bignum[i] << endl;
                    bignum[i] = '$';
                }
                k -= pre - c;
                c = pre + 1;
                //tar[]
                //bignum[pre] = '$';
            }
            /*for (int i = c; i < len; i++)
            {
                bignum[i] = '$';
            }*/
            int cur = 0;
            int i = 0;
            while(bignum[i] == '0' || bignum[i] == '$') i++;
            for (; i < len; i++)
            {
                if (bignum[i] != '$')
                {
                    bignum[cur++] = bignum[i];
                }
            }

            bignum[cur] = 0;
            cout << bignum << endl;
        }
    }
}
