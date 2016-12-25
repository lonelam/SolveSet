/*************************************************************************
	> File Name: cf752D.cpp
	> Author: Lonelam
	> Mail: laizenan@gmail.com
	> Created Time: 2016年12月26日 星期一 02时42分48秒
 ************************************************************************/

#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include <iostream>
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
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int main()
{
    string line;
    map<string, priority_queue<int> > mp;
    set<string> sset;
    int n, k;
    cin >> n >> k;
    int val;
    ll ans = 0;
    priority_queue <int> palinset;
    for (int i = 0; i < n; i++)
    {
        cin >> line >> val;
        mp[line].push(val);
        sset.insert(line);
    }
    for (string xx : sset)
    {
        string rev (xx.rbegin(), xx.rend());
        priority_queue<int> & Q = mp[xx];
        if (rev == xx)
        {
            while(Q.size() > 1)
            {
                int aa = Q.top();
                Q.pop();
                if (aa + Q.top() > 0)
                {
                    ans += aa + Q.top();
                    if(Q.top() < 0)
                    {
                        palinset.push(-Q.top());
                    }
                    Q.pop();
                }
                else
                {
                    Q.push(aa);
                    break;
                }
            }
            if (!Q.empty() && Q.top() > 0)
            {
                palinset.push(Q.top());
            }
            continue;
        }
        while(!Q.empty() && !mp[rev].empty())
        {
            if (mp[rev].top() + Q.top() > 0)
            {
                ans += mp[rev].top() + Q.top();
                mp[rev].pop();
                Q.pop();
            }
            else
                break;
        }
    }
    if (!palinset.empty() && palinset.top() > 0)
    {
        ans += palinset.top();
    }
    cout << ans << endl;
}
