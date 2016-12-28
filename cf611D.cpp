/*************************************************************************
	> File Name: cf611D.cpp
	> Author: Lonelam
	> Mail: laizenan@gmail.com
	> Created Time: 2016年12月28日 星期三 19时28分07秒
 ************************************************************************/

#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<sstream>
#include<utility>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll moder= 1e9+7;
const int maxn = 5000 + 10;
char tail[maxn];
char S[maxn];
ll mem[maxn][maxn];
int n;
ll dfs(int cur, int ndigit, bool new_digit)
{
   // cout <<"debug"<<endl;
   
    if(tail[0] == '0')
    {
        return 0;
    }
    if (cur == n)
    {
    //    cout << tail << endl;
        return 1;
    }
    if (cur + ndigit > n)
    {
        return 0;
    }   bool origlen = false;

    for (int i = 0; i < ndigit; i++)
    {
        if(S[cur + i] < tail[i])
        {
            break;
        }
        else if (S[cur + i] > tail[i])
        {
            origlen = true;
            break;
        }
    }
    ll ans =0; 
    if (origlen)
    {
        memcpy(tail, S + cur, sizeof(char) * (ndigit + 5));
        ans = (ans + dfs(cur + ndigit, ndigit, false)) % moder;
    }
    for (int i = ndigit + 1; i + cur <= n; i++)
    {
        ll res;
        if (mem[cur][i] != -1)
            res = mem[cur][i];
        else
        {
            memcpy(tail, S + cur, sizeof(char) * (i + 5));
            res = mem[cur][i] = dfs(cur + i, i, true);
        }
        ans = (ans + res)% moder;
    }
    return ans;
}
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        memset(mem, -1, sizeof(mem));
        scanf("%s", S);
        printf("%lld\n", dfs(0,0,false));
    }
}

