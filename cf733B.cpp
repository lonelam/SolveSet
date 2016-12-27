/*************************************************************************
	> File Name: cf733B.cpp
	> Author: Lonelam
	> Mail: laizenan@gmail.com
	> Created Time: 2016年12月27日 星期二 03时26分53秒
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
int a[100000], b[100000];
int diff[100000];
int main()
{
    int n;
    while(cin >> n)
    {
        int beaut = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            beaut += a[i] - b[i];
            diff[i] = 2 * a[i] - 2 * b[i];
        }
        int bm = abs(beaut);
        int ans = -1;
        for (int i = 0; i < n ; i++)
        {
            if (abs(beaut - diff[i]) > bm)
            {
                bm = abs(beaut - diff[i]);
                ans = i;
            }
        }
        cout << ans + 1 << endl;
    }
}
