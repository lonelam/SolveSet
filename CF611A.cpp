/*************************************************************************
	> File Name: CF611A.cpp
	> Author: Lonelam
	> Mail: laizenan@gmail.com
	> Created Time: 2016年12月28日 星期三 18时00分17秒
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
#include<iostream>
const int inf = 0x3f3f3f3f;
int main()
{
    string x, y;
    int d;
    while(cin >> d >> x >> y)
    {
        if (y[0] == 'w')
        {
            cout << ((d == 5 || d == 6)? 53 : 52) << endl;
        }
        else
        {
            if (d == 30 )
            cout << 11 << endl;
            else if (d <= 29)
            cout << 12 << endl;
            else if (d == 31)
            {
                cout << 7 << endl;
            }
        }
    }
}
