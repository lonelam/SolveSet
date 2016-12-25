/*************************************************************************
	> File Name: cf733A.cpp
	> Author: Lonelam
	> Mail: laizenan@gmail.com
	> Created Time: 2016年12月26日 星期一 01时38分01秒
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
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#include<iostream>
const int inf = 0x3f3f3f3f;
set<char> vow = {'A', 'E','I','O','U'
               ,'Y'};
int main()
{
    string line;
    cin >> line;
    int ans = 1;
    int pre = -1;
    for (int i = 0; i < line.size(); i++)
    {
        if (vow.find(line[i])!=vow.end())
        {
            ans = max(ans, i - pre);
            pre = i;
        }
    }
    ans = max(ans, (int)line.size() - pre);
    cout << ans << endl;
}
